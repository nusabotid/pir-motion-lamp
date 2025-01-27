#include <WiFi.h>
#include <MQTT.h>
#include <NusabotSimpleTimer.h>

WiFiClient net;
MQTTClient client;
NusabotSimpleTimer timer;

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const int pirPin = 12;
const int relayPin = 18;
const int redPin = 27;
const int greenPin = 26;
const int bluePin = 25;

bool statusPir;

void connect(){
    rgb(1,0,0);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }
    rgb(0,1,0);

    while (!client.connect("clientidrandom")){
        delay(500);
    }
    rgb(0,0,1);
    
}

void publish(){
    client.publish("nusabot/pir", String(statusPir), true, 1);
}

void setup(){
    pinMode(pirPin, INPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    WiFi.begin(ssid, password);
    client.begin("broker.emqx.io", net);
    timer.setInterval(1000, publish);

    connect();
}

void loop(){
    timer.run();
    if(!client.connected()){
        connect();
    }

    statusPir = digitalRead(pirPin);

    digitalWrite(relayPin, statusPir);
}

void rgb(bool red, bool green, bool blue){
    digitalWrite(redPin, red);
    digitalWrite(greenPin, green);
    digitalWrite(bluePin, blue);
}