/*
 * Project conference
 * Description:
 * Author:
 * Date:
 */

#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN A1
#define PIXEL_COUNT 64
#define PIXEL_TYPE WS2812B

#define stepPin 3
#define dirPin 4

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.

    pinMode(PIXEL_PIN, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

    Particle.function("LED",toggle);

    pixel.begin();

    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(100,0,255));
    }

    pixel.show();

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(7000);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(7000);
  }
}

int toggle(String command) {

  if (command=="on") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(100,100,255));
    }

    pixel.show();
    return 1;
  } else if (command=="off") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(0,255,0));
    }
    pixel.show();
    return 0;
  } else {
    return -1;
  }
}
