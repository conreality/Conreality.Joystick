#include "Arduino.h"
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <SPI.h>

#ifndef JOYSTICK_H
#define JOYSTICK_H

#ifndef JOYSTICK_ADDRESS
#define JOYSTICK_ADDRESS 1
#endif

#ifndef RECEIVER_ADDRESS
#define RECEIVER_ADDRESS 2
#endif

class Joystick
{
private:
    RHReliableDatagram* _manager;
    RH_NRF24* _driver;
    byte _x;
    byte _y;
    byte* _buttons;
    int _btnLen;
public:
    Joystick(int ce, int ss);
    bool init(byte xAxis,byte yAxis, byte* buttonsArray, int buttonsLen,bool usePullup);
    void send();
};





#endif