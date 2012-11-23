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
**  Filename :	lvi.h
**  Abstract :	This file implements device driver for LVI module.
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
#ifndef _MDLVI_
#define _MDLVI_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	Low-voltage Detection Register (LVIM)
*/
/* Low-voltage detection operation (LVION) */
#define LVI_OPERATION			0x80
#define LVI_OPERATION_DISABLE	0x00	/* disables operation */
#define LVI_OPERATION_ENABLE	0x80	/* enables operation */
/* Operation mode selection (LVIMD) */
#define LVI_MODE				0x02
#define LVI_MODE_INT			0x00	/* generates interrupt signal */
#define LVI_MODE_RESET			0x02	/* generates reset signal */
/* Low-voltage detection flag (LVIF) */
#define LVI_FLAG				0x01
#define LVI_FLAG_OVER			0x00	/* voltage >= detection voltage */
#define LVI_FLAG_LESS			0x01	/* voltage < detection voltage */

/*
	Low-voltage Detection Level Selection Register (LVIS)
*/
/* Detection level (LVIS0-3) */
#define LVI_LVIS_LEVEL			0x00
#define LVI_LVIS_LEVEL_00		0x00	/*  4.3 V +/- 0.2 V */
#define LVI_LVIS_LEVEL_01		0x01	/*  4.1 V +/- 0.2 V */
#define LVI_LVIS_LEVEL_02		0x02	/*  3.9 V +/- 0.2 V */
#define LVI_LVIS_LEVEL_03		0x03	/*  3.7 V +/- 0.2 V */
#define LVI_LVIS_LEVEL_04		0x04	/*  3.5 V +/- 0.2 V */
#define LVI_LVIS_LEVEL_05		0x05	/*  3.3 V +/- 0.15 V */
#define LVI_LVIS_LEVEL_06		0x06	/*  3.1 V +/- 0.15 V */
#define LVI_LVIS_LEVEL_07		0x07	/*  2.85 V +/- 0.15 V */
#define LVI_LVIS_LEVEL_08		0x08	/*  2.6 V +/- 0.1 V */
#define LVI_LVIS_LEVEL_09		0x09	/*  2.35 V +/- 0.1 V */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
#define LVI_WAITTIME			2000
enum LVILevel { 
	LVILEVEL0, LVILEVEL1, LVILEVEL2, LVILEVEL3,
	LVILEVEL4, LVILEVEL5, LVILEVEL6, LVILEVEL7,
	LVILEVEL8, LVILEVEL9
	};

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void LVI_Init(void);
MD_STATUS LVI_Start(void);
void LVI_Stop(void);
__interrupt void MD_INTLVI(void);
/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
