# turbiata-display

This is very early WIP. Currently a bunch of base utilities and basic widgets.
It allows you to drive three independent OLED displays, even if they share the same hardware address, via an I2C multiplexer, and implements a few widgets to try: text labels, progress bars, a few splash screens (as bitmaps; you can create your own).

Requirements:
  - (1x) arduino
  - (3x) I2C Oled display, 128x64
  - (1x) I2C 7-bus multiplexer
  - (1x) [optional] power regulator / power distribution board
  - (1x) CAN-bus shield for Arduino

Other optional dependencies:
  - Fusion 360
  - CNC or 3D printer to fabricate mounts, enclosures, trim pieces

