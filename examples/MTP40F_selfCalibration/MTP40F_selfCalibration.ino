//
//    FILE: MTP40F_selfCalibration.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo of MTP40F library
//     URL: https://github.com/RobTillaart/MTP40F
//
//  any board that support two or more hardware serial ports
//  Serial and Serial1, e.g. for MEGA, LEONARDO, MICRO, ESP32,ESP8266
//  Uno, Nano or Mini will fail to compile.


#include "MTP40F.h"
#include "SoftwareSerial.h"

SoftwareSerial sws(6, 7);
MTP40F mtp(&sws);
// MTP40F mtp(&Serial1);

uint32_t start;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  Serial.print("MTP40F_LIB_VERSION:\t");
  Serial.println(MTP40F_LIB_VERSION);

  sws.begin(19200);
  mtp.begin();

  Serial.print("STAT:\t");
  Serial.println(mtp.getSelfCalibrationStatus());
  delay(100);
  Serial.print("OPEN:\t");
  Serial.println(mtp.openSelfCalibration());
  delay(100);
  Serial.print("STAT:\t");
  Serial.println(mtp.getSelfCalibrationStatus());
  delay(100);
  Serial.print("CLOSE:\t");
  Serial.println(mtp.closeSelfCalibration());
  delay(100);
  Serial.print("STAT:\t");
  Serial.println(mtp.getSelfCalibrationStatus());
  delay(100);
  Serial.print("OPEN:\t");
  Serial.println(mtp.openSelfCalibration());
  delay(100);
  Serial.print("STAT:\t");
  Serial.println(mtp.getSelfCalibrationStatus());
  delay(100);

  Serial.println();

  Serial.print("GET_HRS:\t");
  uint16_t hrs = mtp.getSelfCalibrationHours();
  Serial.println(hrs);
  delay(100);

  if (hrs > 720) hrs = 23;
  Serial.print("SET_HRS:\t");
  Serial.println(mtp.setSelfCalibrationHours(hrs + 1));
  delay(100);
  Serial.print("GET_HRS:\t");
  Serial.println(mtp.getSelfCalibrationHours());
  delay(100);

  Serial.println("\ndone...");
}


void loop()
{
}


// -- END OF FILE --
