#include "oled_progress_bar.h"

ProgressBar::ProgressBar(uint16_t left, uint16_t bottom,
                         uint16_t width, uint16_t height):
  left_(left),
  bottom_(bottom),
  width_(width),
  height_(height),
  level_(0)
{}

void ProgressBar::draw_bar(uint16_t level, int color, Oled& display) {
  display.drawLine(
    left_ + level, bottom_, left_ + level, 
    bottom_ - map(level, 0, width_, 0, height_),
    color);
}

void ProgressBar::set_level(uint16_t new_level, Oled& display) {
  if (new_level < level_) {
    // going down: erase bars
    for (uint16_t i = new_level; i < level_; ++i) {
      draw_bar(i, BLACK, display);
    }
  } else if (new_level > level_){
    // going up: draw bars
    for (uint16_t i = level_; i < new_level; ++i) {
      draw_bar(i, WHITE, display);
    }
  }
  level_ = new_level;
}
