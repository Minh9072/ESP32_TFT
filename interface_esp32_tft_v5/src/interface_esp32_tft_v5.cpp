#include <Arduino.h>

#include <WiFi.h>
#include <WiFiUdp.h>
#include <HTTPClient.h>

#include <ArduinoJson.h>

#include <lvgl.h>
#include "ui.h"
#include "images.h"

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

static const uint16_t screenWidth = 320;
static const uint16_t screenHeight = 240;
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight);

SPIClass touchscreenSpi = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
uint16_t touchScreenMinimumX = 200, touchScreenMaximumX = 3700, touchScreenMinimumY = 240, touchScreenMaximumY = 3800;

// Độ phân giải
#define TFT_HOR_RES 320
#define TFT_VER_RES 240

// LVGL vẽ vào bộ đệm này, kích thước bằng 1/10 kích thước màn hình thường. Kích thước được tính bằng byte
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
  lv_disp_flush_ready(disp);
}



lv_indev_t *indev;      //Thiết bị đầu vào của Touchscreen
uint8_t *draw_buf;      //Bộ nhớ draw_buf được cấp phát trên heap, nếu không thì vùng nhớ tĩnh sẽ quá lớn khi biên dịch trên ESP32
uint32_t lastTick = 0;  //Dùng để theo dõi tick timer


const char* ssid = "Bao Tu Trong Trung_2.4G";
const char* password = "@2022.com";
//OpenWeatherMap API.
String openWeatherMapApiKey = "0c03dbf427110d6965566014b8ea57f1";
//Tìm kiếm tại: https://openweathermap.org/
String cityName = "Ho Chi Minh city";
String cityCode = "1566083";

int cnt = 0;

String str_Weather_Main, str_Weather_Icon, str_Weather_Description;
String str_Temperature, str_Feels_Like, str_Temp_Max, str_Temp_Min;
String str_Humidity, str_Wind_Speed, str_Pressure, str_Visibility;

char ca_Info_Status[100];

String jsonBuffer;



//---------------------------------------------------------Kết nối wifi---------------------------------------------------------//
void connecting_To_WiFi() {

  //Đặt Wifi ở chế độ STA
  Serial.println();
  Serial.println("-------------WIFI mode");
  Serial.println("WIFI mode : STA");
  WiFi.mode(WIFI_STA);
  Serial.println("-------------");
  delay(1000);
  
  Serial.println();
  Serial.println("-------------Connection");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  int connecting_process_timed_out = 20; //--> 20 = 20 seconds.
  connecting_process_timed_out = connecting_process_timed_out * 2;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    if(connecting_process_timed_out > 0) connecting_process_timed_out--;
    if(connecting_process_timed_out == 0) {
      Serial.println();
      Serial.println("Failed to connect to WiFi.");
      Serial.println("-------------");
      break;

    }
  }

  Serial.println();
  Serial.println("WiFi connected.");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.println("-------------");
  delay(1000);

}
//-------------------------------------------------------------------------------------------------------------------------------//




//------------------------------------------------------------httpGETRequest()--------------------------------------------------//
String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path.
  http.begin(client, serverName);
  
  // Send HTTP POST request.
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  
  // Free resources.
  http.end();

  return payload;
}
//-------------------------------------------------------------------------------------------------------------------------------//



// ------------------------------------------------------Đọc cảm ứng-------------------------------------------------------------//
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
//-------------------------------------------------------------------------------------------------------------------------------//



//------------------------------------------------------- Update UI--------------------------------------------------------------//
void update_UI() {
  lv_tick_inc(millis() - lastTick); //--> Update the tick timer. Tick is new for LVGL 9.
  lastTick = millis();
  lv_timer_handler(); //--> Update the UI.
  delay(5);
}
//-------------------------------------------------------------------------------------------------------------------------------//



