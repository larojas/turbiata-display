#include "oled_boxed_bar.h"
#include "oled_label.h"

BoxedBar::BoxedBar(uint8_t left, uint8_t top, 
                   uint8_t width, uint8_t height, uint16_t max):
  left_(left),
  top_(top),
  width_(width),
  height_(height),
  max_(max),
  value_(0)
{}

void BoxedBar::display(Oled& oled) {
  oled.drawRect(left_, top_, width_, height_, WHITE);
  update_value(value_, oled);
}

void BoxedBar::update_value(uint16_t value, Oled& oled) {
  if (value >= max_) {
    value = max_ - 1;
  }
  uint16_t old_pix_level = map(value_, 0, max_, 0, width_ - 3);
  uint16_t new_pix_level = map(value, 0, max_, 0, width_ - 3);
  if (new_pix_level < old_pix_level) {
    // going down: erase rect
    oled.fillRect(left_ + 2 + new_pix_level, top_ + 2, 
                  old_pix_level - new_pix_level, height_ - 4, BLACK);
  } else if (new_pix_level > old_pix_level) {
    // going up: draw rect
    oled.fillRect(left_ + 2 + old_pix_level, top_ + 2, 
                  new_pix_level - old_pix_level, height_ - 4, WHITE);
  }
  value_ = value;
}

LabeledBoxedBar::LabeledBoxedBar(Point left_top,
                                 Point width_height,
                                 uint16_t max):
  BoxedBar(left_top.x, left_top.y, width_height.x, width_height.y, max),
  ticks_(nullptr),
  tick_count_(0)
{}

void LabeledBoxedBar::setTicksAndLabels(const Tick* ticks, uint8_t n) {
  ticks_ = ticks;
  tick_count_ = n;
}

void LabeledBoxedBar::display(Oled& oled) {
  BoxedBar::display(oled);
  draw_ticks(oled);
}

void LabeledBoxedBar::draw_ticks(Oled& oled) {
  for (uint8_t i = 0; i < tick_count_; ++i) {
    // draw line
    uint8_t tick_x = left_ + map(ticks_[i].value_, 0, max_, 0, width_ - 3);
    oled.drawLine(tick_x, top_, tick_x, top_ - TICK_HEIGHT, WHITE);
    const char* label_str = ticks_[i].label_;
    if (label_str == nullptr) {
      Label label(ticks_[i].value_);
      draw_label(label, tick_x, oled);
    } else if (label_str[0] == '\0') {
      // empty label, do nothing
    } else {
      Label label(label_str);
      draw_label(label, tick_x, oled);
    }
  }
}

void LabeledBoxedBar::draw_label(Label& label, uint8_t tick_x, Oled& oled) {
  // first we'll try to center the label
  uint8_t txt_w = label.get_width();
  int txt_left = tick_x - (txt_w >> 1);
  if (txt_left < left_) {
    txt_left = left_;
  } else if (txt_left + txt_w >= left_ + width_) {
    txt_left = left_ + width_ - txt_w;
  }
  label.set_position(txt_left, top_ - TICK_HEIGHT - 8);
  label.display(oled);
}
