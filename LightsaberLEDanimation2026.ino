#include <FastLED.h>
#include <EEPROM.h>

#define LED_PIN     8
#define BRIGHTNESS  40
#define NUM_LEDS    64
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB


CRGB leds[NUM_LEDS];
int ledsPerFrame = 1;
int frameDelay = 40;
int frameDelay2 = 1;
int startLed = 0;
int endLed = 63;

float r = 255;
float g = 0;
float b = 0;


void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  unsigned int off[3] = { 0, 0, 0 };
  
  // LED animation setup
  for (int i = 0; i <= 31; i += ledsPerFrame) {
    leds[startLed + i] = CRGB(r, g, b);
    leds[endLed - i] = CRGB(r, g, b);
    FastLED.show();
    delay(frameDelay);
  }
}
void loop(){

}




