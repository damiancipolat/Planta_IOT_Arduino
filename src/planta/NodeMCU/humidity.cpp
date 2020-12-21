#include <Arduino.h>

int getHumidity()
{
 return analogRead(A0);
}
