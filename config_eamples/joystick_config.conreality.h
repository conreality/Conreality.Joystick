#include "Arduino.h"
#ifndef JOYSTICK_CONFIG_H
#define JOYSTICK_CONFIG_H

//----------------------------------------------
//CONREALITY CUSTOM JOYSTICK EXAMPLE CONFIGURATION
//----------------------------------------------


//radionmodule pins
#define CE_PIN 5
#define SS_PIN 6

//axis pins
#define JoyStick_X_PIN A0
#define JoyStick_Y_PIN A1

//button pins
#define BTN_TRIGGER 2
#define BTN_FL 3 
#define BTN_LASER 4

//use pullup
#define USE_PULLUP 1

byte buttons[]={BTN_TRIGGER, BTN_FL, BTN_LASER};

#define TOTAL_BUTTONS 3

#endif