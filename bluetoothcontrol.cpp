#include "bluetooth_control.h"

// Bluetooth module connected to Serial
void BluetoothControl::begin() {
  Serial1.begin(9600); // Bluetooth communication at 9600 baud rate
}

bool BluetoothControl::isDataAvailable() {
  return Serial1.available() > 0;
}

char BluetoothControl::readCommand() {
  return Serial1.read();
}

void BluetoothControl::sendResponse(const char* response) {
  Serial1.println(response);
}
