#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffdf7fb), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time = obj;
            lv_obj_set_pos(obj, 11, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // clock
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.clock = obj;
            lv_obj_set_pos(obj, 30, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_clock);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // calendar
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.calendar = obj;
            lv_obj_set_pos(obj, 101, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_calendar);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // picture
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.picture = obj;
            lv_obj_set_pos(obj, 175, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_picture);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // setting
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.setting = obj;
            lv_obj_set_pos(obj, 30, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_setting);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // message
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.message = obj;
            lv_obj_set_pos(obj, 103, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_message);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // note
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.note = obj;
            lv_obj_set_pos(obj, 244, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_note);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            //weather
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.weather = obj;
            lv_obj_set_pos(obj, 175, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_weather);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            //temp
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.temp = obj;
            lv_obj_set_pos(obj, 244, 64);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_temp);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
    }
}

void tick_screen_main() {
}

void create_screen_calendar_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.calendar_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_1 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_1 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_1
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_1 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_1 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_calendar_create(parent_obj);
            lv_obj_set_pos(obj, 0, 28);
            lv_obj_set_size(obj, 320, 212);
            lv_calendar_header_arrow_create(obj);
            lv_calendar_set_today_date(obj, 2022, 11, 1);
            lv_calendar_set_showed_date(obj, 2022, 11);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn
                    lv_obj_t *obj = lv_label_create(parent_obj);                    
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_calendar_screen() {
}

void create_screen_clock_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.clock_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_2 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_2 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_2
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_2 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_2 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_1 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_clock_screen() {
}

void create_screen_image_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.image_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_3 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_3 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_3
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_3 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_3 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_2 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_2
                    lv_obj_t *obj = lv_label_create(parent_obj);                   
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_image_screen() {
}

void create_screen_temp_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.temp_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_5
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_5 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_5
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_5 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_5
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_5 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_5 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_3 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_3
                    lv_obj_t *obj = lv_label_create(parent_obj);                   
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
}

void tick_screen_temp_screen() {
}

void create_screen_setting_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.setting_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_4 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_4 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_4
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_4 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_4 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_4 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_4
                    lv_obj_t *obj = lv_label_create(parent_obj);                    
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // audio
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.audio = obj;
            lv_obj_set_pos(obj, 33, 50);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_audio);
        }
        {
            // brightness
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.brightness = obj;
            lv_obj_set_pos(obj, 33, 106);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_brightness);
        }
        {
            // trash
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.trash = obj;
            lv_obj_set_pos(obj, 33, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_trash);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            lv_obj_set_pos(obj, 94, 69);
            lv_obj_set_size(obj, 202, 10);
            lv_bar_set_value(obj, 30, LV_ANIM_OFF);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff010001), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff7b13db), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            lv_obj_set_pos(obj, 94, 125);
            lv_obj_set_size(obj, 202, 10);
            lv_bar_set_value(obj, 90, LV_ANIM_OFF);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff010001), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff7b13db), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_bar_create(parent_obj);
            lv_obj_set_pos(obj, 94, 181);
            lv_obj_set_size(obj, 202, 10);
            lv_bar_set_value(obj, 50, LV_ANIM_OFF);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff010001), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff7b13db), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_setting_screen() {
}

void create_screen_message_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.message_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_6
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_6 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_6
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_6 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_6
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_6 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_6
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_6 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_5 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_5
                    lv_obj_t *obj = lv_label_create(parent_obj);                   
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // message_box
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.message_box = obj;
            lv_obj_set_pos(obj, 0, 28);
            lv_obj_set_size(obj, 320, 92);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
        }
        {
            // keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keyboard = obj;
            lv_obj_set_pos(obj, 0, 120);
            lv_obj_set_size(obj, 320, 120);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_keyboard_set_textarea(objects.keyboard, objects.message_box);
}

void tick_screen_message_screen() {
}

