#include <Arduino.h>
#include "temp.h"
#include <OneWire.h>
#include <DallasTemperature.h>
 
const int oneWirePin = 8; 
OneWire oneWireBus(oneWirePin);
DallasTemperature sensor(&oneWireBus);

float getTemperature()
{
  //Read temperature.
  sensor.requestTemperatures();
  return sensor.getTempCByIndex(0);
}
