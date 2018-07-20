#include "semi_gauge.h"
#include "semi_gauge_img.h"
#include "semi_gauge_fill.h"

SemiGauge::SemiGauge(uint16_t max_value):
  max_(max_value),
  value_(0)
{}

void SemiGauge::display(Oled& oled) {
  draw_image(oled, semi_img);
}

/*static*/ void SemiGauge::do_raster(uint8_t value, uint16_t color, Oled& oled) {
  char* diff_ptr = (char*)pgm_read_word(SemiGaugeDiff::diffs + value);
  uint8_t line = pgm_read_byte(diff_ptr);
  if (line == SemiGaugeDiff::END) return;
  uint8_t j = 1;
  while (true) {
    uint8_t start = pgm_read_byte(diff_ptr + j++);
    if (start == SemiGaugeDiff::END) return;
    uint8_t length = pgm_read_byte(diff_ptr + j++);
    oled.drawFastHLine(start, line++, length, color);
  }
}


void SemiGauge::update_value(uint16_t value, Oled& oled) {
  if (value > max_) {
    value = max_;
  }
  uint8_t new_value = map(value, 0, max_, 0, 100);
  if (new_value > value_) {
    for (uint8_t i = value_; i < new_value; ++i) {
      do_raster(i, WHITE, oled);
    }
  } else if (new_value < value_) {
    for (uint8_t i = value_ - 1; i >= new_value; --i) {
      do_raster(i, BLACK, oled);
    }
  }
  value_ = new_value;
}