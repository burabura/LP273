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
**  Filename :	ad_user.c
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

#pragma interrupt INTAD MD_INTAD
/*
*******************************************************************************
**  Include files
*******************************************************************************
*/
#include "macrodriver.h"
#include "ad.h"
/* Start user code for include definition. Do not edit comment generated here */
/* End user code for include definition. Do not edit comment generated here */
#include "user_define.h"

/*
*******************************************************************************
**  Global define
*******************************************************************************
*/
/* Start user code for global definition. Do not edit comment generated here */

extern BOOL flag_ADfinish;

/* End user code for global definition. Do not edit comment generated here */


/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function is INTAD interrupt service routine.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
__interrupt void MD_INTAD(void)
{
	/* Start user code. Do not edit comment generated here */
	flag_ADfinish = 1;
	
	/* End user code. Do not edit comment generated here */
}

/* Start adding user code. Do not edit comment generated here */
 
//[Example]

//       USHORT buffer = 0;

//       flag_finish = 1;

//       AD_SelectADChannel(ADCHANNEL1);        /* selects AD input channel */

//       AD_Start();        /* starts the A/D converter */

//       while(flag_finish);        /* conversion end waiting */

//       AD_Read(&buffer);        /* returns the result to buffer */

//       AD_Stop();        /* stops the A/D converter */

/* End user code adding. Do not edit comment generated here */


