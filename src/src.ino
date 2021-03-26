// DHT Confit
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
// Light Sensor Config
#define ENABLE_LIGHT_SENSOR false
#define LIGHT_PIN A0
// EC Sensor Config
#define ENABLE_EC_SENSOR false
#define EC_SENSOR_PIN A1
// Float Sensor Config
#define FLOAT_SENSOR_PIN 3
// DH18B20 Temperature Probe Config
#include <OneWire.h>
#include <DallasTemperature.h>
#define TEMP_PROBE_PIN 4
OneWire oneWire(TEMP_PROBE_PIN);
DallasTemperature sensors(&oneWire);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("Getting things set up..."));
  dht.begin();
  pinMode(FLOAT_SENSOR_PIN, INPUT_PULLUP);
}

float humidity;
float air_temperature;
int light_intensity;
int dissolved_solids;
int float_switch;
int water_temperature;

void loop() {
  // DHT Sensor
  humidity = dht.readHumidity();
  air_temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(air_temperature)) {
    Serial.println(F("Error reading from DHT sensor"));
  }else{
    Serial.print("humidity:");
    Serial.println(humidity);
    Serial.print("temperature:");
    Serial.println(air_temperature);
  }
  delay(1000);
  // Light Sensor (photo-resistor)
  if(ENABLE_LIGHT_SENSOR){
    light_intensity = analogRead(LIGHT_PIN);
    Serial.print("light:");
    Serial.println(light_intensity);
    delay(1000);
  }
  // EC Sensor (measures dissolved solids)
  if(ENABLE_EC_SENSOR){
    dissolved_solids = analogRead(EC_SENSOR_PIN);
    Serial.print("dissolved solids:");
    Serial.println(dissolved_solids);
    delay(1000);
  }
  // Float Switch
  float_switch = digitalRead(FLOAT_SENSOR_PIN);
  Serial.print("float sensor:");
  Serial.println(float_switch);
  // DS18B20 temperature probe
  sensors.requestTemperatures();
  water_temperature = sensors.getTempCByIndex(0);
  if(water_temperature < -100){ // If not connected, probe reads -127 C
    Serial.println("Error reading from DS18B20 temperature probe");
  }else{
    Serial.print("water temperature:");
    Serial.println(water_temperature);
  }
  // Polling Delay
  delay(2000);
}
