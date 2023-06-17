//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup() {
  while (!Serial)
    ;
  Serial.begin(9600);

  radio.setDataRate(RF24_2MBPS);  // Configura la velocidad de datos a 2 Mbps
  radio.setChannel(76);           // Configura el canal a 76

  radio.begin();

  //set the address
  radio.openReadingPipe(0, address);

  //Set module as receiver
  radio.startListening();
}

void loop() {
  //Read the data if available in buffer
  if (radio.available()) {
    Serial.print("Esperando info...");
    char text[32] = { 0 };
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}