//------------------------------------------------Xử lý sự kiện trên note screen-------------------------------------------------//
// Sự kiện xóa nội dung của TextArea và Label khi nhấn nút "Cancel"
static void keyboard_cancel_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Lấy event code
  lv_obj_t *kb = (lv_obj_t *)lv_event_get_target(e);        //Switch kích hoạt event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label hoặc UI cần cập nhật (nếu có)
  Serial.println("Clear Text Area");
  if (code == LV_EVENT_CANCEL) {
    lv_textarea_set_text(objects.text_note, "");     //Đặt textarea thành chuỗi rỗng
  }
}

// Sự kiện chọn một tùy chọn trong dropdown menu 
static void get_selected_option_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Lấy event code
  lv_obj_t *dd = (lv_obj_t *)lv_event_get_target(e);        //Switch kích hoạt event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label hoặc UI cần cập nhật (nếu có)
  Serial.println("Dropdown Selected");
  if (code == LV_EVENT_VALUE_CHANGED) {

    char buf[24];
    lv_dropdown_get_selected_str(dd, buf, sizeof(buf)); //Lưu giá trị vào mảng buf
    LV_LOG_USER("Option: %s", buf);
    Serial.println(buf);

    lv_textarea_set_text(objects.text_note, buf);
    //lv_label_set_text_fmt(objects.label_show_selection, "Selected: %s", buf); //Cập nhật nội dung Label UI
  }
}

// Sự kiện thêm một tùy chọn mới vào dropdown menu khi bấm nút
static void button_add_new_option_event_handler(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Lấy event code
  lv_obj_t *btn = (lv_obj_t *)lv_event_get_target(e);       //Button kích hoạt event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label hoặc UI cần cập nhật (nếu có)

  Serial.println("Dropdown Add New Note");
  if (code == LV_EVENT_CLICKED || code == LV_EVENT_READY) {                       //Event codes này sẽ xử lí

    //Check new option doesn't already exist before adding
    const char *new_option = lv_textarea_get_text(objects.text_note);        //Lấy dữ liệu nhập từ người dùng
    String option = String(new_option);                                           
    option.trim();
    if (!option.isEmpty()) {                                                      //Kiểm tra nếu text không phải empty
      //Kiểm tra xem có tùy chọn nào tồn tại trước khi thêm
      int exists = lv_dropdown_get_option_index(objects.dd_note, new_option);     //Kiểm tra xem tùy chọn đã tồn tại chưa
      if (exists == -1) {                                                         //Giá trị -1 nghĩa là tùy chọn chưa có trong dropdown
        int number_of_options = lv_dropdown_get_option_count(objects.dd_note);    //Lấy giá trị số lượng tùy chọn có trong dropdown list
        lv_dropdown_add_option(objects.dd_note, new_option, number_of_options);   //Thêm tùy chọn
        //lv_label_set_text_fmt(objects.label_show_selection, "Added: %s", option); //Cập nhật label
      } else {
        //lv_label_set_text(objects.label_show_selection, "Option Already Exists"); //Cập nhật là "Option already exits" nếu lựa chọn này đã tồn tại
      }
    }else{
        //lv_label_set_text(objects.label_show_selection, "Nothing to add");        //Cập nhật là "Nothing to add" nếu thêm tùy chọn rỗng
    }
  }
}
//-------------------------------------------------------------------------------------------------------------------------------//




