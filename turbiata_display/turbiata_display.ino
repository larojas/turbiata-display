#include "oled_display.h"
#include "draw_util.h"
#include "miata_img.h"
#include "turbo_img.h"
#include "oled_progress_bar.h"
#include "oled_label.h"
#include "oled_boxed_bar.h"
#include "semi_gauge.h"
#include "pots.h"

#define LEFT 0
#define CENTER 1
#define RIGHT 2

// Globals
uint8_t display_ports[] = {2, 3, 4};
MuxOledDisplays displays(0x70, 3, display_ports);
ProgressBar bar(0, 32, 128, 32);
Label rpm_label(0, 4, /*zero_padded*/true);
Label fps_label(0, 4, /*zero_padded*/false);
LabeledBoxedBar coolant_bar(Point(0, 32), Point(128, 32), 212);
SemiGauge rpm_gauge(7500);
const int pot_pins[] = {A0};
Pots pot(1, pot_pins);
long temp = 60;

void setup() {
  while (!Serial);
  delay(1000);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("ready!");
  
  displays.init();
  draw_image(displays[LEFT], turbo_img);
  draw_image(displays[RIGHT], miata_img);
  draw_splash_text(displays[CENTER]);
  
  delay(2000);
  displays[CENTER].clearDisplay();
  rpm_label.set_font(FONT_18PT);
  rpm_label.set_position(33, 60);
  rpm_label.display(displays[CENTER]);
  displays[CENTER].display();

  displays[RIGHT].clearDisplay();
  rpm_gauge.display(displays[RIGHT]);
  displays[RIGHT].display();

  displays[LEFT].clearDisplay();  
  Tick ticks[] = { Tick(0, "cold"), Tick(100, "ok"), Tick(200, ""), Tick(212) };
  coolant_bar.setTicksAndLabels(ticks, 4);
  coolant_bar.display(displays[LEFT]);
  fps_label.set_position(33, 1);
  fps_label.display(displays[LEFT]);
  displays[LEFT].display();
}

int progress = 0;

void loop() {
  unsigned long start = millis();
  
  if (++progress >= 128) progress = 0;
  bar.set_level(progress, displays[CENTER]);
  rpm_label.erase(displays[CENTER]);
  rpm_label.set_value(progress*10);
  rpm_label.display(displays[CENTER]);
  if (pot.get_value(0) >= 512) {
    displays[CENTER].display();
  }
    
  pot.poll();
  if (pot.has_changed_pot()) {
    int val = map(pot.get_value(0), 0, 1023, 0, 7500);
    pot.clear_changed();
    rpm_gauge.update_value(val, displays[RIGHT]);
    displays[RIGHT].display();
  }

  temp += random(21) - 10;
  if (temp < 0) temp = 0;
  coolant_bar.update_value(temp, displays[LEFT]);
  fps_label.erase(displays[LEFT]);
  fps_label.set_value((uint16_t)(millis() - start));
  fps_label.display(displays[LEFT]);
  displays[LEFT].display();
}
