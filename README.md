# turbiata-display

This is early WIP. Currently a bunch of base utilities and basic widgets.
It allows you to drive three independent OLED displays, even if they share the same hardware address, via an I2C multiplexer, and implements a few widgets to try: text labels, progress bars, a few splash screens (as bitmaps; you can create your own).

That is today, but the end vision is a system for connecting to your standalone ECU via CAN-bus (targeting MegaSquirt but I guess others should work with some tweaking), then selecting engine parameters and gauge styles, and enjoying live data on the go (AFR, coolant temp, oil pressure, RPM, boost/vacuum, duty cycles, timing, etc.).

### Requirements:
  - (1x) arduino
  - (3x) I2C Oled display, 128x64
  - (1x) I2C 7-bus multiplexer
  - (1x) [optional] power regulator / power distribution board
  - (1x) CAN-bus shield for Arduino
  - Various switches or encoders as input to control the display

### Other optional dependencies:
  - Fusion 360
  - CNC or 3D printer to fabricate mounts, enclosures, trim pieces


## Notes:
  - The Adafruit Oled library (Adafruit_SSD1306) doesn't support multiple displays, since it has a global buffer variable. So I have included a patch file (see [resources/Adafruit_SSD1306.diff](resources/Adafruit_SSD1306.diff)) that you can apply or use as a guide to modify the library. Basically it creates an instance variable for each object, copying from the base buffer. Unfortunately, this means more memory consumption but it's kind of unavoidable. Possible optimization: if all abjects are created before the first write, one copy of the buffer could be saved by having the global buffer mapped to one instance, and further instances can get their own copy. I have not implemented that optimization as the Arduino mega has enough resources so far (given all other graphic resources are in `PROGMEM` already).
  - The current main Arduino file references a library (`pots.h`)that I'm not uploading here. It's a small potentiometer library that handles smoothing and detecting changes. This is only transient for my current testing so the reference to it will be removed in future commits. In the meantime, you can replace it with something else or remove the Pots variable entirely. The demo will still show stuff.
  - There are two Python utilities: one for generating bitmaps and the other for generating one of the supported widgets. The bitmap generation takes a .h that GIMP would generate and packs it more tightly into bytes. There surely is a beter way to do this. Also, the Adafruit library supports bitmap display but I haven't tried it; I wrote my own routine to take that packed format and display it but I have the impression Adafruit's function takes the same format, coincidentally. I'm not sure. The utility also has the GIMP output for the three bitmaps I'm using hardcoded inside; this clearly can be improved. See [turbiata_display/arduino_bmp.py](turbiata_display/arduino_bmp.py) for more info.
  - The widget utility takes the semicircular widget bitmap and generates pixel deltas for incrementally filling up the semicircle in `n` steps (currently 100 by default), so that the Arduino program can have a routine that applies or removes these deltas as the gauge value changes. It uses cv2 for visualization so you can check that the correct pixels are being generated, and that the correct deltas are being generated for those pixels. See [turbiata_display/radial_line.py](turbiata_display/radial_line.py) for more info.

## TODO:
  - Add CAN-bus routines. Currently nothing implemented.
  - Add sources (engine data from the CAN-bus).
  - Add sinks (visual widgets) --take the current widgets and make them more usable by e.g. presenting the same interface, adding labels where applicable, etc.
  - Add code to manage sources and sinks.
  - Consider other display formats and resolutions.
  - Experiment with SPI instead of I2C which already at 3 screens is quite slow.
