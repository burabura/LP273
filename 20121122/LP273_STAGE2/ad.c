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
**  Filename :	ad.c
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
/* End user code for global definition. Do not edit comment generated here */


/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function initializes the A/D converter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void AD_Init(void)
{
	ADM = AD_ADM_INITIALVALUE;	/* disable AD conversion */
	ADMK = 1;	/* disable INTAD */
	ADIF = 0;	/* clear INTAD flag */
	ADCE = 1;	/* enable AD comparator */
	/* Set AD input channel */
	ADS = AD_INPUT_CHANNEL1;
	/* Set AD conversion time */
	ADM |= AD_CONVERSION_TIME2;
	/* Set AD pin */
	/* Set ANI1 pin */
	PM2 |= 0x02;
	PMC2 |= 0x02;
	/* Set ANI2 pin */
	PM2 |= 0x04;
	PMC2 |= 0x04;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function starts the A/D converter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void AD_Start(void)
{
	ADIF = 0;	/* clear INTAD flag */
	ADMK = 0;	/* enable INTAD */
	ADCS = 1;	/* enable AD conversion */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function returns the conversion result in the buffer.
**
**	Parameters:
**		*buffer :	the address where to write the conversion result
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void AD_Read(USHORT* buffer)
{
	*buffer = (USHORT)ADCR;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function stops the A/D converter.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void AD_Stop(void)
{
	ADCS = 0;	/* disable AD conversion */
	ADMK = 1;	/* disable INTAD */
	ADIF = 0;	/* clear INTAD flag */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function enables comparator operation.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void AD_ComparatorOn(void)
{
	ADCE = 1;	/* enable AD comparator */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function stops comparator operation.
**
**	Parameters:
**		None
**
**	Returns:
**		None
**
**-----------------------------------------------------------------------------
*/
void AD_ComparatorOff(void)
{
	ADCE = 0;	/* disable AD comparator */
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**		This function selects analog input channel.
**
**	Parameters:
**		channel :	analog input channel
**
**	Returns:
**		MD_OK
**		MD_ARGERROR
**
**-----------------------------------------------------------------------------
*/
MD_STATUS AD_SelectADChannel(enum ADChannel channel)
{
	MD_STATUS status = MD_OK;
	
	if ((channel >= ADCHANNEL0) && (channel <= ADCHANNEL3))
	{
		ADS = channel;
	}
	else
	{
		status = MD_ARGERROR;
	}

	return (status);
}

/* Start adding user code. Do not edit comment generated here */
/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**	Parameters:	BOOL flag=flag_ADfinish	
**	Returns:	USHORT	buffer		
**
**-----------------------------------------------------------------------------
*/

USHORT Fn_ADSsampleOneShot(BOOL* flag,enum ADChannel channel)
{	USHORT	buffer;
	AD_SelectADChannel(channel);  
	buffer=0;     
	AD_Start();
	while((*flag)==0);//while(!flag_ADfinish);
	AD_Read(&buffer);  
	AD_Stop();
	*flag=0;        
	return buffer;	
}     

/* End user code adding. Do not edit comment generated here */


