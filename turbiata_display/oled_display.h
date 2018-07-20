#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define OLED_RESET 4

class MuxOledDisplays {
 public:
   MuxOledDisplays(uint8_t mux_addr, uint8_t n, const uint8_t* ports):
     mux_addr_(mux_addr),
     ports_(ports),
     n_(n),
     current_(-1),
     dirty_(0)
  {
    Wire.begin();
    displays_ = new Adafruit_SSD1306*[n];
  }
  
  void clear_all() {
    for (uint8_t i = 0; i < n_; ++i) {
      (*this)[i].clearDisplay();
      (*this)[i].display();
    }
    dirty_ = 0;
  }

  Adafruit_SSD1306& operator [](uint8_t number) {
    switch_to(number);
    dirty_ |= (1 << number);
    return *displays_[number];
  }

  void init() {
    for (uint8_t i = 0; i < n_; ++i) {
      Serial.print("Initializing oled number "); Serial.println(i);
      switch_to(i);
      displays_[i] = new Adafruit_SSD1306(OLED_RESET);
      displays_[i]->begin();
      displays_[i]->setTextWrap(false);
    }
    clear_all();
  }
  
  void clean(uint8_t number) {
    dirty_ ^= (1 << number);
  }
  
  bool is_dirty(uint8_t number) {
    return dirty_ & (1 << number);
  }

 private:
  const uint8_t mux_addr_;
  Adafruit_SSD1306** displays_;
  const uint8_t* ports_;
  const uint8_t n_;
  uint8_t current_;
  uint8_t dirty_;
  
  void switch_to(uint8_t number) {
    if (current_ != number) {
      //Serial.print("Switching to display "); Serial.println(number);
      Wire.beginTransmission(mux_addr_);
      Wire.write(1 << ports_[number]);
      Wire.endTransmission();
      current_ = number;
    }
  }
};

// RAII: switch to a display, draw stuff, and refresh the display.
class DisplayWrapper {
 public:
  DisplayWrapper(MuxOledDisplays& displays, uint8_t number):
    oled_(displays[number]) {}
  ~DisplayWrapper() { oled_.display(); }
  operator Adafruit_SSD1306&() { return oled_; }
 private:
   Adafruit_SSD1306& oled_;
};


#endif // OLED_DISPLAY_H