#include <WebUSB.h>
#include <Adafruit_CircuitPlayground.h>

WebUSB WebUSBSerial(1, "https://n9jlo.github.io/arduino/demos/rgb/");

#define Serial WebUSBSerial

int index;
int color[3];

void setup() {
  while (!Serial) {
    ;
  }
  Serial.begin(9600);
  Serial.write("Sketch begins.\r\n");
  Serial.flush();
  CircuitPlayground.begin();
  index = 0;
}

void loop() {
  if (Serial && Serial.available()) {
    color[index++] = Serial.read();
    if (index == 3) {
      for(int i=0; i<10; ++i) {
        CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.strip.Color(color[0], color[1], color[2]));
      }
      // Show all the pixels.
      CircuitPlayground.strip.show();
        
      Serial.print("Set LED to ");
      Serial.print(color[0]);
      Serial.print(", ");
      Serial.print(color[1]);
      Serial.print(", ");
      Serial.print(color[2]);
      Serial.print(".\r\n");
      Serial.flush();
      index = 0;
    }
  }
}
