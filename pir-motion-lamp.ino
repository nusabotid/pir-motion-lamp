const int pirPin = 12;
const int relayPin = 18;

void setup(){
    pinMode(pirPin, INPUT);

    Serial.begin(9600);
}

void loop(){
    bool statusPir = digitalRead(pirPin);
    Serial.println(statusPir);
}