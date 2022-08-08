#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_LEDS 28
#define botao 4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int estadoBotao = 0; // inicia com o valor de 0 no qual nenhum efeito é exibido

void setup(){
  
  	pixels.begin();
    pinMode(botao, INPUT);
  	Serial.begin(9600);
  
}

void loop () {  
   
      
    switch(estadoBotao){

        case 0: //Acende luz azul
      		//Serial.print(digitalRead(botao) == HIGH);
            for(int i = 0; i < NUM_LEDS ; i++){
  	        	pixels.setPixelColor(i, pixels.Color(0, 0, 100));
              	pixels.show();
				delay(100);
              	alteraEfeito();
            }
      		break;

        case 1: // Acende luz verde
      		//Serial.print(digitalRead(botao) == HIGH);
            for(int i = 0; i < NUM_LEDS ; i++){
  	            pixels.setPixelColor(i, pixels.Color(100, 0, 0));
                pixels.show();
                delay(100);
                alteraEfeito();
            }             
      		break;

        case 2: // Acende luz vernelha
  
            for(int i = 0; i < NUM_LEDS ; i++){
  	            pixels.setPixelColor(i, pixels.Color(0, 110, 0));
                pixels.show();
                delay(100);
              	alteraEfeito();
            }
      		break;
    }
}


void alteraEfeito() {
    
	if (digitalRead(botao) == HIGH && estadoBotao != 2) 
    	estadoBotao++;

   	else if (digitalRead(botao) == HIGH && estadoBotao == 2)
       	estadoBotao = 0;
    
}
  