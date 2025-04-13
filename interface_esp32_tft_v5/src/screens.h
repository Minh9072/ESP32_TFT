#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *calendar_screen;
    lv_obj_t *clock_screen;
    lv_obj_t *image_screen;
    lv_obj_t *temp_screen;
    lv_obj_t *setting_screen;
    lv_obj_t *message_screen;
    lv_obj_t *weather_screen;
    lv_obj_t *note_screen;
    lv_obj_t *audio;
    lv_obj_t *back_btn;
    lv_obj_t *back_btn_1;
    lv_obj_t *back_btn_2;
    lv_obj_t *back_btn_3;
    lv_obj_t *back_btn_4;
    lv_obj_t *back_btn_5;
    lv_obj_t *back_btn_6;
    lv_obj_t *back_btn_7;
    lv_obj_t *battery;
    lv_obj_t *battery_1;
    lv_obj_t *battery_2;
    lv_obj_t *battery_3;
    lv_obj_t *battery_4;
    lv_obj_t *battery_5;
    lv_obj_t *battery_6;
    lv_obj_t *battery_7;
    lv_obj_t *battery_8;
    lv_obj_t *brightness;
    lv_obj_t *calendar;
    lv_obj_t *clock;
    lv_obj_t *dd_note;
    lv_obj_t *feels;
    lv_obj_t *image_icon_weather;
    lv_obj_t *icon_humd;
    lv_obj_t *icon_location;
    lv_obj_t *icon_max;
    lv_obj_t *icon_pressure;
    lv_obj_t *icon_temp;
    lv_obj_t *icon_wind;
    lv_obj_t *keyboard;
    lv_obj_t *keyboard_note;
    lv_obj_t *label_city;
    lv_obj_t *label_date;
    lv_obj_t *label_feels_like;
    lv_obj_t *label_humd;
    lv_obj_t *label_max;
    lv_obj_t *label_min;
    lv_obj_t *label_pressure;
    lv_obj_t *label_temperature;
    lv_obj_t *label_time;
    lv_obj_t *label_weather_description;
    lv_obj_t *label_wind;
    lv_obj_t *max;
    lv_obj_t *max_1;
    lv_obj_t *message;
    lv_obj_t *message_box;
    lv_obj_t *note;
    lv_obj_t *picture;
    lv_obj_t *pressure;
    lv_obj_t *setting;
    lv_obj_t *sound;
    lv_obj_t *sound_1;
    lv_obj_t *sound_2;
    lv_obj_t *sound_3;
    lv_obj_t *sound_4;
    lv_obj_t *sound_5;
    lv_obj_t *sound_6;
    lv_obj_t *sound_7;
    lv_obj_t *sound_8;
    lv_obj_t *temp;
    lv_obj_t *text_note;
    lv_obj_t *time;
    lv_obj_t *time_1;
    lv_obj_t *time_2;
    lv_obj_t *time_3;
    lv_obj_t *time_4;
    lv_obj_t *time_5;
    lv_obj_t *time_6;
    lv_obj_t *time_7;
    lv_obj_t *time_8;
    lv_obj_t *trash;
    lv_obj_t *wifi;
    lv_obj_t *wifi_1;
    lv_obj_t *wifi_2;
    lv_obj_t *wifi_3;
    lv_obj_t *wifi_4;
    lv_obj_t *wifi_5;
    lv_obj_t *wifi_6;
    lv_obj_t *wifi_7;
    lv_obj_t *wifi_8;
    lv_obj_t *wind;
    lv_obj_t *weather;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_CALENDAR_SCREEN = 2,
    SCREEN_ID_CLOCK_SCREEN = 3,
    SCREEN_ID_IMAGE_SCREEN = 4,
    SCREEN_ID_TEMP_SCREEN = 5,
    SCREEN_ID_SETTING_SCREEN = 6,
    SCREEN_ID_MESSAGE_SCREEN = 7,
    SCREEN_ID_WEATHER_SCREEN = 8,
    SCREEN_ID_NOTE_SCREEN = 9,
};

void create_screen_main();
void tick_screen_main();

void create_screen_calendar_screen();
void tick_screen_calendar_screen();

void create_screen_clock_screen();
void tick_screen_clock_screen();

void create_screen_image_screen();
void tick_screen_image_screen();

void create_screen_temp_screen();
void tick_screen_temp_screen();

void create_screen_setting_screen();
void tick_screen_setting_screen();

void create_screen_message_screen();
void tick_screen_message_screen();

void create_screen_weather_screen();
void tick_screen_weather_screen();

void create_screen_note_screen();
void tick_screen_note_screen();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/