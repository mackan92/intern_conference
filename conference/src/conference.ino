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
#define powerPin 6
#define directionPin 5
bool currentPower = HIGH;
bool currentDirection = HIGH;

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.

    pinMode(PIXEL_PIN, OUTPUT);
    pinMode(powerPin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    digitalWrite(powerPin, HIGH);
    digitalWrite(directionPin, HIGH);


    Particle.function("LED",toggle);
    Particle.function("swapDir", setDir);
    Particle.function("swapPwr", setPwr);

    pixel.begin();

    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(100,0,255));
    }

    pixel.show();

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
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

int setDir(String command) {
  currentDirection = !currentDirection;
  digitalWrite(directionPin, currentDirection);
  return 1;
}
int setPwr(String command) {
  currentPower = !currentPower;
  digitalWrite(powerPin, currentPower);
  return 1;
}
