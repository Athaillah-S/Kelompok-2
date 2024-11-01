#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "base64.h"

// Setup WiFi network
const char* ssid = "xxxxxxxxxxxx";
const char* password = "xxxxxxxxxx";

// read sensor
const int sensorPin = A0;
int speakerPin = D5;
int state = 0;

// Twilio Parameter
String account_sid = "Axxxxxxxxxxxxxxxxxxxxxxxxxx";
String auth_token = "8xxxxxxxxxxxxxxxxxxxxxxxxxx";
String from = "14xxxxxxxxx";
String to = "62xxxxxxxxxxxxxxx";
String body = "Pintu Ada Yang Buka";

void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  
  pinMode(sensorPin,INPUT);
  pinMode(speakerPin, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to WiFi");
 
}