#include "Arduino.h"
#ifndef JOYSTICK_CONFIG_H
#define JOYSTICK_CONFIG_H
//----------------------------------------------
//          FUNDUINO EXAMPLE CONFIGURATION
//          see:https://protosupplies.com/product/funduino-joystick-shield-v1-a/
//          or google: funduino joystick
//----------------------------------------------

//pins for radio module
#define CE_PIN 9
#define SS_PIN 10

//axis pins
#define JoyStick_X_PIN A0
#define JoyStick_Y_PIN A1

//button pins
#define BTN_A 2
#define BTN_B 3
#define BTN_C 4
#define BTN_D 5
#define BTN_E 6
#define BTN_F 7
#define BTN_K 8

#define USE_PULLUP 0

byte buttons[]={BTN_A, BTN_B, BTN_C, BTN_D, BTN_E, BTN_F, BTN_K};
#define TOTAL_BUTTONS 7

#endif