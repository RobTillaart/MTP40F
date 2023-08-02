//
//    FILE: MTP40F_getCO2.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo of MTP40C library
//     URL: https://github.com/RobTillaart/MTP40F
//
//  any board that support two or more hardware serial ports
//  Serial and Serial1, e.g. for MEGA, LEONARDO, MICRO, ESP32, ESP8266
//  Uno, Nano or Mini will fail to compile.

//  SCHEMA example SoftwareSerial sws(7, 6);
//              UNO                     MTP40F
//        +---------------+        +---------------+
//        |               |        |               |
//        |          +5V  |--------| 1 VIN         |
//        |          GND  |--------| 2 GND         |
//        |               |        | 3             |
//        |               |        | 4             |
//        |               |        |               |
//        |               |        | 5             |
//        |         RX 6  |--------| 6 TX          |
//        |         TX 7  |--------| 7 RX          |
//        |               |        | 8             |
//        |               |        | 9             |
//        |               |        |               |
//        +---------------+        +---------------+
//


#include "MTP40F.h"
#include "SoftwareSerial.h"

//  SoftwareSerial sws(7, 6);

// MTP40F mtp(&sws);
MTP40F mtp(&Serial1);  // MEGA, ESP32

int lines = 10;


void setup()
{
  Serial.begin(115200);
  // Serial.println(__FILE__);
  // Serial.print("MTP40_LIB_VERSION:\t");
  // Serial.println(MTP40_LIB_VERSION);

  //  sws.begin(9600);
  Serial1.begin(9600);
  mtp.begin();

  // if (mtp.begin() == false)
  // {
  //   Serial.println("could not connect!");
  //   while(1);
  // }

}


void loop()
{
  if (lines == 10)
  {
    lines = 0;
    Serial.println("\nTIME\tCO2 LEVEL");
  }

  if (millis() - mtp.lastRead() >= 5000)
  {
    Serial.print(millis());
    Serial.print("\t");
    Serial.print(mtp.getGasConcentration());
    Serial.println();
    lines++;
  }
}


//  -- END OF FILE --
