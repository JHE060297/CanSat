#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);

byte direccion[5] = {'j', 'h', 'o', 'a', 'n'};

int datos[16];
int led = 5;

void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(100);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, direccion);

  radio.startListening();
  pinMode(led, OUTPUT);
}

void loop(void){
  if(radio.available()){
    radio.read(datos, sizeof datos);
    Serial.print("Dato recibido: ");
    Serial.println( datos[0]);
    if(datos[0] == 2){
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }else{
      digitalWrite(led, LOW);
    }
  }else{
    Serial.println("No hay datos de TX");
  }
}