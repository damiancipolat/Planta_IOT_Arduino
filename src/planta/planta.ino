#include "config.h"
#include "temp.h"
#include "humidity.h"
#include "ui.h"
#include "led.h"

int LED_RED=16;
String state;
int temperature;
int humidity;
bool connected=false;

//Create temperature feed - adafruit.io.
AdafruitIO_Feed *humidity_feed = io.feed("iot_humidity");

//Create humidity feed - adafruit.io.
AdafruitIO_Feed *temperature_feed = io.feed("iot_temperature");

void setup(){
  Serial.begin(9600);

  //Set pin modes.
  pinMode(LED_RED,OUTPUT);
  
  //Start display.
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
  return (humidity>=500&&humidity<=700);
}

bool waterRequired(){
  return (humidity>700);
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

//Connect wifi.
int connect_wifi(){

  if (connected==true)
    return 0;

  // wait for serial monitor to open
  while(!Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED){
    draw_wait();
    led_on(LED_RED);
    delay(500);
    Serial.println("Wait...");
    led_off(LED_RED);
    delay(500);
  }

  connected=true;
  
  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  
  return 1;
   
}

//Send values to adafruit.
void send_adafruit_values(){
  draw_sending();
  Serial.print("Sending values to adafruit, T:"+(String)temperature+" H:"+(String)humidity);
  humidity_feed->save(humidity);
  temperature_feed->save(temperature);
}

void loop(){

  //Welcome state.
  if (state=="W"){
    draw_welcome();
    delay(500);
    state="WIFI";
  }

  //Connect wifi.
  if (state=="WIFI"){
    draw_connection();
    connect_wifi();
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
    state="S";
  }

  //Send adafruit values.
  if (state=="S"){
    send_adafruit_values();
    delay(500);
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
