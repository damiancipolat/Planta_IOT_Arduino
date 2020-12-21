#include "temp.h"
#include "humidity.h"
#define LED_BUILTIN 5
#define LED_BUILTIN2 16

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN2, OUTPUT);
}

void loop() {
  float temp = getTemperature();
  int humidity = getHumidity();
  
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_BUILTIN2, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN2, HIGH);
  delay(2000);
  Serial.println("Temperature:"+(String)temp);
  Serial.println("Humidity:"+(String)humidity);

}
