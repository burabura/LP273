/*
*******************************************************************************
**
**  This device driver was created by Applilet2 for 78K0S/Kx1+
**  8-Bit Single-Chip Microcontrollers
**
**  Copyright(C) NEC Electronics Corporation 2002 - 2012
**  All rights reserved by NEC Electronics Corporation.
**
**  This program should be used on your own responsibility.
**  NEC Electronics Corporation assumes no responsibility for any losses
**  incurred by customers or third parties arising from the use of this file.
**
**  Filename :	user_define.h
**  Abstract :	This file includes user define.
**  APIlib :	Applilet2 for 78K0S/Kx1+ V2.41 [9 Sep. 2008]
**
**  Device :	uPD78F9202
**
**  Compiler :	CC78K0S
**
**  Creation date:	2012-6-8
**  
*******************************************************************************
*/
#ifndef _MD_USER_DEF_
#define _MD_USER_DEF_
/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
/* Start user code for definition. Do not edit comment generated here */
//HARDWARE MACRO
//-----------------------------------
#define Supply3V
//#define	Supply5V

#define	NotRailToRail
//#define RailToRail
//-----------------------------------
#define	PWM_PORT P2.0  
#define	CTRL_GND_PORT P2.3
#define VAC_DETECTION_PORT P3.2
//#define DelayTimeSwitch_Mid P4.0
//#define DelayTimeSwitch_Long P4.3
#define DM_Switch P3.4
#define PIR_Signal_PORT P2.2
#define CDS_PORT P2.1
//--------------------------------------------

//SOFTWARE MACRO
//--------------------------------------------
#define	_8HoursHANDLE
#define	CDS_HANDLE
//--------------------------------------------
#define DUTY_THRESHOLD 15  //  200 is 100%
#define DOWN_TIME_RATIO 0
#define RISE_TIME_RATIO 0
#define DM_DOWN_TIME_RATIO 0
#define DM_RISE_TIME_RATIO 0


#define		DELAY_10s
#define 	DELAY_60s
#define		DELAY_180S

#define		THRESHOLD_ON_HIGHLEVEL
#define		THRESHOLD_OFF_HIGHLEVEL
#define		THRESHOLD_ON_LOWLEVEL
#define		THRESHOLD_OFF_LOWLEVEL

#define		DUTY_INCVALUE			0x01		
#define		DUTY_DECVALUE		

//UCHAR St_PIR
#define		STPIR_POFF		0x00
#define		STPIR_NONE		0x01
#define		STPIR_BEING		0x02
/* End user code for definition. Do not edit comment generated here */
#endif
