#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

// Zdefiniowanie pinu A0 dla bezpośredniego pomiaru wilgotności
const int pinGleby = A0; 

void setup(void) {
  Serial.begin(115200);
  while (!Serial) {
      delay(1);
  }

  Serial.println("Rozpoczynam inicjalizację INA219...");

  if (!ina219.begin()) {
    Serial.println("Błąd: Nie znaleziono układu INA219! Sprawdź kable SDA/SCL.");
    while (1) { delay(10); } 
  }

  Serial.println("Czujnik INA219 gotowy!");
  Serial.println("-----------------------------------");
}

void loop(void) {
  // 1. Odczyt napięcia z pinu Vin- względem GND (z INA219)
  float busvoltage = ina219.getBusVoltage_V();

  // 2. Bezpośredni odczyt z pinu A0 Arduino (z czujnika gleby)
  int wilgotnoscSurowa = analogRead(pinGleby);

  // Wypisywanie wyników w jednej linii
  Serial.print("Napięcie [INA219]: ");
  Serial.print(busvoltage);
  Serial.print(" V  |  Wilgotność [A0]: ");
  Serial.println(wilgotnoscSurowa);

  delay(2000);
}