//-------------------------------------------Xử lý sự kiện weather screen--------------------------------------------------------//
//Lấy dữ liệu từ OpenWeatherMap
//Đoạn này dùng với thư viện <Aruino_JSON.h>
/*void get_Data_from_OpenWeatherMap() {  
  Serial.println();
  Serial.println("-------------");
  Serial.println("Update weather data (Getting Weather Data from OpenWeatherMap).");
  Serial.println("Please wait...");
  delay(500);
  
  if(WiFi.status()== WL_CONNECTED){
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?id=" + countryCode + "&appid=" + openWeatherMapApiKey;
    
    jsonBuffer = httpGETRequest(serverPath.c_str());
    Serial.println();
    Serial.println("Weather Data in JSON form :");
    Serial.println(jsonBuffer);
    JSONVar myObject = JSON.parse(jsonBuffer);

    // JSON.typeof(jsonVar) can be used to get the type of the var.
    if (JSON.typeof_(myObject) == "undefined") {
      strcpy(ca_Info_Status, "(Failed : Parsing input failed !)");
      
      Serial.println("Parsing input failed !");

      return;
    }

    Serial.println();
    Serial.println("Weather Data taken");

    str_Weather_Main = JSON.stringify(myObject["weather"][0]["main"]);
    str_Weather_Main.replace("\"", ""); //--> Removes the Double quotes (") character in the string.
    str_Weather_Icon = JSON.stringify(myObject["weather"][0]["icon"]);
    str_Weather_Icon.replace("\"", "");
    str_Weather_Description = JSON.stringify(myObject["weather"][0]["description"]);
    str_Weather_Description.replace("\"", "");
    
    str_Temperature = JSON.stringify(myObject["main"]["temp"]);
    str_Feels_Like = JSON.stringify(myObject["main"]["feels_like"]);
    str_Temp_Max = JSON.stringify(myObject["main"]["temp_max"]);
    str_Temp_Min = JSON.stringify(myObject["main"]["temp_min"]);
    
    str_Humidity = JSON.stringify(myObject["main"]["humidity"]);
    str_Wind_Speed = JSON.stringify(myObject["wind"]["speed"]);
    str_Pressure = JSON.stringify(myObject["main"]["pressure"]);
    str_Visibility = JSON.stringify(myObject["visibility"]);

    Serial.println();
    Serial.print("Weather Main : ");Serial.println(str_Weather_Main);
    Serial.print("Weather Icon : ");Serial.println(str_Weather_Icon);
    Serial.print("Weather Description : ");Serial.println(str_Weather_Description);
    
    Serial.print("Temperature : ");Serial.print(str_Temperature);Serial.println(" °C");
    Serial.print("Feels Like : ");Serial.print(str_Feels_Like);Serial.println(" °C");
    Serial.print("Temp Max : ");Serial.print(str_Temp_Max);Serial.println(" °C");
    Serial.print("Temp Min : ");Serial.print(str_Temp_Min);Serial.println(" °C");
    
    Serial.print("Humidity : ");Serial.print(str_Humidity);Serial.println(" %");
    Serial.print("Wind Speed : ");Serial.print(str_Wind_Speed);Serial.println(" m/s");
    Serial.print("Pressure : ");Serial.print(str_Pressure);Serial.println(" hPa");
    Serial.print("Visibility : ");Serial.print(str_Visibility);Serial.println(" m");

    Serial.println("-------------");
    Serial.println();

    strcpy(ca_Info_Status, "(Succeed)");
    delay(1000);
  }
  else {
    strcpy(ca_Info_Status, "(Failed : WiFi Disconnected !)");
    
    Serial.println("WiFi Disconnected");
    Serial.println("-------------");
    Serial.println();
  }
}*/
void get_Data_from_OpenWeatherMap() {  
  Serial.println();
  Serial.println("-------------");
  Serial.println("Update weather data (Getting Weather Data from OpenWeatherMap).");
  Serial.println("Please wait...");
  delay(500);
  
  if(WiFi.status()== WL_CONNECTED){
    String serverPath = "http://api.openweathermap.org/data/2.5/weather?id=" + cityCode + "&appid=" + openWeatherMapApiKey;
    
    jsonBuffer = httpGETRequest(serverPath.c_str());
    Serial.println();
    Serial.println("Weather Data in JSON form :");
    Serial.println(jsonBuffer);
    
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, jsonBuffer);
    
    if (error) {
      strcpy(ca_Info_Status, "(Failed : Parsing input failed !)");
      Serial.println("Parsing input failed !");
      return;
    }
    
    Serial.println();
    Serial.println("Weather Data taken");
    
    str_Weather_Main = doc["weather"][0]["main"].as<String>();
    str_Weather_Icon = doc["weather"][0]["icon"].as<String>();
    str_Weather_Description = doc["weather"][0]["description"].as<String>();
    
    str_Temperature = String(doc["main"]["temp"].as<float>());
    str_Feels_Like = String(doc["main"]["feels_like"].as<float>());
    str_Temp_Max = String(doc["main"]["temp_max"].as<float>());
    str_Temp_Min = String(doc["main"]["temp_min"].as<float>());
    
    str_Humidity = String(doc["main"]["humidity"].as<int>());
    str_Wind_Speed = String(doc["wind"]["speed"].as<float>());
    str_Pressure = String(doc["main"]["pressure"].as<int>());
    str_Visibility = String(doc["visibility"].as<int>());
    
    Serial.println();
    Serial.print("Weather Main : "); Serial.println(str_Weather_Main);
    Serial.print("Weather Icon : "); Serial.println(str_Weather_Icon);
    Serial.print("Weather Description : "); Serial.println(str_Weather_Description);
    
    Serial.print("Temperature : "); Serial.print(str_Temperature); Serial.println(" °C");
    Serial.print("Feels Like : "); Serial.print(str_Feels_Like); Serial.println(" °C");
    Serial.print("Temp Max : "); Serial.print(str_Temp_Max); Serial.println(" °C");
    Serial.print("Temp Min : "); Serial.print(str_Temp_Min); Serial.println(" °C");
    
    Serial.print("Humidity : "); Serial.print(str_Humidity); Serial.println(" %");
    Serial.print("Wind Speed : "); Serial.print(str_Wind_Speed); Serial.println(" m/s");
    Serial.print("Pressure : "); Serial.print(str_Pressure); Serial.println(" hPa");
    Serial.print("Visibility : "); Serial.print(str_Visibility); Serial.println(" m");

    Serial.println("-------------");
    //Serial.println();

    //strcpy(ca_Info_Status, "(Succeed)");
    delay(1000);
  }
  else {
    //strcpy(ca_Info_Status, "(Failed : WiFi Disconnected !)");
    Serial.println("WiFi Disconnected");
    Serial.println("-------------");
    Serial.println();
  }
}

