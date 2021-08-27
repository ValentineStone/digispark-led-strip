#include <Arduino.h>
#include "FastLED.h"
#define NUM_LEDS 13
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<NEOPIXEL, PB0>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++)
    leds[i] = CRGB::Red;
  FastLED.show();
}

void loop() {
  int every = 15 * 000;

  for (int n = 0; n < 20; n++) { // n * 1040
    for (int k = 0; k < NUM_LEDS; k++) {
      for (int i = 0; i < NUM_LEDS; i++)
        leds[i] = CRGB::Black;
      leds[k] = CRGB::Red;
      leds[(k + NUM_LEDS / 2) % NUM_LEDS] = CRGB::Red;
      FastLED.show();
      delay(80);
    }
  }

  for (int n = 0; n < 27; n++) { // n * 768
    for (int k = 0; k < 256; k++) {
      for (int i = 0; i < NUM_LEDS; i++)
        leds[i].setRGB(k, 0,0);
      FastLED.show();
      delay(1);
    }
    for (int k = 255; k >= 0; k--) {
      for (int i = 0; i < NUM_LEDS; i++)
        leds[i].setRGB(k, 0,0);
      FastLED.show();
      delay(2);
    }
  }

  for (int k = 0; k < 256; k++) {
    for (int i = 0; i < NUM_LEDS; i++)
      leds[i].setRGB(k, 0,0);
    FastLED.show();
    delay(1);
  }

  for (int i = 0; i < NUM_LEDS; i++)
    leds[i] = CRGB::Red;
  FastLED.show();
  delay(1040 * 20);

  for (int k = 255; k >= 0; k--) {
    for (int i = 0; i < NUM_LEDS; i++)
      leds[i].setRGB(k, 0,0);
    FastLED.show();
    delay(1);
  }
}