#include "temp.h"
#include "humidity.h"
#include "ui.h"
#include "led.h"

int LED_RED =5;
int LED_YELLOW =16;
String state;
int temperature;
int humidity;

void setup(){
  Serial.begin(9600);
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_YELLOW,OUTPUT);  
  display_start();
  state="W";
}

//Alarm condition.
bool isAlarm(){  
  return (isTemperatureAlarm()||isHumidityAlarm()||waterRequired());
}

//Control flow.
String control_values(){
  if (isAlarm())
    return "A";
  else
    return "W";
}

//Temperatura alarm.
bool isTemperatureAlarm(){
  return (temperature>=30);
}

bool isHumidityAlarm(){
  return (humidity>0&&humidity<200);
}

bool waterRequired(){
  return (humidity>800);
}

//Alarm state.
String alarm(){

  //Check temperature excess.
  if (isTemperatureAlarm())
    return "ET";

  //Check humidity excess.
  if (isHumidityAlarm())
    return "EW";

  //Check watering plant.
  if (waterRequired())
    return "WP";    

}

//Read the sensor values.
void read_sensor_values(){
  temperature = getTemperature();
  Serial.println("Sensor TEMPERATURE------->"+(String)temperature);    
  humidity = getHumidity();
  Serial.println("Sensor HUMIDITY------->"+(String)humidity);  
}

void loop(){

  //Welcome state.
  if (state=="W"){
    draw_welcome();
    delay(500);
    state="T";
  }

  //Temperature scan
  if (state=="T"){
    read_sensor_values();
    draw_temperature_box(temperature);    
    led_standby(LED_RED);
    delay(250);
    state="H";
  }

  //Humidity scan
  if (state=="H"){
    read_sensor_values();
    draw_humidity_box(humidity);      
    led_standby(LED_RED);
    delay(250);    
    state="C";
  }

  //Value control.
  if (state=="C"){
    //Read values.
    read_sensor_values();
    //Analize conditions.
    state = control_values();
  }

  //Alarm state.
  if (state=="A"){
    //Show warning.
    draw_warning();
    delay(500);
    state = alarm();
  }

  //WATER excess.
  if (state=="EW"){
    //Show message.
    draw_alarm("Exceso","agua!");
    delay(1500);
    state="R";
  }
  
  //TEMPERATURE excess.
  if (state=="ET"){
    //Blink led.
    led_alarm(LED_RED);    
    //Show message.
    draw_alarm("Exceso","temp.!");
    delay(1500);
    state="R";
  }

  //WATER required!
  if (state=="WP"){
    //Show message.
    draw_alarm("Regar","planta");
    delay(1500);
    state="R";    
  }

  //Return state.
  if (state=="R"){
    state="C";
  }

}