void set_initial_display_of_labels() {
  lv_label_set_text(objects.label_city, cityName.c_str());
  lv_label_set_text(objects.label_date, "--, ----");
  lv_label_set_text(objects.label_time, "--:--:--");
  lv_label_set_text(objects.label_weather_description, "--");
  lv_label_set_text(objects.label_temperature, "--.--°C");
  lv_label_set_text(objects.label_feels_like, "--.-- °C");
  lv_label_set_text(objects.label_max, "--.-- °C");
  lv_label_set_text(objects.label_min, "--.-- °C");
  lv_label_set_text(objects.label_humd, "--%");
  lv_label_set_text(objects.label_wind, "-- km/h");
  lv_label_set_text(objects.label_pressure, "-- hPa");

  update_UI();
}

//Cập nhật Weather data
void update_Weather_Data() {
  // Call the get_DateTime() subroutine.
  //get_DateTime();

  //char ca_Time[10];
  //sprintf(ca_Time, "%02d:%02d:%02d", t_hour, t_minute, t_second);
  
  // Call the get_Data_from_OpenWeatherMap() subroutine.
  get_Data_from_OpenWeatherMap();

  // Displays weather conditions.
  //lv_label_set_text(objects.label_weather_info, str_Weather_Main.c_str());

  //----------------------------------------Displays weather icon images.
  // For a list of icon variable names, see the "images.c" file.
  if (str_Weather_Icon == "01d") {
    lv_img_set_src(objects.image_icon_weather, &img_sunny);
  } else if (str_Weather_Icon == "01n") {
    lv_img_set_src(objects.image_icon_weather, &img_night);
  } else if (str_Weather_Icon == "02d") {
    lv_img_set_src(objects.image_icon_weather, &img_cloud);
  } else if (str_Weather_Icon == "02n") {
    lv_img_set_src(objects.image_icon_weather, &img_cloud);
  } else if (str_Weather_Icon == "03d" || str_Weather_Icon == "03n") {
    lv_img_set_src(objects.image_icon_weather, &img_cloud);
  } else if (str_Weather_Icon == "04d" || str_Weather_Icon == "04n") {
    lv_img_set_src(objects.image_icon_weather, &img_cloud);
  } else if (str_Weather_Icon == "09d" || str_Weather_Icon == "09n") {
    lv_img_set_src(objects.image_icon_weather, &img_rain);
  } else if (str_Weather_Icon == "10d") {
    lv_img_set_src(objects.image_icon_weather, &img_rain);
  } else if (str_Weather_Icon == "10n") {
    lv_img_set_src(objects.image_icon_weather, &img_rain);
  } else if (str_Weather_Icon == "11d" || str_Weather_Icon == "11n") {
    lv_img_set_src(objects.image_icon_weather, &img_stormy);
  } else if (str_Weather_Icon == "13d" || str_Weather_Icon == "13n") {
    lv_img_set_src(objects.image_icon_weather, &img_wind);
  } else if (str_Weather_Icon == "50d" || str_Weather_Icon == "50n") {
    lv_img_set_src(objects.image_icon_weather, &img_windy);
  } 
  //----------------------------------------

  // Displays a description of weather conditions.
  lv_label_set_text(objects.label_weather_description, str_Weather_Description.c_str());

  //----------------------------------------Displays temperature values ​​and other temperature data.
  float f_Temp = str_Temperature.toFloat();
  char ca_Temp[10];
  lv_snprintf(ca_Temp, sizeof(ca_Temp), "%.1f°C", f_Temp);
  lv_label_set_text(objects.label_temperature, ca_Temp);

  float f_Feels_Like = str_Feels_Like.toFloat();
  char ca_Feels_Like[11];
  lv_snprintf(ca_Feels_Like, sizeof(ca_Feels_Like), "%.1f °C", f_Feels_Like);
  lv_label_set_text(objects.label_feels_like, ca_Feels_Like);

  float f_Temp_Max = str_Temp_Max.toFloat();
  char ca_Temp_Max[11];
  lv_snprintf(ca_Temp_Max, sizeof(ca_Temp_Max), "%.1f °C", f_Temp_Max);
  lv_label_set_text(objects.label_max, ca_Temp_Max);

  float f_Temp_Min = str_Temp_Min.toFloat();
  char ca_Temp_Min[11];
  lv_snprintf(ca_Temp_Min, sizeof(ca_Temp_Min), "%.1f °C", f_Temp_Min);
  lv_label_set_text(objects.label_min, ca_Temp_Min);
  //----------------------------------------

  // Displays humidity value.
  str_Humidity += " %";
  lv_label_set_text(objects.label_humd, str_Humidity.c_str());

  // Displays wind speed value
  // By default, wind speed values ​​from OpenWeatherMap are in meters per second (m/s).
  // "float f_Wind_Speed ​​= str_Wind_Speed.toFloat() * 3.6;" is to convert from m/s to km/h.
  float f_Wind_Speed = str_Wind_Speed.toFloat() * 3.6;
  char ca_Wind_Speed[12];
  lv_snprintf(ca_Wind_Speed, sizeof(ca_Wind_Speed), "%.1f km/h", f_Wind_Speed);
  lv_label_set_text(objects.label_wind, ca_Wind_Speed);

  // Displays pressure value (atmospheric pressure / air pressure).
  str_Pressure += " hPa";
  lv_label_set_text(objects.label_pressure, str_Pressure.c_str());

  // Displays visibility values.
  // By default, visibility values ​​from OpenWeatherMap are in meters.
  // "float f_Visibility = str_Visibility.toFloat() / 1000;" is to convert from meters to kilometers.
 /* float f_Visibility = str_Visibility.toFloat() / 1000;
  char ca_Visibility[9];
  lv_snprintf(ca_Visibility, sizeof(ca_Visibility), "%.1f km", f_Visibility);
  lv_label_set_text(objects.label_visibility, ca_Visibility);

  // Displays other information.
  char ca_Info[70];
  lv_snprintf(ca_Info, sizeof(ca_Info), "Last data update: %s %s", ca_Time, ca_Info_Status);
  lv_label_set_text(objects.label_info, ca_Info);*/
}
//________________________________________________________________________________ 

