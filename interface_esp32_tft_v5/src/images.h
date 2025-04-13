#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_wifi;
extern const lv_img_dsc_t img_bluetooth;
extern const lv_img_dsc_t img_battery;
extern const lv_img_dsc_t img_clock;
extern const lv_img_dsc_t img_calendar;
extern const lv_img_dsc_t img_setting;
extern const lv_img_dsc_t img_message;
extern const lv_img_dsc_t img_call;
extern const lv_img_dsc_t img_note;
extern const lv_img_dsc_t img_file;
extern const lv_img_dsc_t img_caculator;
extern const lv_img_dsc_t img_picture;
extern const lv_img_dsc_t img_temp;
extern const lv_img_dsc_t img_weather;
extern const lv_img_dsc_t img_sound;
extern const lv_img_dsc_t img_brightness;
extern const lv_img_dsc_t img_audio;
extern const lv_img_dsc_t img_trash;
extern const lv_img_dsc_t img_location;
extern const lv_img_dsc_t img_humidity;
extern const lv_img_dsc_t img_sunny;
extern const lv_img_dsc_t img_wind;
extern const lv_img_dsc_t img_cloud;
extern const lv_img_dsc_t img_lightning;
extern const lv_img_dsc_t img_rain;
extern const lv_img_dsc_t img_stormy;
extern const lv_img_dsc_t img_pressure;
extern const lv_img_dsc_t img_windy;
extern const lv_img_dsc_t img_visibility;
extern const lv_img_dsc_t img_temp2;
extern const lv_img_dsc_t img_arrowup;
extern const lv_img_dsc_t img_icon_min;
extern const lv_img_dsc_t img_night;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[33];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/