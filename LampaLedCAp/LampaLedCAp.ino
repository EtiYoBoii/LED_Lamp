#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define OUT1 2                    // Pin pentru prima iesire a senzorului capacitiv
#define OUT2 3                    // Pin pentru a doua iesire a senzorului capacitiv
#define OUT3 4                 // Pin pentru a treia iesire a senzorului capacitiv
#define OUT4 5                    // Pin pentru a patra iesire a senzorului capacitiv
#define TEMPERATURE_SENSOR_PIN 8  // Pin digital pentru senzorul de temperatură (18B20)
#define PIR 10                     // Pin pentru senzorul de mișcare PIR (schimbă la nevoie)
#define LAMP 9                    // Pin pentru controlul lămpii


OneWire oneWire(TEMPERATURE_SENSOR_PIN);
DallasTemperature sensors(&oneWire);


int brightnessLevels[] = { 0, 10, 64, 128, 255 };  // Nivelele de luminozitate
int currentBrightness = 0;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(OUT1, INPUT);
  pinMode(OUT2, INPUT);
  pinMode(OUT3, INPUT);
  pinMode(OUT4, INPUT);
  pinMode(LAMP, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int temperature = getTemperature();
  volatile bool motionDetected = digitalRead(PIR);

  if (temperature >= 80 || !motionDetected) {
    currentBrightness = 0;  // Luminozitate minimă dacă temperatura depășește 80 de grade sau nu se detectează mișcare
  } else {
    if (digitalRead(OUT1) == HIGH) {
      currentBrightness = 1;
    } else if (digitalRead(OUT2) == HIGH) {
      currentBrightness = 2;
    } else if (digitalRead(OUT3) == HIGH) {
      currentBrightness = 3;
    } else if (digitalRead(OUT4) == HIGH) {
      currentBrightness = 4;  // Luminozitate maximă dacă este detectată mișcare și niciun alt senzor capacitiv nu este activ
    } 
    }
  analogWrite(LAMP, brightnessLevels[currentBrightness]);

  delay(500);  // Ajustează dacă este nevoie
}


float getTemperature() {
  // Solicită temperaturile de la senzorul DS18B20
  sensors.requestTemperatures();

  // Citire temperatura în grade Celsius
  float temperature = sensors.getTempCByIndex(0);

  // Verificare dacă citirea temperaturii este validă
  if (temperature == DEVICE_DISCONNECTED_C) {
    Serial.println("Eroare: Senzorul de temperatură nu este conectat corect sau este defect.");
    return -127; // Valoare de eroare pentru temperatură
  }

  return temperature;
}
