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
**  Filename :	timer.c
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

/*
*******************************************************************************
**  Include files
*******************************************************************************
*/
#include "macrodriver.h"
#include "timer.h"
/* Start user code for include definition. Do not edit comment generated here */
/* End user code for include definition. Do not edit comment generated here */
#include "user_define.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
/* Start user code for global definition. Do not edit comment generated here */
/* End user code for global definition. Do not edit comment generated here */


/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function initializes TM00.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TM00_Init(void)
{
	TMC00 = TM0_OPERATE_DISABLE;
	TMMK000 = 1;	/* disable INTTM000 */
	TMIF000 = 0;	/* clear INTTM000 flag */
	TMMK010 = 1;	/* disable INTTM010 */
	TMIF010 = 0;	/* clear INTTM010 flag */
	/* TM00 interval timer */
	PRM00 = TM0_INTER_CLOCK_2;
	CRC00 = TM0_CR00_COMPARE;
	CR000 = TM00_CR000_VALUE;
	CR010 = TM00_CR010_VALUE;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function starts TM00 counter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TM00_Start(void)
{
	TMIF000 = 0;	/* clear INTTM000 flag */
	TMMK000 = 0;	/* enable INTTM000 */
	TMC00 &= (UCHAR)~TM0_OPERATE;
	TMC00 |= TM0_CLEAR_BY_MATCH_CR00;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function stops TM00 counter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TM00_Stop(void)
{
	TMC00 = TM0_OPERATE_DISABLE;
	TMMK000 = 1;	/* disable INTTM000 */
	TMIF000 = 0;	/* clear INTTM000 flag */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function changes TM00 interval value.
**
**	Parameters:
**		*array_reg : array_reg values in the compare registers
**		array_num : value number
**
**	Returns:
**		MD_OK
**		MD_ARGERROR
**
**-----------------------------------------------------------------------------
*/
MD_STATUS TM00_ChangeTimerCondition(USHORT* array_reg, UCHAR array_num)
{
	MD_STATUS status = MD_OK;

	switch (array_num)
	{
		case 1:
			CR000 = array_reg[0];
			break;
		case 2:
			CR000 = array_reg[0];
			CR010 = array_reg[1];
			break;
		default:
			status = MD_ARGERROR;
			break;
	}

	return (status);
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function initializes TMH1.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TMH1_Init(void)
{
	TMHE1 = 0;	/* disable TMH1 counter */
	TMMKH1 = 1;	/* disable INTTMH1 */
	TMIFH1 = 0;	/* enable INTTMH1 */
	/* TMH1 PWM output mode */
	TMHMD1 = TMH_INTER_CLOCK_1 | TMH_PWM_MODE | TMH_OUTPUT_LVL_LOW;
	//TMHMD1 = TMH_INTER_CLOCK_4 | TMH_PWM_MODE | TMH_OUTPUT_LVL_LOW;
	CMP01 = TMH1_CMP0_VALUE;
	CMP11 = TMH1_CMP1_VALUE;
	/* Set TOH1 pin */
	PM2 &= 0xFE;
	P2 &= 0xFE;
	PMC2 &=0xFE;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function starts TMH1 counter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TMH1_Start(void)
{
	TMIFH1 = 0;	/* clear INTTMH1 flag */
	TMMKH1 = 0;	/* enable INTTMH1 */
	CMP11 = TMH1_CMP1_VALUE;
	TOEN1 = 1;	/* enable output */
	TMHE1 = 1;	/* enable TMH1 counter */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function stops TMH1 counter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TMH1_Stop(void)
{
	TMHE1 = 0;	/* disable TMH1 counter */
	TOEN1 = 0;	/* disable output */
	TMMKH1 = 1;	/* disable INTTMH1 */
	TMIFH1 = 0;	/* clear INTTMH1 flag */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function changes TMH1 duty value.
**
**	Parameters:
**		ratio :	value for duty
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void TMH1_ChangeDuty(UCHAR ratio)
{
	USHORT cycle = CMP01 + 1;
	USHORT reg = 0;

	if (ratio > 100)
	{
		ratio = 100;
	}
	reg = cycle * ratio / 100 - 1;
	CMP11 = (UCHAR)reg;
}

/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */


