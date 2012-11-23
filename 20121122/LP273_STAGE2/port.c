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
**  Filename :	port.c
**  Abstract :	This file implements device driver for PORT module.
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
#include "port.h"
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
**		This function initializes the Port I/O.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void PORT_Init(void)
{
	P2 = Pn3_OUTPUT_1;
	PM2 = PMn0_MODE_DEFAULT | PMn1_MODE_DEFAULT | PMn2_MODE_DEFAULT | PMn3_MODE_OUTPUT | PM2_DEFAULT;
	PM3 = PMn2_MODE_INPUT | PMn4_MODE_INPUT | PM3_DEFAULT;
	PM4 = PMn0_MODE_INPUT | PMn3_MODE_INPUT | PM4_DEFAULT;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function changes P23 to input mode by software.
**
**	Parameters:
**		enablePU :	Pull-up enable or not
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void PORT_ChangeP23Input(BOOL enablePU)
{
	if (enablePU)
	{
		PU2 |= PUn3_PULLUP_ON;
	}
	else
	{
		PU2 &= (UCHAR)~PUn3_PULLUP_ON;
	}
	PM2 |= PMn3_MODE_INPUT;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function changes P23 to output mode by software.
**
**	Parameters:
**		initialValue :	initial output 1 or 0
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void PORT_ChangeP23Output(BOOL initialValue)
{
	if (initialValue)
	{
		P2 |= Pn3_OUTPUT_1;
	}
	else
	{
		P2 &= (UCHAR)~Pn3_OUTPUT_1;
	}
	PM2 &= (UCHAR)~PMn3_MODE_INPUT;
}

/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */


