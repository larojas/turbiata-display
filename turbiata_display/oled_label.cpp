#include "oled_label.h"

void BaseLabel::set_position(uint8_t x, uint8_t y) {
  x_ = x;
  y_ = y;
}

void BaseLabel::display(Oled& oled) {
  oled.setCursor(x_, y_);
  draw(WHITE, oled);
}

void BaseLabel::erase(Oled& oled) {
  oled.setCursor(x_, y_);
  draw(BLACK, oled);
}

BaseLabel::BaseLabel(uint8_t x, uint8_t y):
  x_(x),
  y_(y)
{}

Label::Label(const char* str, uint8_t max_width):
  width_(max_width > 0 ? max_width : strlen(str)),
  font_(nullptr),
  zero_(false)
{
  set_value(str);
}

Label::Label(uint16_t value, uint8_t max_width, bool zero_padded):
  width_(max_width > 0 ? max_width : log10(value)),
  font_(nullptr),
  zero_(zero_padded)
{
  set_value(value);
}

void Label::set_value(const char* value) {
  strncpy(text_, value, width_);
  text_[width_] = '\0';
}

void Label::set_value(uint16_t value) {
  char format[] = "%099d";
  sprintf(format, "%%%s%dd", zero_? "0" : "", width_);
  snprintf(text_, width_ + 1, format, value);
  text_[width_] = '\0';
}

void Label::set_font(const GFXfont* font) {
  font_ = font;
}

void Label::draw(uint16_t color, Oled& oled) {
  if (strlen(text_) == 0) return;
  oled.setTextColor(color);
  oled.setFont(font_, false);
  oled.print(text_);
}

uint8_t Label::get_width() {
  // TODO(arojas): make this dependent on font type
  int len = strlen(text_);
  return len > 0 ?  len * 6 - 1 : 0;
}

/*static*/ uint8_t Label::log10(uint16_t v) {
  return (v > 9999) ? 5 : (v > 999)? 4 : (v > 99)? 3 : (v > 9)? 2 : 1;
}

