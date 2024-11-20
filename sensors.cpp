#include "sensors.h"

// Define sensor pins
const int ultrasonicTriggerPin = 7;
const int ultrasonicEchoPin = 8;

void initSensors() {
  pinMode(ultrasonicTriggerPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
}

int readUltrasonic() {
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(ultrasonicTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicTriggerPin, LOW);

  // Measure the duration of the echo
  long duration = pulseIn(ultrasonicEchoPin, HIGH);

  // Calculate distance in cm
  int distance = duration * 0.034 / 2;
  return distance;
}
