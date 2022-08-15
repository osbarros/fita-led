#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_LEDS 28
#define botao 4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int estadoBotao = 0; // inicia com o valor de 0 no qual nenhum efeito é exibido
uint32_t selColor = pixels.Color(50, 205, 50);
uint32_t black = pixels.Color(0, 0, 0);
uint32_t white = pixels.Color(255, 255, 255);


void setup(){
  
  	pixels.begin();
    pinMode(botao, INPUT);
  	Serial.begin(9600);
  
}

void loop () {  
   
  
    switch(estadoBotao){
      	
        case 0: //estatico
              //Serial.print(digitalRead(botao) == HIGH);
              for(int i = 0; i < NUM_LEDS ; i++){
                  pixels.setPixelColor(i, selColor);
                  pixels.show();
                  alteraEfeito();
              }
              
              break;

        case 1: //scanner
           	scanner();
      		break;

        case 2: //strobe
            strobe(selColor, 10, 50, 1000);          
      		break;

        case 3: //cinema
           	cinema(50,205,50, 50);
      		break;
    }
}


void alteraEfeito() {
    
  if (digitalRead(botao) == HIGH && estadoBotao != 3) {
    	estadoBotao = estadoBotao + 1;
  } else if (digitalRead(botao) == HIGH && estadoBotao == 3){
       	estadoBotao = 0;
  }
  
}



void scanner() {
  
  
  for(int i = 0; i < NUM_LEDS ; i++){
  	pixels.setPixelColor(i, pixels.Color(0, 100, 0));
    pixels.setPixelColor(i-3, pixels.Color(0, 0, 0));
    pixels.show();
    delay(100);
    alteraEfeito();
  }
  
  	pixels.setPixelColor(25, pixels.Color(0, 0, 0));
 	pixels.setPixelColor(26, pixels.Color(0, 0, 0));
 	pixels.setPixelColor(27, pixels.Color(0, 0, 0));
  	pixels.show();
  	delay(100);
  	alteraEfeito();
  
}



void strobe(uint32_t selColor, int StrobeCount, int FlashDelay, int EndPause){
  for(int j = 0; j < StrobeCount; j++) {
  		pixels.fill(selColor, 0, NUM_LEDS);
    	pixels.show();
    	delay(FlashDelay);
    	alteraEfeito();
   
  		pixels.fill(black, 0, NUM_LEDS);
    	pixels.show();
    	delay(FlashDelay);
    	alteraEfeito();
  }
 
 delay(EndPause);
}



void cinema(byte red, byte green, byte blue, int SpeedDelay) {

  int Position=0;
 
  for(int j=0; j<NUM_LEDS*2; j++) {
  
      Position++; 
      for(int i=0; i<NUM_LEDS; i++) {
        pixels.setPixelColor(i,((sin(i+Position) * 127 + 128)/255)*red,
                   ((sin(i+Position) * 127 + 128)/255)*green,
                   ((sin(i+Position) * 127 + 128)/255)*blue);
        alteraEfeito();
      }
     
      pixels.show();
      delay(SpeedDelay);
      alteraEfeito();
  }
}

  