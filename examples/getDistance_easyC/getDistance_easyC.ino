/**
 **************************************************
 * @file        getDistance.ino
 * @brief       Example for getting distance
 *              from ultrasonic sensor for easyC sensors
 *
 * product: www.solde.red/333001
 * @authors     Goran Juric@ soldered.com
 ***************************************************/

#include "Ultrasonic-distance-sensor-easyC-SOLDERED.h"

Ultrasonic_Sensor hc; //Initializer for sensor with easyC

void setup()
{
  Serial.begin(115200);  //Start serial communication with PC via UART
  hc.begin();  //Initialize sensor
}

void loop()
{
  hc.takeMeasure();                             //Send command sensor to take measure
  delay(50);                                    //Measure takes at most 38 miliseconds, and
                                                //sensor should be idle at that time
  Serial.print("Distance from obstacle is: ");
  Serial.print(hc.getDistance());               //Get distance saved in sensors register
  Serial.println(" cm.");                       
  Serial.print("Time took wave to return: ");
  Serial.print(hc.getDuration());               //Get time needed for bounced ultrasound wave 
                                                //to return to the sensor
  Serial.println(" uS.");
  delay(250);
}
