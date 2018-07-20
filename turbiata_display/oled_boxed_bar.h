#ifndef OLED_BOXED_BAR_H
#define OLED_BOXED_BAR_H

#include "draw_util.h"

#define TICK_HEIGHT 5

class Label;

class BoxedBar {
 public:
  BoxedBar(uint8_t left, uint8_t top, uint8_t width, uint8_t height, uint16_t max);
  virtual void display(Oled&);
  void update_value(uint16_t, Oled&);
   
 protected:
  const uint8_t left_;
  const uint8_t top_;
  const uint8_t width_;
  const uint8_t height_;
  const uint16_t max_;

 private:
  uint16_t value_;
};

// Tickmark and optional label.
// Label options:
//   - "my_string" -> use "my_string" as the label
//   - "" -> empty label
//   - nullptr -> use the integer value as the label
struct Tick {
  Tick(uint16_t value, const char* label=nullptr): value_(value), label_(label) {}
  uint16_t value_;
  const char* label_;
};

class LabeledBoxedBar: public BoxedBar {
 public:
  LabeledBoxedBar(Point left_top, Point width_height, uint16_t max);
  void setTicksAndLabels(const Tick* ticks, uint8_t n);
  void display(Oled&) override;

 private:
  const Tick* ticks_;
  uint8_t tick_count_;
  
  void draw_ticks(Oled&);
  void draw_label(Label& label, uint8_t tick_x, Oled& oled);
};

#endif // OLED_BOXED_BAR_H
