#ifndef OLED_PROGRESS_BAR_H
#define OLED_PROGRESS_BAR_H

#include <Adafruit_SSD1306.h>
#include "draw_util.h"

class ProgressBar {
 public:
  ProgressBar(uint16_t left, uint16_t bottom, uint16_t width, uint16_t height);
  void set_level(uint16_t level, Oled& display);
  
 private:
  uint16_t left_;
  uint16_t bottom_;
  uint16_t width_;
  uint16_t height_;
  uint16_t level_;
  
  void draw_bar(uint16_t level, int color, Oled& display);
};

#endif // OLED_PROGRESS_BAR_H
