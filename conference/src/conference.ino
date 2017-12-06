/*
 * Project conference
 * Description:
 * Author:
 * Date:
 */

#include <neopixel.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define PIXEL_PIN A1
#define PIXEL_COUNT 48
#define PIXEL_TYPE WS2812B

#define PIN 6

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, PIN,
NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(255, 255, 255) };




// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.

    pinMode(PIXEL_PIN, OUTPUT);

    Particle.function("LED",toggle);

    pixel.begin();

    matrix.begin();
    matrix.setTextWrap(false);
    matrix.setBrightness(40);
    matrix.setTextColor(colors[0]);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F(“HI, RYAN.  THIS IS A NEOPIXEL BOARD”));
  if(–x < -220) {
  x = matrix.width();
  if(++pass >= 3) pass = 0;
  matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(100);
}

int toggle(String command) {

  if (command=="on") {
    for(int i = 0; i<48; i++){
      pixel.setPixelColor(i, pixel.Color(100,100,255));
    }

    pixel.show();
    return 1;
  } else if (command=="off") {
    for(int i = 0; i<48; i++){
      pixel.setPixelColor(i, pixel.Color(0,255,0));
    }
    pixel.show();
    return 0;
  } else {
    return -1;
  }
}
