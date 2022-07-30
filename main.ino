//PROJETO TRAINEE TESLA UFMG 2022

#include <FastLED.h> //pq ta dando erro?

#define NUM_LEDS  300
#define LED_PIN   2

CRGB leds[NUM_LEDS];


void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100); //0 a 255
}

void loop(){

}

void solidColor(){

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(34, 20, 43);
  }
  
  FastLED.show();

}

void icyGreen(){

  EVERY_N_MILLISECONDS(50) { //velocidade do movimento
    
    // Create a new HSV color for led[0]
    leds[0] = CHSV(277, random8(), random8(100, 255));
    
    // Copy each pixel to the next one, starting at the far end
    // thereby 'moving' the pattern along the strip
    for (int i = NUM_LEDS - 1; i > 0; i--) {
      leds[i] = leds[i - 1];
    }
  }
  
  FastLED.show();
}