void create_screen_weather_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.weather_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_7
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_7 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_7
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_7 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_7
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_7 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_7
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_7 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_6 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_6
                    lv_obj_t *obj = lv_label_create(parent_obj);                  
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // icon_location
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_location = obj;
            lv_obj_set_pos(obj, 111, 50);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_location);
        }
        {
            // icon_temp
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_temp = obj;
            lv_obj_set_pos(obj, 10, 180);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_temp2);
        }
        {
            // icon_humd
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_humd = obj;
            lv_obj_set_pos(obj, 10, 310);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_humidity);
        }
        {
            // icon_wind
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_wind = obj;
            lv_obj_set_pos(obj, 102, 318);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_wind);
        }
        {
            // icon_pressure
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_pressure = obj;
            lv_obj_set_pos(obj, 232, 318);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_pressure);
        }
        {
            // icon_01d
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.image_icon_weather = obj;
            lv_obj_set_pos(obj, 10, 50);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_sunny);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 9, 37);
            lv_obj_set_size(obj, 302, 122);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff939393), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 10, 167);
            lv_obj_set_size(obj, 302, 122);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff939393), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 9, 297);
            lv_obj_set_size(obj, 302, 122);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xff939393), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_city
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_city = obj;
            lv_obj_set_pos(obj, 159, 66);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "City");
        }
        {
            // label_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_time = obj;
            lv_obj_set_pos(obj, 212, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00:00");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_date = obj;
            lv_obj_set_pos(obj, 184, 130);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Wed, 00-12-2025");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_weather_description
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_weather_description = obj;
            lv_obj_set_pos(obj, 111, 106);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Clear");
        }
        {
            // icon_max
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_max = obj;
            lv_obj_set_pos(obj, 111, 180);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_arrowup);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 205, 180);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_icon_min);
        }
        {
            // label_temperature
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_temperature = obj;
            lv_obj_set_pos(obj, 106, 243);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0°C");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // max
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.max = obj;
            lv_obj_set_pos(obj, 159, 180);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Max");
        }
        {
            // max_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.max_1 = obj;
            lv_obj_set_pos(obj, 254, 180);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Min");
        }
        {
            // label_max
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_max = obj;
            lv_obj_set_pos(obj, 159, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0°C");
        }
        {
            // label_min
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_min = obj;
            lv_obj_set_pos(obj, 253, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0°C");
        }
        {
            // wind
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.wind = obj;
            lv_obj_set_pos(obj, 151, 326);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Wind");
        }
        {
            // label_wind
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_wind = obj;
            lv_obj_set_pos(obj, 151, 342);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "000.0km/h");
        }
        {
            // label_humd
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_humd = obj;
            lv_obj_set_pos(obj, 106, 373);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "000%");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // pressure
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pressure = obj;
            lv_obj_set_pos(obj, 224, 366);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Pressure");
        }
        {
            // label_pressure
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_pressure = obj;
            lv_obj_set_pos(obj, 224, 382);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0000hPa");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // feels
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.feels = obj;
            lv_obj_set_pos(obj, 229, 243);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Feels like");
        }
        {
            // label_feels_like
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_feels_like = obj;
            lv_obj_set_pos(obj, 229, 260);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0°C");
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_weather_screen() {
}

void create_screen_note_screen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.note_screen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 28);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff2f2f2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // wifi_8
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wifi_8 = obj;
            lv_obj_set_pos(obj, 280, 0);
            lv_obj_set_size(obj, 31, 26);
            lv_img_set_src(obj, &img_wifi);
        }
        {
            // sound_8
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.sound_8 = obj;
            lv_obj_set_pos(obj, 244, 0);
            lv_obj_set_size(obj, 36, 26);
            lv_img_set_src(obj, &img_sound);
        }
        {
            // battery_8
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.battery_8 = obj;
            lv_obj_set_pos(obj, 213, 0);
            lv_obj_set_size(obj, 31, 28);
            lv_img_set_src(obj, &img_battery);
            lv_img_set_pivot(obj, 15, 14);
            lv_img_set_angle(obj, 1);
        }
        {
            // time_8
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_8 = obj;
            lv_obj_set_pos(obj, 67, 4);
            lv_obj_set_size(obj, 53, 21);
            lv_label_set_text(obj, "02:54");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.back_btn_7 = obj;
            lv_obj_set_pos(obj, 9, 2);
            lv_obj_set_size(obj, 47, 24);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff696969), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_btn_7
                    lv_obj_t *obj = lv_label_create(parent_obj);                    
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // text_note
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.text_note = obj;
            lv_obj_set_pos(obj, 0, 28);
            lv_obj_set_size(obj, 229, 92);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, false);
            lv_textarea_set_password_mode(obj, false);
            //lv_obj_clear_flag(obj, LV_OBJ_FLAG_PRESS_LOCK);
        }
        {
            // keyboard_note
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keyboard_note = obj;
            lv_obj_set_pos(obj, 1, 120);
            lv_obj_set_size(obj, 319, 120);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_TEXT_UPPER);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // dd_note
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.dd_note = obj;
            lv_obj_set_pos(obj, 229, 28);
            lv_obj_set_size(obj, 91, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Note 1\nNote 2\nNote 3");
        }
    }
    lv_keyboard_set_textarea(objects.keyboard_note, objects.text_note);
}

void tick_screen_note_screen() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_calendar_screen();
    create_screen_clock_screen();
    create_screen_image_screen();
    create_screen_temp_screen();
    create_screen_setting_screen();
    create_screen_message_screen();
    create_screen_weather_screen();
    create_screen_note_screen();

    lv_scr_load(objects.main);
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_calendar_screen,
    tick_screen_clock_screen,
    tick_screen_image_screen,
    tick_screen_temp_screen,
    tick_screen_setting_screen,
    tick_screen_message_screen,
    tick_screen_weather_screen,
    tick_screen_note_screen,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
