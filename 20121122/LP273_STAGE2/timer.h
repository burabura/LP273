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
**  Filename :	timer.h
**  Abstract :	This file implements device driver for Timer module.
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
#ifndef _MDTIMER_
#define _MDTIMER_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	TM00 Mode Control Register(TMC00)
*/
#define TM0_TMC0_INITIALVALUE		0x00
/* Operating mode and clear mode selection(TMC00.TMC003 & TMC00.TMC002) */
#define TM0_OPERATE					0x0C	/* for clear the bits */
#define TM0_OPERATE_DISABLE			0x00	/* operation stop(TM00 cleared to 0) */
#define TM0_OPERATE_FREERUNNING		0x04	/* free-running mode */
#define TM0_CLEAR_BY_TI00_EDGE		0x08	/* clear & start occurs on TI000 pin valid edge */
#define TM0_CLEAR_BY_MATCH_CR00		0x0C	/* clear & start occurs on match between TM00 and CR000 */
/* Condition to reverse timer output(TO00)(TMC00.TMC001) */
#define TM0_TO00_MATCH_CR0n			0x00	/* matches between TM00 and CR000 or matches between TM00 and CR010 */
#define TM0_TO00_MATCH_CR0n_TI00	0x02	/* matches between TM00 and CR000 or matches between TM00 and CR010 or triggers input of TI000 pin valid edge */
/* TM00 overflow detection(TMC00.OVF00) */
#define TM0_OVERFLOW_FLAG			0x01	/* overflow detected */

/*
	Capture/Compare Control Register(CRC00)
*/
#define TM0_CRC0_INITIALVALUE		0x00
/* CR010 operating mode selection(CRC00.CRC002) */
#define TM0_CR01_MODE				0x04
#define TM0_CR01_COMPARE			0x00	/* operates as compare register */
#define TM0_CR01_CAPTURE			0x04	/* operates as capture register */
/* CR000 capture trigger selection(CRC00.CRC001) */
#define TM0_CR00_CAPTURE_MODE		0x02
#define TM0_CR00_CAPTURE_TI01		0x00	/* captures on valid edge of TI010 pin */
#define TM0_CR00_CAPTURE_TI00		0x02	/* captures on valid edge of TI000 pin by reverse phase */
/* CR000 operating mode selection(CRC00.CRC000) */
#define TM0_CR00_MODE				0x01
#define TM0_CR00_COMPARE			0x00	/* operates as compare register */
#define TM0_CR00_CAPTURE			0x01	/* operates as capture register */

/*
	Timer Output Control Register(TOC00)
*/
#define TM0_TOC0_INITIALVALUE		0x00
/* One-shot pulse output trigger control via software(TOC00.OSPT00) */
#define TM0_SOFTWARE_TRIGGER_OFF	0x00	/* no one-shot pulse output trigger */
#define TM0_SOFTWARE_TRIGGER_ON		0x40	/* one-shot pulse output trigger */
/* One-shot pulse output operation control(TOC00.OSPE00) */
#define TM0_SUCCESSIVE_MODE			0x00	/* successive pulse output mode */
#define TM0_ONESHOT_MODE			0x20	/* one-shot pulse output mode */
/* Timer output F/F control on match of CR010 and TM00(TOC00.TOC004) */
#define TM0_CR01_OUTPUT_FF_OFF_MODE	0x00	/* disables inversion operation */
#define TM0_CR01_OUTPUT_FF_ON_MODE	0x10	/* enables inversion operation */
/* Timer output F/F status setting(TOC00.LVS00 & TOC00.LVR00) */
#define TM0_OUTPUT_INIT_LEVEL_CLR	0x0C	/* for clear the bits */
#define TM0_OUTPUT_INIT_LEVEL_LOW	0x04	/* timer output F/F reset (0) */
#define TM0_OUTPUT_INIT_LEVEL_HIGH	0x08	/* timer output F/F set (1) */
/* Timer output F/F control using match of CR000 and TM00(TOC00.TOC001) */
#define TM0_CR00_OUTPUT_FF_OFF_MODE	0x00	/* disables inversion operation */
#define TM0_CR00_OUTPUT_FF_ON_MODE	0x02	/* enables inversion operation */
/* Timer output control(TOC00.TOE00) */
#define TM0_OUTPUT_DISABLE_BIT		0x00	/* disables output (output fixed to level 0) */
#define TM0_OUTPUT_ENABLE_BIT		0x01	/* enables output */

