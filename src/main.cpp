#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <LittleFS.h>
#include <ArduinoJson.h>
#include <Clock.h>

#define CREDENTIALS_FILE "/data/credentials.json"

char* ssid;
char* password;



void setup() {
  Serial.begin(9600);
  
  //start instance of the clock to be able to display something
  Clock clock;
  clock.setup();
  clock.setColor(0,255,0);



  Serial.println("Clock setup succesfully");
}

// the loop function runs over and over again forever
void loop() {

}
