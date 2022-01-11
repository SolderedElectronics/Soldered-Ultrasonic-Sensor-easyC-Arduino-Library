/**
 **************************************************
 * @file        getDistance.ino
 * @brief       Example for getting distance
 *              from ultrasonic sensor for easyC sensors
 *
 *
 * @authors     Goran Juric@ soldered.com
 ***************************************************/

#include "Ultrasonic-distance-sensor-with-easyC-SOLDERED.h"

Ultrasonic_Sensor hc;
void setup()
{
  Serial.begin(115200);
  hc.begin();
}

void loop()
{
  Serial.println(hc.takeMeasure());
  delay(50);
  Serial.println(hc.getDistance());
  delay(1000);
}