//-------------------------------------------------------------------------------------------------------------------------------//




//--------------------------------------------------Sự kiện chuyển đổi màn hình--------------------------------------------------//
void switch_screen(lv_obj_t *new_screen) {
    lv_scr_load(new_screen);  // Chuyển sang màn hình được chỉ định
}

static void goto_screen_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_CLICKED) {
        lv_obj_t *target_screen = (lv_obj_t *)lv_event_get_user_data(e);  // Lấy dữ liệu màn hình từ user_data
        if (target_screen) {
            Serial.println("Switching screen...");
            switch_screen(target_screen);
        }
    }
}

void change_screen_events() {
    //------------------Back về main screen
    lv_obj_t* back_buttons[] = { objects.back_btn, objects.back_btn_1, objects.back_btn_2, objects.back_btn_3,
                                 objects.back_btn_4, objects.back_btn_5, objects.back_btn_6, objects.back_btn_7 };
    for (lv_obj_t* btn : back_buttons) { //Duyệt qua từng btn
        lv_obj_add_event_cb(btn, goto_screen_event_handler, LV_EVENT_ALL, objects.main); //gán sự kiện cho từng phần tử
    }

    //------------------Goto screen
    typedef struct {
        lv_obj_t* goto_screen_btn;
        lv_obj_t* screen;
    } screen_info;
    //Btn tương ứng với từng screen
    screen_info screen_map[] = {
        { objects.clock, objects.clock_screen },
        { objects.calendar, objects.calendar_screen },
        { objects.picture, objects.image_screen },
        { objects.temp, objects.temp_screen },
        { objects.setting, objects.setting_screen },
        { objects.message, objects.message_screen },
        { objects.weather, objects.weather_screen },
        { objects.note, objects.note_screen }
    };

    for (auto& entry : screen_map) { //Tự động lấy và duyệt qua từng phần tử trong screen_map
        lv_obj_add_event_cb(entry.goto_screen_btn, goto_screen_event_handler, LV_EVENT_ALL, entry.screen); //gán sự kiện cho từng phần tử
    }
}
//-------------------------------------------------------------------------------------------------------------------------------//



