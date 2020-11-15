#include "temp.h"
#include "humidity.h"
#include "ui.h"
#include "led.h"

int LED_1 =9;
String state;
int temperature;
int humidity;

void setup(){
  Serial.begin(9600);
  pinMode(LED_1,OUTPUT);  
  display_start();
  state="W";
}

//Alarm condition.
bool isAlarm(){  
  return (temperature>20);
}

//Control flow.
void control_values(){
  if (isAlarm())
    return "A";
  else
    return "W";
}

//Alarm state.
String alarm(){

  //Check temperature excess.
  if (temperature>20)
    return "ET";

  //Check humidity excess.
  if (humidity>0&&humidity<200)
    return "EW"; 

}

void loop(){

  //Welcome state.
  if (state=="W"){
    draw_welcome();
    delay(2000);
    state="T";
  }

  //Temperature scan
  if (state=="T"){
    temperature = getTemperature();
    draw_temperature_box(temperature);      
    led_standby(LED_1);
    delay(1000);
    state="H";
  }

  //Humidity scan
  if (state=="H"){
    humidity = getHumidity();
    draw_humidity_box(humidity);      
    led_standby(LED_1);
    delay(1000);    
    state="C";
  }

  //Value control.
  if (state=="C"){
    state = control_values();
  }

  //Alarm state.
  if (state=="A"){
    state = alarm();
  }

  //WATER excess.
  if (state=="EW"){
    //Show warning.
    draw_warning();
    delay(1000);

    //Show message.
    draw_alarm("Exceso","agua!");
    delay(1000);
    state="R";
  }
  
  //TEMPERATURE excess.
  if (state=="ET"){
    //Show warning.
    draw_warning();
    delay(1000);

    //Show message.
    draw_alarm("Exceso","temp.!");
    delay(1000);
    state="R";    
  }

  //WATER required!
  if (state=="WP"){
    //Show warning.
    draw_warning();
    delay(1000);

    //Show message.
    draw_alarm("Regar","planta");
    delay(1000);
    state="R";    
  }

  //Return state.
  if (state=="R"){
    state="W";
  }

}
