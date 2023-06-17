//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup() {

  radio.setDataRate(RF24_2MBPS);  // Configura la velocidad de datos a 2 Mbps
  radio.setChannel(76);           // Configura el canal a 76
  radio.begin();

  //set the address
  radio.openWritingPipe(address);

  //Set module as transmitter
  radio.stopListening();
}
void loop() {
  //Send message to receiver
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));

  delay(1000);
}