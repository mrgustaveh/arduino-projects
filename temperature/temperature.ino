#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  for(int pin = 4; pin < 7; pin++){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  dht.begin();
}

void loop() {
  delay(2500);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if(isnan(humidity) || isnan(temperature)){
    Serial.println("failed to read DHT sensor values");
  }else {
    Serial.println("Humidity: ");
    Serial.print(humidity);
    
    Serial.println("Temperature: ");
    Serial.print(temperature);

    if(temperature <= 35.0){
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
    } else if(temperature > 35.0 || temperature < 36.0){
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
    } else {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }

    delay(1);
  }
}


