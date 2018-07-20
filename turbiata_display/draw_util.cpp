#include "draw_util.h"

void draw_image(Oled& oled, const unsigned char* img) {
  oled.clearDisplay();
  unsigned char buffer[SSD1306_LCDWIDTH * SSD1306_LCDHEIGHT / 8];
  memcpy_P(buffer, img, SSD1306_LCDWIDTH * SSD1306_LCDHEIGHT / 8);
  for (int i = 0; i < SSD1306_LCDWIDTH * SSD1306_LCDHEIGHT; ++i) {
    // Avoiding division: i/8 becomes i>>3, and i%8 becomes i&7
    bool is_set = buffer[i >> 3] & (1 << (i & 7));
    if (is_set) {
      // Let's avoid these divisions if displays are 128x64
#if SSD1306_LCDWIDTH == 128
      oled.drawPixel(i & (127), i >> 7, WHITE);
#else
      oled.drawPixel(i % SSD1306_LCDWIDTH, i / SSD1306_LCDWIDTH, WHITE);
#endif
    }
  }
  oled.display();
}

void draw_splash_text(Oled& oled) {
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setFont(FONT_9PT);
  oled.setCursor(0, 16);
  oled.print("Display System");
  oled.setFont(FONT_DEFAULT);
  oled.setCursor(0, 48);
  oled.print("(c)2018 larxyz Soft");
  oled.setFont(FONT_TINY);
  oled.setCursor(72, 62);
  oled.print("v0.1 - alpha");
  oled.display();
}
