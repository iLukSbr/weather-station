#include <Arduino.h>
#include "GPSHandler.h"

GPSHandler::GPSHandler(int rxPin, int txPin) : gpsSerial(rxPin, txPin) {}

void GPSHandler::begin() {
  Serial.begin(GPS_Serial_Baud);
  gpsSerial.begin(GPS_Serial_Baud);
}

bool GPSHandler::newDataAvailable() {
  bool newData = false;
  unsigned long chars;

  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (gpsSerial.available()) {
      char c = gpsSerial.read();
      if (gps.encode(c))
        newData = true;
    }
  }

  return newData;
}

void GPSHandler::printGPSData() {
  float flat, flon;
  unsigned long age;

  gps.f_get_position(&flat, &flon, &age);

  Serial.print("LAT=");
  Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
  Serial.print(" LON=");
  Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
  Serial.print(" SAT=");
  Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
  Serial.print(" PREC=");
  Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
  Serial.println();
  Serial.println();
}