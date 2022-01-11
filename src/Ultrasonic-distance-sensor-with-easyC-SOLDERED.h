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

class Ultrasonic_Sensor : public ULTRASONIC_DISTANCE_SENSOR::EasyC
{
  public:
    Ultrasonic_Sensor();
    Ultrasonic_Sensor(int _pin);
    int takeMeasure();
    uint16_t getDistance();

  protected:
    void initializeNative();

  private:
    int pin;
    char raw[2];
    uint16_t value;
};

#endif
