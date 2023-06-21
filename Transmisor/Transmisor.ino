/* NRF24L01  ARDUINO UNO
1: GND        pin GND
2: VCC        pin 3v3
3: CE         pin 9
4: CSN        pin 10
5: SCK        pin 13
6: MOSI       pin 11
7: MISO       pin 12
*/

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

int ledTX = 5;
const int pinCE = 9;
const int pinCSN = 10;

RF24 radio(pinCE, pinCSN);

byte direccion[5] = { 'j', 'h', 'o', 'a', 'n' };
int datos[16];

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(100);
  // radio.stopListening();
  radio.openWritingPipe(direccion);
  pinMode(ledTX, OUTPUT);
}

void loop(void) {
  datos[0] = 2;
  radio.write(datos, sizeof(datos));
  delay(500);
  digitalWrite(ledTX, HIGH);
  delay(500);
  digitalWrite(ledTX, LOW);
  delay(500);
}