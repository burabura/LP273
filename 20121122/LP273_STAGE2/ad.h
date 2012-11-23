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
**  Filename :	ad.h
**  Abstract :	This file implements device driver for AD module.
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
#ifndef _MDAD_
#define _MDAD_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	A/D Converter Mode Register (ADM)
*/
/* Initial value */
#define AD_ADM_INITIALVALUE		0x00
/* A/D conversion operation control (ADCS) */
#define AD_CONVERSION_ENABLE	0x80	/* enable A/D conversion operation control */
#define AD_CONVERSION_DISABLE	0x00	/* disable A/D conversion operation control */
/* A/D conversion time selection (FR2, FR1, FR0) */
#define AD_CONVERSION_TIME0		0x00	/* 36/fXP (conversion time), 12/fXP (sampling time) */
#define AD_CONVERSION_TIME1		0x20	/* 72/fXP (conversion time), 24/fXP (sampling time) */
#define AD_CONVERSION_TIME2		0x30	/* 144/fXP (conversion time), 96/fXP (sampling time) */
#define AD_CONVERSION_TIME3		0x28	/* 96/fXP (conversion time), 48/fXP (sampling time) */
#define AD_CONVERSION_TIME4		0x10	/* 72/fXP (conversion time), 48/fXP (sampling time) */
#define AD_CONVERSION_TIME5		0x08	/* 48/fXP (conversion time), 24/fXP (sampling time) */
#define AD_CONVERSION_TIME6		0x38	/* 224/fXP (conversion time), 176/fXP (sampling time) */
#define AD_CONVERSION_TIME7		0x18	/* 112/fXP (conversion time), 88/fXP (sampling time) */
/* A/D comparator operation control (ADCE) */
#define AD_COMPARATOR_ENABLE	0x01	/* enable comparator operation control */
#define AD_COMPARATOR_DISABLE	0x00	/* disable comparator operation control */

/*
	Analog Input Channel Specification Register (ADS)
*/
/* Initial value */
#define AD_ADS_INITIALVALUE		0x00
/* Analog input channel specification (ADS1, ADS0) */
#define AD_INPUT_CHANNEL0		0x00	/* ANI0 */
#define AD_INPUT_CHANNEL1		0x01	/* ANI1 */
#define AD_INPUT_CHANNEL2		0x02	/* ANI2 */
#define AD_INPUT_CHANNEL3		0x03	/* ANI3 */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
enum ADChannel { ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3 };

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void AD_Init(void);
void AD_Start(void);
void AD_Read(USHORT* buffer);
void AD_Stop(void);
void AD_ComparatorOn(void);
void AD_ComparatorOff(void);
MD_STATUS AD_SelectADChannel(enum ADChannel channel);
__interrupt void MD_INTAD(void);
/* Start user code for definition. Do not edit comment generated here */
#define CDS_CHANNEL	AD_INPUT_CHANNEL1
#define PIR_CHANNEL	AD_INPUT_CHANNEL2

USHORT Fn_ADSsampleOneShot(BOOL* flag,enum ADChannel channel);

/* End user code for definition. Do not edit comment generated here */
#endif
