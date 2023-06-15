#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

void setup() {
	Serial.begin(9600);

	if (!bme.begin(0x76)) {
		Serial.println("No se ha podido encontrar un sensor BME280, compruebe el cableado!");
		while (1);
	}
}

void loop() {
	Serial.print("Temperatura = ");
	Serial.print(bme.readTemperature());
	Serial.println("*C");

	Serial.print("Presion = ");
	Serial.print(bme.readPressure() / 100.0F);
	Serial.println("hPa");

	Serial.print("Aprox. Altitud = ");
	Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
	Serial.println("m");

	Serial.print("Humedad = ");
	Serial.print(bme.readHumidity());
	Serial.println("%");

	Serial.println();
	delay(1000);
}