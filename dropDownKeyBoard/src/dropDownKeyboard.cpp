#include <Arduino.h>

#include <lvgl.h>
#include "ui.h"

#include <TFT_eSPI.h>

#include <XPT2046_Touchscreen.h>

// ----------------------------
// Touch Screen pins
// ----------------------------

// CYD touch sử dụng một số chân SPI không mặc định
// SPI pins

#define XPT2046_IRQ  36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK  25
#define XPT2046_CS   33

TFT_eSPI tft = TFT_eSPI();

SPIClass touchscreenSpi = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
uint16_t touchScreenMinimumX = 200, touchScreenMaximumX = 3700, touchScreenMinimumY = 240, touchScreenMaximumY = 3800;

// Set độ phân giải
#define TFT_HOR_RES 240
#define TFT_VER_RES 320

// LVGL vẽ vào bộ đệm này, kích thước bằng 1/10 kích thước màn hình thường hoạt động tốt. Kích thước được tính bằng byte
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))

// In thông tin để debug
#if LV_USE_LOG != 0
void my_print(lv_log_level_t level, const char *buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush(); //Đảm bảo dữ liệu được gửi hết qua Serial ngay lập tức.
}
#endif

// LVGL gọi hàm này khi một hình ảnh đã được render cần được sao chép lên màn hình
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
  //Gọi nó để báo cho LVGL biết rằng bạn đã sẵn sàng
  lv_disp_flush_ready(disp);
}

// Đọc cảm ứng
void my_touchpad_read(lv_indev_t *indev, lv_indev_data_t *data) {
  if (touchscreen.touched()) {
    TS_Point p = touchscreen.getPoint();
    //Một số hiệu chỉnh tự động cơ bản để tránh bị lệch ngoài phạm vi
    if (p.x < touchScreenMinimumX) touchScreenMinimumX = p.x;
    if (p.x > touchScreenMaximumX) touchScreenMaximumX = p.x;
    if (p.y < touchScreenMinimumY) touchScreenMinimumY = p.y;
    if (p.y > touchScreenMaximumY) touchScreenMaximumY = p.y;
    //Map giá trị đầu vào này thành vị trí pixel trên màn hình
    data->point.x = map(p.x, touchScreenMinimumX, touchScreenMaximumX, 1, TFT_HOR_RES); //Hiệu chỉnh tọa độ X của Touchscreen 
    data->point.y = map(p.y, touchScreenMinimumY, touchScreenMaximumY, 1, TFT_VER_RES); //Hiệu chỉnh tọa độ Y của Touchscreen 
    data->state = LV_INDEV_STATE_PRESSED;
    /*
    Serial.print("Touch x ");
    Serial.print(data->point.x);
    Serial.print(" y ");
    Serial.println(data->point.y);
    */
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

lv_indev_t *indev;      //Thiết bị đầu vào của Touchscreen
uint8_t *draw_buf;      //Bộ nhớ draw_buf được cấp phát trên heap, nếu không thì vùng nhớ tĩnh sẽ quá lớn khi biên dịch trên ESP32
uint32_t lastTick = 0;  //Dùng để theo dõi tick timer

// Sự kiện xóa nội dung của TextArea và Label khi nhấn nút "Cancel"
static void keyboard_cancel_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Lấy event code
  lv_obj_t *kb = (lv_obj_t *)lv_event_get_target(e);        //Switch kích hoạt event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label hoặc UI cần cập nhật (nếu có)
  Serial.println("Clear Text Area");
  if (code == LV_EVENT_CANCEL) {
    lv_textarea_set_text(objects.ta_new_options, "");     //Đặt textarea thành chuỗi rỗng
    lv_label_set_text(objects.label_show_selection, "");  //Đặt label text thành chuỗi rỗng
  }
}

// Sự kiện chọn một tùy chọn trong dropdown menu 
static void get_selected_option_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Lấy event code
  lv_obj_t *dd = (lv_obj_t *)lv_event_get_target(e);        //Switch kích hoạt event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label hoặc UI cần cập nhật (nếu có)
  Serial.println("Dropdown Get Car Selected");
  if (code == LV_EVENT_VALUE_CHANGED) {

    char buf[24];
    lv_dropdown_get_selected_str(dd, buf, sizeof(buf)); //Lưu giá trị vào mảng buf
    LV_LOG_USER("Option: %s", buf);
    Serial.println(buf);

    lv_label_set_text_fmt(objects.label_show_selection, "Selected: %s", buf); //Cập nhật nội dung Label UI
  }
}

