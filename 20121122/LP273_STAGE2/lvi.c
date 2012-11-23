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
**  Filename :	lvi.c
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

/*
*******************************************************************************
**  Include files
*******************************************************************************
*/
#include "macrodriver.h"
#include "lvi.h"
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
**		This function initializes the low-voltage detector.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void LVI_Init(void)
{
	LVION = 0;	/* disable LVI */
	LVIMK = 1;	/* disable INTLVI */
	LVIIF = 0;	/* clear INTLVI flag */
	LVIS = LVI_LVIS_LEVEL_08;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function starts the low-voltage detector.
**
**	Parameters:
**		None
**
**	Returns:
**		MD_OK
**		MD_ERROR
**
**-----------------------------------------------------------------------------
*/
MD_STATUS LVI_Start(void)
{
	MD_STATUS status = MD_OK;
	USHORT i;

	LVION = 1;	/* enable operation */
	/* Wait 200 us */
	for( i = 0; i <= LVI_WAITTIME; i++ )
	{
		NOP();
	}
	if (LVIF == 1)
	{
		/* To avoid this error, please increase "LVI_WAITTIME" value in "lvi.h". */
		status = MD_ERROR;
	}
	else
	{
		LVIIF = 0;	/* clear INTLVI flag */
		LVIMK = 0;	/* enable INTLVI */
		LVIMD = 0;	/* interrupt mode */
	}

	return (status);
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function stops the low-voltage detector.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void LVI_Stop(void)
{
	LVION = 0;	/* disable operation */
	LVIMK = 1;	/* disable INTLVI */
	LVIIF = 0;	/* clear INTLVI flag */
}

/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */


