#include <Arduino.h>

void led_alarm(int pin)
{
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  delay(100);
}

void led_standby(int pin)
{
  delay(2500);
  digitalWrite(pin,HIGH);
  delay(100);
  digitalWrite(pin,LOW);
}
