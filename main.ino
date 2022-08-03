#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_LEDS 28

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);



void setup(){
  
  	pixels.begin();
  
  
}




void loop () {
  
  
  for(int i = 0; i < NUM_LEDS ; i++){
  	pixels.setPixelColor(i, pixels.Color(0, 100, 0));
    pixels.setPixelColor(i-3, pixels.Color(0, 0, 0));
    pixels.show();
    delay(100);
  }
  
  pixels.setPixelColor(25, pixels.Color(0, 0, 0));
  pixels.setPixelColor(26, pixels.Color(0, 0, 0));
  pixels.setPixelColor(27, pixels.Color(0, 0, 0));
  pixels.show();
  delay(100);
  
}


void loop () {
  
  int red = random(0, 255);
  int green = random(0, 255);
  int blue = random(0,255);
  
  
  for(int i = 0; i < NUM_LEDS ; i++){
  	pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show();
    delay(25);
  }
  
  
}