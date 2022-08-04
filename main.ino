#define PIN 2
#define NUM_LEDS 28

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

uint32_t selColor = 0x32CD32;;
uint32_t black = pixels.Color(0, 0, 0);
uint32_t white = pixels.Color(255, 255, 255);

void setup(){
  
  	pixels.begin();
  	pixels.setBrightness(200);
  	pixels.fill(selColor, 0, NUM_LEDS);
  
  
}

void loop(){
  	strobe(selColor, 10, 50, 1000);
}

void scanner () {
  
  
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

void strobe(uint32_t selColor, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
  		pixels.fill(white, 0, NUM_LEDS);
    	pixels.show();
    	delay(FlashDelay);
   
  		pixels.fill(black, 0, NUM_LEDS);
    	pixels.show();
    	delay(FlashDelay);
    
  }
 
 delay(EndPause);
}      
  