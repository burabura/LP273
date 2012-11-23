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
**  Filename :	macrodriver.h
**  Abstract :	This file implements general head file.
**  APIlib :	Applilet2 for 78K0S/Kx1+ V2.41 [9 Sep. 2008]
**
**  Device :	uPD78F9202
**
**  Compiler :	CC78K0S
**
**  Creation date:	2012-7-16
**  
*******************************************************************************
*/
#ifndef _MDSTATUS_
#define _MDSTATUS_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/
#pragma sfr
#pragma DI
#pragma EI
#pragma NOP
#pragma HALT
#pragma STOP

/* Data type defintion */
typedef	unsigned long	ULONG;
typedef	signed long		SLONG;

typedef	unsigned int	UINT;
typedef	signed int		SINT;

typedef	unsigned short	USHORT;
typedef	signed short	SHORT;

typedef	unsigned char	UCHAR;
typedef	signed char		SCHAR;

typedef	unsigned char	BOOL;
typedef	unsigned short	MD_STATUS;

#define	MD_ON		1
#define	MD_OFF		0

#define	MD_TRUE		1
#define	MD_FALSE	0

/* Status list definition */
#define	MD_STATUSBASE		0x00
#define	MD_OK				MD_STATUSBASE+0x0	/* register setting OK */
#define	MD_RESET			MD_STATUSBASE+0x1	/* reset input */
#define	MD_SENDCOMPLETE		MD_STATUSBASE+0x2	/* send data complete */
#define	MD_OVF				MD_STATUSBASE+0x3	/* timer count overflow */

/* Error list definition */
#define	MD_ERRORBASE		0x80
#define	MD_ERROR			MD_ERRORBASE+0x00	/* error */
#define	MD_RESOURCEERROR	MD_ERRORBASE+0x01	/* no resource available */
#define	MD_PARITYERROR		MD_ERRORBASE+0x02	/* UARTn parity error(n=0,6) */
#define	MD_OVERRUNERROR		MD_ERRORBASE+0x03	/* UARTn overrun error(n=0,6) */
#define	MD_FRAMEERROR		MD_ERRORBASE+0x04	/* UARTn frame error(n=0,6) */
#define	MD_ARGERROR			MD_ERRORBASE+0x05	/* Error agrument input error */
#define	MD_TIMINGERROR		MD_ERRORBASE+0x06	/* Error timing operation error */
#define	MD_SETPROHIBITED	MD_ERRORBASE+0x07	/* setting prohibited */
#define	MD_DATAEXISTS		MD_ERRORBASE+0x08	/* Data to be transferred next exists in TXB6 register */
/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
#endif
