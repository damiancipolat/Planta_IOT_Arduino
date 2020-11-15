#include <Arduino.h>

void led_alarm(int pin)
{
  digitalWrite(pin,HIGH);
  delay(250);
  digitalWrite(pin,LOW);
  delay(250);
}

void led_standby(int pin)
{
  delay(2500);
  digitalWrite(pin,HIGH);
  delay(100);
  digitalWrite(pin,LOW);
}
