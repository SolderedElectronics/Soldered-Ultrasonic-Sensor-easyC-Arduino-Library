/**
 **************************************************
 *
 * @file        Template for attiny_firmware
 * @brief       Fill in sensor specific code.
 *
 *
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

#define echoPin 0 // attach pin PA4 Arduino to pin Echo of HC-SR04
#define trigPin 1 //attach pin PA5 Arduino to pin Trig of HC-SR04

int addr = DEFAULT_ADDRESS;
char reg_addr[4];
uint8_t bytes_received=0;
uint32_t duration; // variable for the duration of sound wave travel
uint16_t distance; // variable for the distance measurement

void setup()
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);
}

void loop()
{
}

uint16_t getDistance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH,38);
    // Calculating the distance
    return duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}


void receiveEvent(int howMany)
{   
    bytes_received=0;
    while (1 < Wire.available())
    {
        reg_addr[bytes_received] = Wire.read();
        bytes_received++;
    }

    reg_addr[bytes_received] = Wire.read();
    if(reg_addr[0]==1)
    {
        distance=getDistance();
    }
}

void requestEvent()
{
    if(reg_addr[0]==0)
    {
        int n = 2;
        char a[2];
        a[0] = distance & 0xFF;
        a[1] = (distance >> 8) & 0xFF;
        Wire.write(a, n);
    }
}
