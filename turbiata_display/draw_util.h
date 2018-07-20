#ifndef DRAW_UTIL_H
#define DRAW_UTIL_H

#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
//#include <Fonts/TomThumb.h>
#include <Fonts/Picopixel.h>

#define FONT_9PT (&FreeSans9pt7b)
#define FONT_12PT (&FreeSans12pt7b)
#define FONT_18PT (&FreeSans18pt7b)
#define FONT_DEFAULT (NULL)
#define FONT_TINY (&Picopixel)

// Use the following macros for height and width:
#define OLED_HEIGHT SSD1306_LCDHEIGHT 
#define OLED_WIDTH  SSD1306_LCDWIDTH

typedef Adafruit_SSD1306 Oled;

struct Point {
  uint8_t x;
  uint8_t y;
  Point(uint8_t new_x, uint8_t new_y): x(new_x), y(new_y) {}
};

void draw_image(Oled& oled, const unsigned char* img);
void draw_splash_text(Oled& oled);

#endif // DRAW_UTIL_H