/*
	Prescaler Mode Register(PRM00)
*/
#define TM0_PRM0_INITIALVALUE		0x00
/* TI010 pin valid edge selection(PRM00.ES110 & PRM00.ES100) */
#define TM0_TI01_VALID_EDGE			0xC0	/* for clear the bits */
#define TM0_TI01_VALID_EDGE_FALL	0x00	/* falling edge */
#define TM0_TI01_VALID_EDGE_RISE	0x40	/* rising edge */
#define TM0_TI01_VALID_EDGE_BOTH	0xC0	/* both falling and rising edges */
/* TI000 pin valid edge selection(PRM00.ES010 & PRM00.ES000) */
#define TM0_TI00_VALID_EDGE			0x30	/* for clear the bits */
#define TM0_TI00_VALID_EDGE_FALL	0x00	/* falling edge */
#define TM0_TI00_VALID_EDGE_RISE	0x10	/* rising edge */
#define TM0_TI00_VALID_EDGE_BOTH	0x30	/* both falling and rising edges */
/* Count clock selection(PRM00.PRM001 & PRM00.PRM000) */
#define TM0_COUNT_CLOCK				0x03	/* for clear the bits */
#define TM0_INTER_CLOCK_1			0x00	/* fXP */
#define TM0_INTER_CLOCK_2			0x01	/* fXP/2^2 */
#define TM0_INTER_CLOCK_3			0x02	/* fXP/2^8 */
#define TM0_EXTER_CLOCK				0x03	/* TI000 valid edge */

/*
	8-bit timer H mode register 1 (TMHMD1)
*/
#define TMH_TMHMD_INITIALVALUE		0x00	/* TMHMD1 initial value */
/* Timer operation enable(TMHMD1.TMHE1) */
#define TMH_OPERATE_DISABLE			0x00	/* stops timer count operation(counter is cleared to 0) */
#define TMH_OPERATE_ENABLE			0x80	/* enables timer count operation(count operation started by inputting clock) */
/* Count clock selection(TMHMD1.CKS12~CKS10) */
#define TMH_INTER_CLOCK_1			0x00	/* fXP */
#define TMH_INTER_CLOCK_2			0x10	/* fXP/2^2 */
#define TMH_INTER_CLOCK_3			0x20	/* fXP/2^4 */
#define TMH_INTER_CLOCK_4			0x30	/* fXP/2^6 */
#define TMH_INTER_CLOCK_5			0x40	/* fXP/2^12 */
#define TMH_INTER_CLOCK_6			0x50	/* fRL/2^7 */
/* Timer operation mode(TMHMD1.TMMD11~TMMD10) */
#define TMH_INTERVAL_SQUARE_MODE	0x00	/* interval/square-wave timer mode */
#define TMH_PWM_MODE				0x08	/* PWM output mode */
/* Timer output level control (in default mode)(TMHMD1.TOLEV1) */
#define TMH_OUTPUT_LVL_LOW			0x00	/* low level */
#define TMH_OUTPUT_LVL_HIGH			0x02	/* high level */
/* Timer output control(TMHMDn.TOENn) */
#define	TMH_OUTPUT_ENABLE_BIT		0x01	/* output enabled */
#define	TMH_OUTPUT_DISABLE_BIT		0x00	/* output disabled */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
/* 16-bit timer compare register 000 (CR000) */
#define TM00_CR000_VALUE			0x4E1F
/* 16-bit timer compare register 010 (CR010) */
#define TM00_CR010_VALUE			0xFFFF
/* 8-bit timer compare register H1 (CMP01) */
#define	TMH1_CMP0_VALUE				0xC8
/* 8-bit timer compare register H1 (CMP11) */
#define	TMH1_CMP1_VALUE				0x00
enum TMChannel { TMCHANNEL0, TMCHANNEL1 };

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void TM00_Init(void);
void TM00_Start(void);
void TM00_Stop(void);
MD_STATUS TM00_ChangeTimerCondition(USHORT* array_reg, UCHAR array_num);
__interrupt void MD_INTTM000(void);
void TMH1_Init(void);
void TMH1_Start(void);
void TMH1_Stop(void);
void TMH1_ChangeDuty(UCHAR ratio);
__interrupt void MD_INTTMH1(void);
/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
