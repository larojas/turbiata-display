#ifndef SEMI_GAUGE_H
#define SEMI_GAUGE_H

#include "draw_util.h"

class SemiGauge {
 public:
  SemiGauge(uint16_t max_value);
  void display(Oled&);
  void update_value(uint16_t, Oled&);
  
 private:
  const uint16_t max_;
  uint8_t value_;

  static void do_raster(uint8_t value, uint16_t color, Oled& oled);
};

#endif // SEMI_GAUGE_H