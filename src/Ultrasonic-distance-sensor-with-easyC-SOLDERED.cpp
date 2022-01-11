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

int Ultrasonic_Sensor::takeMeasure()
{
    char addr = 0X01;
    return sendAddress(addr);
}

uint16_t Ultrasonic_Sensor::getDistance()
{
    readRegister(0, raw, 2 * sizeof(uint8_t));
    value = raw[0] | (raw[1]) << 8;
    return value;
}