/**
 **************************************************
 * @file        Ultrasound-distance-sensor-with-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#ifndef __ULTRASONIC_DISTANCE_SENSOR__
#define __ULTRASONIC_DISTANCE_SENSOR__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

#define TAKE_MEAS_REG 0
#define DISTANCE_REG  1
#define DURATION_REG  2

class Ultrasonic_Sensor : public ULTRASONIC_DISTANCE_SENSOR::EasyC
{
  public:
    Ultrasonic_Sensor();
    Ultrasonic_Sensor(int _echoPin, int _trigPin);
    int takeMeasure();
    uint16_t getDistance();
    uint16_t getDuration();

  protected:
    void initializeNative();

  private:
    int echoPin,trigPin;
    char raw[2];
    uint16_t value;
};

#endif
