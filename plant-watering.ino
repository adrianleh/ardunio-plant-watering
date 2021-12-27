#include <ESP8266WiFi.h>
#include <Wire.h>
#include <HCSR04.h>

int readDistance() {
  return 0;
}

int readMoisture() {
  return 0;
}

float waterLevel() {
  return 0.f;
}

bool decision(int dist, int moisture) {
  return false;
}

void runMotor(int time) {
  
}

const int delayBetweenMeasurements = 5 * 1000;
const int numberOfMeasurements = 60;
const float waterLevelThreshold = -1;

int currentMeasurement = 0;
int dist = 0;
int moisture = 0;

void resetMeasurement() {
  currentMeasurement = 0;
  dist = 0;
  moisture = 0;
}

void setup() {
  Serial.begin(9600);
  resetMeasurement();
}

void loop() {
  delay(delayBetweenMeasurements);
  currentMeasurement++;
  dist += readDistance();
  moisture += readMoisture();
  if (currentMeasurement < numberOfMeasurements) {
      return;
  }
  resetMeasurement();
  if (decision(dist, moisture)) {
    runMotor(1000);
  }

  if(waterLevel() < waterLevelThreshold) {
    // TODO: alert 
  }
}