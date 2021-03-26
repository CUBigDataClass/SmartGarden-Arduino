#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define ENABLE_LIGHT_SENSOR false
#define LIGHT_PIN A0

#define ENABLE_EC_SENSOR false
#define EC_SENSOR_PIN A1


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Getting things set up..."));
  dht.begin();
}

void loop() {
  // DHT Sensor
  float humidity = dht.readHumidity();
  float air_temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(air_temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
  }else{
    Serial.print("humidity:");
    Serial.println(humidity);
    Serial.print("temperature:");
    Serial.println(air_temperature);
  }
  delay(1000);
  // Light Sensor (photo-resistor)
  if(ENABLE_LIGHT_SENSOR){
    int light_intensity = analogRead(LIGHT_PIN);
    Serial.print("light:");
    Serial.println(light_intensity);
    delay(1000);
  }
  // EC Sensor (measures dissolved solids)
  if(ENABLE_EC_SENSOR){
    int dissolved_solids = analogRead(EC_SENSOR_PIN);
    Serial.print("dissolved_solids:");
    Serial.println(dissolved_solids);
    delay(1000);
  }
  // Polling Delay
  delay(2000);
}
