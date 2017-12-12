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

SYSTEM_MODE(SEMI_AUTOMATIC);

bool currentPower = HIGH;
bool currentDirection = HIGH;
int b = 100; // brightness, max is 255

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.

    pinMode(PIXEL_PIN, OUTPUT);
    pinMode(powerPin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    digitalWrite(powerPin, HIGH);
    digitalWrite(directionPin, HIGH);
    
    WiFi.on();
    WiFi.setCredentials("Talkative Guest", "joeyalexander03");
    WiFi.setCredentials("jennyPhone19", "7s429xvvvoqgw");
    Particle.connect();

    pixel.begin();

    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(255,0,255));
    }

    pixel.show();

    Particle.function("setColor",setColor);
    Particle.function("swapDir", setDir);
    Particle.function("swapPwr", setPwr);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
}

int setColor(String command) {
  if (command == "red") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(255,0,0));
      pixel.show();
    }
    return 1;
  } else if (command == "green") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(0,255,0));
      pixel.show();
    }
    return 1;
  } else if (command == "blue") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(0,0,255));
      pixel.show();
    }
    return 1;
  } else if (command == "cyan") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(0,255,255));
      pixel.show();
    }
    return 1;
  } else if (command == "magenta") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(255,0,255));
      pixel.show();
    }
    return 1;
  } else if (command == "yellow") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(255,255,0));
      pixel.show();
    }
    return 1;
  } else if (command == "white") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(255,255,255));
      pixel.show();
    }
    return 1;
  } else if (command == "black") {
    for(int i = 0; i<PIXEL_COUNT; i++){
      pixel.setPixelColor(i, pixel.Color(0,0,0));
      pixel.show();
    }
    return 1;
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
