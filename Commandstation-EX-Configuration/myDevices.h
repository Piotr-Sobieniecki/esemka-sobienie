#ifndef MYDEVICES_H
//#define MYDEVICES_H

#include "IO_HALDisplay.h"
#include "myAliases.h"

//****  HAL Devices   ****//
//    HAL(device, parameters) 
//HAL(PCA9685,100, 16, 0x40)  // defined by default  in IODevice.cpp
/*  Examples  
* HAL(PCA9685,116, 16, 0x41)  
* HAL(MCP23017,164, 16, 0x20)
* HAL(MCP23017,180, 16, 0x21)
*/ 
//HAL(PCF8574,BTN1, 8, 0x20)  	// 8 bit io

// Define additional displays apart from display 0 defined in config.h
//HAL(HALDisplay<OLED>,DSP_STATION, 0x3c, 128, 64)

//****  TURNOUTS   ****//
// TURNOUT(id, adr[0-511], subaddr[0-3])

TURNOUT(TRN_01,0,0,"T1")
TURNOUT(TRN_02,0,1,"T2")
TURNOUT(TRN_03,0,2,"T3")
TURNOUT(TRN_04,0,3,"T4")
TURNOUT(TRN_05,1,0,"T5")
TURNOUT(TRN_06,1,1,"T6")
TURNOUT(TRN_07,1,2,"T7")
TURNOUT(TRN_08,1,3,"T8")
TURNOUT(TRN_09,2,0,"T9")
TURNOUT(TRN_10,2,1,"T10")

TURNOUT(SH1  ,20,0,"SH1-S1_S2")
TURNOUT(SH1+1,20,1,"SH1-S3_S4")
TURNOUT(SH1+2,20,2,"SH1-S5-S10")
TURNOUT(SH1+3,20,3,"SH1-S11-S12")
TURNOUT(SH1+4,21,0,"SH1-S13-SZ")
TURNOUT(SH2 ,21,1,"SH2-S1-S2")
TURNOUT(SH2a,21,2,"SH2-S3-S5")

TURNOUT(SH3  ,30,0,"SH3-S1_S2")
TURNOUT(SH3+1,30,1,"SH3-S3_S4")
TURNOUT(SH3+2,30,2,"SH3-S5-S10")
TURNOUT(SH3+3,30,3,"SH3-S11-S12")
TURNOUT(SH3+4,31,0,"SH3-S13-SZ")
TURNOUT(SH4 ,31,1,"SH4-S1-S2")
TURNOUT(SH4a,31,2,"SH4-S3-S5")





//SERVO_TURNOUT(109,100,200,400,Fast,HIDDEN)
//SERVO_TURNOUT(110,101,200,400,Fast,"ST110")

//VIRTUAL_TURNOUT(201)
//VIRTUAL_TURNOUT(202)

// Caution: Pin turnout pins defined here my conflict with sensiors and outputs in mySetup.h
//PIN_TURNOUT(226,26,"PT26")
//PIN_TURNOUT(227,27,"PT27") 


//****  SIGNALS   ****//
// four aspects in two groups for unisemaf - only RED/GREEN comand for every aspect
// DCC_SIGNAL( id, addr, sub_addr ) - Define a DCC accessory signal

DCC_SIGNAL(SH1,20,0)    
DCC_SIGNAL(SH1a,20,1)
DCC_SIGNAL(SH1b,20,2)
DCC_SIGNAL(SH1c,20,3)

//VIRTUAL_SIGNAL(401)  //hidden




//****  SENSORS   ****//
//****  OUTPUTS   ****//
#endif