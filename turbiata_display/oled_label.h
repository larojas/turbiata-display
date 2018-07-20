#ifndef OLED_LABEL_H
#define OLED_LABEL_H

#include "draw_util.h"

#define MAX_WIDTH 10

class BaseLabel {
 public:
  void set_position(uint8_t x, uint8_t y);
  void display(Oled&);
  void erase(Oled&);

 protected:
  BaseLabel(uint8_t x=0, uint8_t y=0);
  virtual void draw(uint16_t color, Oled&) = 0;

 private:
  uint8_t x_;
  uint8_t y_;
};

class Label: public BaseLabel {
 public:
  Label(const char* str, uint8_t max_width=0);
  Label(uint16_t value, uint8_t max_width=0, bool zero_padded=0);

  void set_value(const char* value);
  void set_value(uint16_t value);
  void set_font(const GFXfont*);
  uint8_t get_width();
  
  static uint8_t log10(uint16_t);

 protected:
  void draw(uint16_t color, Oled&) override;
  
 private:
  const uint8_t width_;
  char text_[MAX_WIDTH];
  const GFXfont* font_;
  bool zero_;
};

#endif // OLED_LABEL_H