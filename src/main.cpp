
#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include <SPI.h>
#include "joystick.h"


/*---------------------------------------------------*/
/*
  See configuration examples in config_examples folder
*/

#include "joystick_config.h"


/*---------------------------------------------------*/


/***
 *                                                            
 *    ,------.            ,--.,--.                            
 *    |  .--. ' ,--,--. ,-|  |`--' ,---.                      
 *    |  '--'.'' ,-.  |' .-. |,--.| .-. |                     
 *    |  |\  \ \ '-'  |\ `-' ||  |' '-' '                     
 *    `--' '--' `--`--' `---' `--' `---'                      
 *         ,--.                      ,--.  ,--.      ,--.     
 *         |  | ,---.,--. ,--.,---.,-'  '-.`--' ,---.|  |,-.  
 *    ,--. |  || .-. |\  '  /(  .-''-.  .-',--.| .--'|     /  
 *    |  '-'  /' '-' ' \   ' .-'  `) |  |  |  |\ `--.|  \  \  
 *     `-----'  `---'.-'  /  `----'  `--'  `--' `---'`--'`--' 
 *                   `---'                                    
 */


Joystick joystick(CE_PIN, SS_PIN);



void setup()
{
  Serial.begin(9600);

  joystick.init(JoyStick_X_PIN,JoyStick_Y_PIN,buttons,TOTAL_BUTTONS,USE_PULLUP==1);
}

void loop()
{
  joystick.send();
}
