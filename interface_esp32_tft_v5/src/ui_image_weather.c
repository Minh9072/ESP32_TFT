
#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#elif defined(LV_BUILD_TEST)
#include "../lvgl.h"
#else
#include "lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_DUST
#define LV_ATTRIBUTE_IMG_DUST
#endif

static const
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_DUST
uint8_t img_weather_map[] = {

    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2b,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xeb,0x39,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0xed,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xec,0x31,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xeb,0x39,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2b,0x2a,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2b,0x2a,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x4d,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x6c,0x3a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0b,0x32,0x2c,0x32,0x2c,0x32,0xed,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x0b,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2b,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0xeb,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xb6,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x2c,0x32,0x2c,0x32,0x8c,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2b,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xb6,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x31,0x53,0xcf,0x4a,0xff,0xb5,0xbf,0xb5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x4c,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xbe,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xef,0x39,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xeb,0x29,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0xeb,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xef,0x39,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2b,0x32,0xed,0x29,0x6c,0x32,0x2c,0x2a,0x2c,0x32,0x2c,0x32,0x0c,0x32,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x7b,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x0c,0x32,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x1f,0xbe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0b,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xdf,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x4d,0x22,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4b,0x2a,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x4b,0x32,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xdf,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xfa,0x94,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x4d,0x22,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xae,0x42,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2c,0x32,0x2b,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xd4,0x6b,0x31,0x53,0xd4,0x6b,0x6d,0x3a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xb5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x1f,0xbe,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xff,0xff,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1f,0xbe,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x7f,0xce,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0xbe,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x7f,0xce,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0xff,0xbd,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0x52,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0xc0,0xff,0xff,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x99,0xfe,0xff,0xff,0xef,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0xc5,0xff,0xf7,0xda,0xff,0x96,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0xc5,0xff,0xde,0x2b,0xba,0xff,0x4d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9a,0xff,0xde,0x19,0x00,0xe4,0xff,0x1d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0xfe,0xf7,0x2b,0x00,0x00,0xf6,0xff,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc3,0xff,0x7c,0x00,0x00,0x00,0xf2,0xff,0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2e,0xff,0xec,0x0c,0x00,0x00,0x00,0xd9,0xff,0x26,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0xff,0x96,0x00,0x00,0x00,0x00,0xbb,0xff,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xbc,0xff,0x4d,0x00,0x00,0x00,0x00,0x76,0xff,0x9e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe2,0xff,0x1d,0x00,0x00,0x00,0x00,0x27,0xff,0xee,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf5,0xff,0x08,0x00,0x00,0x00,0x00,0x00,0xbc,0xff,0x86,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0d,0x61,0xa2,0xd6,0xed,0xfc,0xe7,0xcf,0x95,0xfb,0xff,0x05,0x00,0x00,0x00,0x00,0x00,0x33,0xfe,0xf7,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0x90,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfa,0x76,0x07,0x00,0x00,0x00,0x00,0x00,0x92,0xff,0xe4,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x49,0xea,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd2,0x2f,0x00,0x00,0x00,0x00,0x04,0xbc,0xff,0xe5,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6f,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0x44,0x00,0x00,0x00,0x00,0x10,0xbc,0xff,0xf7,0x87,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x62,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf7,0x3e,0x00,0x00,0x00,0x00,0x04,0x91,0xfd,0xff,0xee,0x9f,0x51,0x28,0x0c,0x0a,0x21,0x54,0x84,0x31,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2f,0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe8,0x18,0x00,0x00,0x00,0x00,0x00,0x32,0xbb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xa0,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xa2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x25,0x75,0xba,0xd7,0xf3,0xf7,0xf7,0xff,0xfe,0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x52,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x23,0xe4,0xff,0x92,0x00,
    0x00,0x00,0x00,0x00,0x00,0x1e,0x6d,0xdb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x93,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x37,0xe2,0xff,0xc2,0x07,0x00,0x00,0x00,0x00,0x10,0x9b,0xfa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe2,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0x83,0xfa,0xff,0xc2,0x0e,0x00,0x00,
    0x00,0x00,0x26,0xe1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd6,0xf0,0xf4,0xd4,0x90,0x38,0x54,0x9a,0xf2,0xff,0xfe,0x94,0x07,0x00,0x00,0x00,0x00,0x17,0xe4,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x3b,0x00,0x00,0x00,0x00,0x00,
    0x00,0xb2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x37,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x96,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x2b,0x00,0x00,0x00,0x00,0x00,0x00,0xd6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8e,0x00,0x00,0x00,0x00,0x00,0x00,
    0xf2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd3,0x00,0x00,0x00,0x00,0x00,0x00,0xf5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0x00,0x00,0x00,0x00,0x00,0x00,
    0xdc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0x00,0x00,0x00,0x00,0x00,0x00,0xa2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd3,0x00,0x00,0x00,0x00,0x00,0x00,
    0x4d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8d,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xca,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x2d,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbb,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x2d,0xc9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0x90,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x4c,0xa1,0xda,0xf5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xd3,0x8d,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};

const lv_img_dsc_t img_weather = {
  .header.magic = LV_IMAGE_HEADER_MAGIC,
  .header.cf = LV_COLOR_FORMAT_RGB565A8,
  .header.flags = 0,
  .header.w = 48,
  .header.h = 48,
  .header.stride = 96,
  .data_size = 6912,
  .data = img_weather_map,
};

