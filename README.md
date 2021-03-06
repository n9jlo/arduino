WebUSB ❤ ️Circuit Playground
================

This repository contains an Arduino library for WebUSB-enabling your sketches. Example sketches and JavaScript code are available in the demos directory.

Compatible Hardware
-------------------

WebUSB requires an Arduino model that gives the sketch complete control over the USB hardware. This library has been tested with the following models:

 * Adafruit Circuit Playground

Getting Started
---------------

1. Install at least version 1.6.11 of the [Arduino IDE](https://www.arduino.cc/en/Main/Software).

2. The WebUSB library provides all the extra low-level USB code necessary for WebUSB support except for one thing: Your device must be upgraded from USB 2.0 to USB 2.1. To do this go into the SDK installation directory and open `hardware/arduino/avr/cores/arduino/USBCore.h`. Then find the line `#define USB_VERSION 0x200` and change `0x200` to `0x210`. That's it!

  **macOS:** Right click on the Ardunio application icon and then click on show package contents menu item. Navigate to `Contents/Java/hardware/arduino/avr/cores/arduino/USBCore.h`
  
  **Warning:** Windows requires USB 2.1 devices to present a Binary Object Store (BOS) descriptor when they are enumerated. The code to support this is added by including the "WebUSB" library in your sketch. If you do not include this library after making this change to the SDK then Windows will no longer be able to recognize your device and you will not be able to upload new sketches to it.

3. Copy (or symlink) the `library/WebUSB` directory from this repository into the `libraries` folder in your sketchbooks directory.

4. Launch the Arduino IDE. You should see "WebUSB" as an option under "Sketch > Include Library".

5. Load up `demos/rgb/sketch/sketch.ino` and program it to your device.

6. When the sketch is finished uploading you should see a notification from Chrome: "Go to [https://webusb.github.io/arduino/demos/](https://webusb.github.io/arduino/demos/) to connect." Try it out!

  **Windows:** This notification is currently disabled in Chrome on Windows due to [Chromium issue 656702](https://crbug.com/656702). Implementation of new, more stable USB support for Windows is tracked on Chromium issues [422562](https://crbug.com/422562) and [637404](https://crbug.com/637404).