void setup() {
  //Một số thông tin cơ bản trên Serial console
  String LVGL_Arduino = "LVGL demo ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(9600);
  Serial.println(LVGL_Arduino);

  //Khởi tạo Touchscreen
  touchscreenSpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS); 
  touchscreen.begin(touchscreenSpi);                                        
  touchscreen.setRotation(3);                                               

  //Khởi tạo LVGL GUI
  lv_init();

  draw_buf = new uint8_t[DRAW_BUF_SIZE];
  lv_display_t *disp;
  disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, DRAW_BUF_SIZE);//Tạo màn hình TFT
  //lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);

  //Khởi tạo driver thiết bị đầu vào XPT2046 
  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, my_touchpad_read);

  //Hoàn thành Setup LVGL
  Serial.println("LVGL Setup done");

  //Tích hợp EEZ Studio GUI
  ui_init();

  set_initial_display_of_labels();

  connecting_To_WiFi();

  update_Weather_Data();


  //Đăng kí LVGL event handlers 
  lv_obj_add_event_cb(objects.dd_note, get_selected_option_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
  
  //Tái sử dụng cùng một event handler cho cả nút bấm và bàn phím
  //lv_obj_add_event_cb(objects.btn_add_option, button_add_new_option_event_handler, LV_EVENT_CLICKED, objects.label_show_selection);
  lv_obj_add_event_cb(objects.keyboard_note, button_add_new_option_event_handler, LV_EVENT_READY, NULL);

  lv_obj_add_event_cb(objects.keyboard_note, keyboard_cancel_event_handler, LV_EVENT_CANCEL, NULL);

  change_screen_events();


  tft.invertDisplay(true);

  
}


void loop() {
  //update_Weather_Data();
  update_UI();
}