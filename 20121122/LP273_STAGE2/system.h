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
**  Filename :	system.h
**  Abstract :	This file implements device driver for System module.
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
#ifndef _MDSYSTEM_
#define _MDSYSTEM_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	Preprocessor Clock Control Register (PPCC)
*/
#define	CG_PPCC_INITIALVALUE	0x02
/* Peripheral clock (fXP) selection (PPCC1, PPCC0) */
#define	CG_PERIPHERALCLOCK_FX	0x00	/* fXP = fX */
#define	CG_PERIPHERALCLOCK_FX2	0x01	/* fXP = fX/2 */
#define	CG_PERIPHERALCLOCK_FX4	0x02	/* fXP = fX/2^2 */

/*
	Processor Clock Control Register (PCC)
*/
#define	CG_PCC_INITIALVALUE		0x02
/* CPU clock (fCPU) selection (PCC1) */
#define	CG_CPUCLOCK0			0x00	/* fCPU = fXP */
#define	CG_CPUCLOCK1			0x02	/* fCPU = fXP/2^2 */

/*
	Low-speed Internal Oscillation Mode Register (LSRCM)
*/
/* Low-speed internal oscillator oscillation/stop (LSRSTOP) */
#define	CG_LOWINTERNAL			0x00	/* low-speed internal oscillates */
#define	CG_LOWINTERNAL_RUN		0x00	/* low-speed internal oscillates */
#define	CG_LOWINTERNAL_STOP		0x01	/* low-speed internal oscillator stops */

/*
	Oscillation Stabilization Time Select Register (OSTS)
*/
/* Oscillation stabilization time selection (OSTS1, OSTS0) */
#define	CG_OSCSTAB_SELECT10		0x00	/* 2^10/fX */
#define	CG_OSCSTAB_SELECT12		0x01	/* 2^12/fX */
#define	CG_OSCSTAB_SELECT15		0x02	/* 2^15/fX */
#define	CG_OSCSTAB_SELECT17		0x03	/* 2^17/fX */

/*---------------------------myself-------------------------------*/
#define WDTRF		4
#define LVIRF		0

#define WDTRFisSET(A)		((A)&(1<<WDTRF))
#define LVIRFisSET(A)		((A)&(1<<LVIRF))


/*----------------------------------------------------------------*/

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
enum CPUClock { SYSTEMCLOCK, SYSONEHALF, SYSONEFOURTH, SYSONEEIGHTH, SYSONESIXTEENTH };
enum PSLevel { PSSTOP, PSHALT };
enum StabTime { STLEVEL0, STLEVEL1, STLEVEL2, STLEVEL3 };



/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void CLOCK_Init(void);
void CG_ReadResetSource(void);
/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
