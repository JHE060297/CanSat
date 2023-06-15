#include <DHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define DHT_PIN 2
#define DHT_TYPE DHT22

#define SEALEVELPRESSURE_HPA (1013.25)

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_BME280 bme;


void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!bme.begin(0x76)) {
    Serial.println("No se ha podido encontrar un sensor BME280, compruebe el cableado!");
    while (1)
      ;
  }
}

void loop() {
  Serial.print("TemperaturaBME= ");
  Serial.print(bme.readTemperature());
  Serial.print(", Presion= ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.print(", Altitud= ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.print(", HumedadBME= ");
  Serial.print(bme.readHumidity());
  Serial.print(", TemperaturaDHT= ");
  Serial.print(dht.readTemperature());
  Serial.print(", HumedadDHT= ");
  Serial.println(dht.readHumidity());

  delay(1000);
}