// Sự kiện thêm một tùy chọn mới vào dropdown menu khi bấm nút
static void button_add_new_option_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Lấy event code
  lv_obj_t *btn = (lv_obj_t *)lv_event_get_target(e);       //Button kích hoạt event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label hoặc UI cần cập nhật (nếu có)

  Serial.println("Dropdown Add New Car");
  if (code == LV_EVENT_CLICKED || code == LV_EVENT_READY) {                       //Event codes này sẽ xử lí

    //Check new option doesn't already exist before adding
    const char *new_option = lv_textarea_get_text(objects.ta_new_options);        //Lấy dữ liệu nhập từ người dùng
    String option = String(new_option);                                           
    option.trim();
    if (!option.isEmpty()) {                                                      //Kiểm tra nếu text không phải empty
      //Kiểm tra xem có tùy chọn nào tồn tại trước khi thêm
      int exists = lv_dropdown_get_option_index(objects.dd_cars, new_option);     //Kiểm tra xem tùy chọn đã tồn tại chưa
      if (exists == -1) {                                                         //Giá trị -1 nghĩa là tùy chọn chưa có trong dropdown
        int number_of_options = lv_dropdown_get_option_count(objects.dd_cars);    //Lấy giá trị số lượng tùy chọn có trong dropdown list
        lv_dropdown_add_option(objects.dd_cars, new_option, number_of_options);   //Thêm tùy chọn
        lv_label_set_text_fmt(objects.label_show_selection, "Added: %s", option); //Cập nhật label
      } else {
        lv_label_set_text(objects.label_show_selection, "Option Already Exists"); //Cập nhật là "Option already exits" nếu lựa chọn này đã tồn tại
      }
    }else{
        lv_label_set_text(objects.label_show_selection, "Nothing to add");        //Cập nhật là "Nothing to add" nếu thêm tùy chọn rỗng
    }
  }
}

void setup() {

  //Một số thông tin cơ bản trên Serial console
  String LVGL_Arduino = "LVGL demo ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(9600);
  Serial.println(LVGL_Arduino);

  //Khởi tạo Touchscreen
  touchscreenSpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); 
  touchscreen.begin(touchscreenSpi);                                        
  touchscreen.setRotation(2);                                               

  //Khởi tạo LVGL GUI
  lv_init();

  draw_buf = new uint8_t[DRAW_BUF_SIZE];
  lv_display_t *disp;
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, DRAW_BUF_SIZE);//Tạo màn hình TFT
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);

  //Khởi tạo driver thiết bị đầu vào XPT2046 
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  //Hoàn thành Setup LVGL
  Serial.println("LVGL Setup done");

  //Tích hợp EEZ Studio GUI
  ui_init();


  //Đăng kí LVGL event handlers 
  lv_obj_add_event_cb(objects.dd_cars, get_selected_option_event_handler, LV_EVENT_VALUE_CHANGED, objects.label_show_selection);
  
  //Tái sử dụng cùng một event handler cho cả nút bấm và bàn phím
  lv_obj_add_event_cb(objects.btn_add_option, button_add_new_option_event_handler, LV_EVENT_CLICKED, objects.label_show_selection);
  lv_obj_add_event_cb(objects.kb_input, button_add_new_option_event_handler, LV_EVENT_READY, objects.label_show_selection);

  lv_obj_add_event_cb(objects.kb_input, keyboard_cancel_event_handler, LV_EVENT_CANCEL, objects.label_show_selection);

  tft.invertDisplay(true);
}


//Yêu cầu LVGL 9.1
void loop() {
  lv_tick_inc(millis() - lastTick);  //Update tick timer
  lastTick = millis();
  lv_timer_handler();  //Update UI
  delay(5);
}