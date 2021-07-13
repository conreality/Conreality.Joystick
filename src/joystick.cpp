#include "joystick.h"


Joystick::Joystick(int ce, int ss)
{
    _driver = new RH_NRF24(ce, ss);

    _manager = new RHReliableDatagram(*_driver, JOYSTICK_ADDRESS);
}

bool Joystick::init(byte xAxis, byte yAxis, byte *buttonsArray, int buttonsLen,bool usePullup)
{
    _x = xAxis;
    _y = yAxis;
    _buttons = buttonsArray;
    _btnLen = buttonsLen;

    bool res = _manager->init();
    if (Serial.availableForWrite())
    {
        if (res)
        {
            Serial.println("radio initialized");
        }
        else
        {
            Serial.println("radio failed initialization");
        }
    }

    if(usePullup==1)
    {
        for(int i=0;i<buttonsLen;i++)
        {
            pinMode(_buttons[i],INPUT_PULLUP);
        }
    }
    return res;
}

void Joystick::send()
{
    byte joystick[2 + 1 + _btnLen];

    joystick[0] = map(analogRead(_x), 0, 1023, 0, 255);
    joystick[1] = map(analogRead(_y), 0, 1023, 0, 255);

    joystick[2] = _btnLen;
    for (int i = 0; i < _btnLen; i++)
    {
        joystick[i + 2 + 1] = digitalRead(_buttons[i]);
    }

    _manager->sendtoWait(joystick, sizeof(joystick), 255);
}
