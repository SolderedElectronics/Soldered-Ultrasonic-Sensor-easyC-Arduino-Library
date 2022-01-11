/**
 **************************************************
 * @file        Ultrasound-distance-sensor-with-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/


#include "Ultrasonic-distance-sensor-with-easyC-SOLDERED.h"

/**
 * @brief
 *
 */
Ultrasonic_Sensor::Ultrasonic_Sensor()
{
}

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
Ultrasonic_Sensor::Ultrasonic_Sensor(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void Ultrasonic_Sensor::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief                   This function sends command to slave device
 *                          to take measure, measure lasts lasts a maximum 
 *                          of 38 milliseconds
 * 
 * @return int              If 0, communication was sucessful 
 */
int Ultrasonic_Sensor::takeMeasure()
{
    return sendAddress(TAKE_MEAS_REG);
}

/**
 * @brief                   This function receives data and converts distance from binary code to
 *                          value in centimeters.
 * 
 * @return                  Distance from obstacle in centimeters
 */
uint16_t Ultrasonic_Sensor::getDistance()
{
    readRegister(DISTANCE_REG, raw, 2 * sizeof(uint8_t));
    value = raw[0] | (raw[1]) << 8;
    return value;
}

/**
 * @brief                   This function receives data and converts it to time needed for bounced sound wave
 *                          to return to sensor 
 * 
 * @return                  Time in microseconds needed for bounced sound wave to return
 */
uint16_t Ultrasonic_Sensor::getDuration()
{
    readRegister(DURATION_REG, raw, 2 * sizeof(uint8_t));
    value = raw[0] | (raw[1]) << 8;
    return value;
}