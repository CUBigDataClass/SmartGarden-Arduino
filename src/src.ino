#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

#define LIGHTPIN A0


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  }else{
    Serial.print("humidity:");
    Serial.println(h);
    Serial.print("temperature:");
    Serial.println(t);
  }

  delay(1000);

  int light_intensity = analogRead(LIGHTPIN);
  Serial.print("light:");
  Serial.println(light_intensity);

  delay(4000);
}
