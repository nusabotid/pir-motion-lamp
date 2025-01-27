#include <WiFi.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const int pirPin = 12;
const int relayPin = 18;
const int redPin = 27;
const int greenPin = 26;
const int bluePin = 25;

void connect(){
    rgb(1,0,0);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    rgb(0,1,0);
}

void setup(){
    pinMode(pirPin, INPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    WiFi.begin(ssid, password);

    connect();
}

void loop(){
    bool statusPir = digitalRead(pirPin);

    digitalWrite(relayPin, statusPir);
}

void rgb(bool red, bool green, bool blue){
    digitalWrite(redPin, red);
    digitalWrite(greenPin, green);
    digitalWrite(bluePin, blue);
}