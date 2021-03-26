#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

#define ENABLELIGHTSENSOR false
#define LIGHTPIN A0

#define ENABLEECSENSOR false
#define ECSENSORPIN A1


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

  if(ENABLELIGHTSENSOR){
    int light_intensity = analogRead(LIGHTPIN);
    Serial.print("light:");
    Serial.println(light_intensity);
    delay(1000);
  }



  if(ENABLELIGHTSENSOR){
    int dissolved_solids = analogRead(ECSENSORPIN);
    Serial.print("dissolved_solids:");
    Serial.println(dissolved_solids);
    delay(1000);
  }


  delay(2000);
}
