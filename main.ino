#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_LEDS 28

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int estadoBotao = 0; // inicia com o valor de 0 no qual nenhum efeito é exibido

void setup(){
  
  	pixels.begin();
    pinMode(1, INPUT);
  
}

void loop () {  
    
    if (digitalRead(1) == HIGH && estadoBotao != 3) 
        estadoBotao++;

    else if (digitalRead(1) == HIGH && estadoBotao == 3)
        estadoBotao = 0;
    

    switch(estadoBotao){

        case 0: //Acende luz branca
            for(int i = 0; i < NUM_LEDS ; i++){
  	            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
                pixels.show();
            }

        case 1: //feixe de luz
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

        case 2: // Acende luz verde
            for(int i = 0; i < NUM_LEDS ; i++){
  	            pixels.setPixelColor(i, pixels.Color(100, 0, 0));
                pixels.show();
                delay(100);
            }

        case 3: // Acende luz vernelha
            for(int i = 0; i < NUM_LEDS ; i++){
  	            pixels.setPixelColor(i, pixels.Color(0, 110, 0));
                pixels.show();
                delay(100);
            }
    }
}
  