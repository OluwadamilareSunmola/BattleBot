#include <Arduino.h>
#include "motor_control.h"
#include "sensors.h"
#include "bluetooth_control.h"

// Define Bluetooth serial
BluetoothControl btControl;

void setup() {
  // Initialize motors and Bluetooth communication
  Serial.begin(9600);
  btControl.begin();
  initMotors(); // Initialize motor driver pins
  initSensors(); // Initialize sensor pins
}

void loop() {
  // Continuously check for Bluetooth commands and process them
  if (btControl.isDataAvailable()) {
    char command = btControl.readCommand();
    processCommand(command);  // Process the command received via Bluetooth
  }

  // Optional: Add additional robot behavior like obstacle detection or following a line
  int distance = readUltrasonic();  // Get the distance from the ultrasonic sensor
  if (distance < 10) {
    stopMotors(); // Stop if an obstacle is detected within 10cm
  }
}
