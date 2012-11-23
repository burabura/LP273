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
**  Filename :	port.h
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
#ifndef _MDPORT_
#define _MDPORT_
/*
*******************************************************************************
**	Register bit define
*******************************************************************************
*/
/*
	Port mode register(PMn.0 to 7)
*/
#define PMn0_MODE_DEFAULT	0x01	/* not use Pn0 as digital I/O */
#define PMn1_MODE_DEFAULT	0x02	/* not use Pn1 as digital I/O */
#define PMn2_MODE_DEFAULT	0x04	/* not use Pn2 as digital I/O */
#define PMn3_MODE_DEFAULT	0x08	/* not use Pn3 as digital I/O */
#define PMn4_MODE_DEFAULT	0x10	/* not use Pn4 as digital I/O */

#define PMn0_MODE_INPUT		0x01	/* Pn0 as input mode */
#define PMn1_MODE_INPUT		0x02	/* Pn1 as input mode */
#define PMn2_MODE_INPUT		0x04	/* Pn2 as input mode */
#define PMn3_MODE_INPUT		0x08	/* Pn3 as input mode */
#define PMn4_MODE_INPUT		0x10	/* Pn4 as input mode */

#define PMn0_MODE_OUTPUT	0x00	/* Pn0 as output mode */
#define PMn1_MODE_OUTPUT	0x00	/* Pn1 as output mode */
#define PMn2_MODE_OUTPUT	0x00	/* Pn2 as output mode */
#define PMn3_MODE_OUTPUT	0x00	/* Pn3 as output mode */
#define PMn4_MODE_OUTPUT	0x00	/* Pn4 as output mode */

#define PMn0_CHANGE_OUTPUT	0xFE	/* Change Pn0 to output mode */
#define PMn1_CHANGE_OUTPUT	0xFD	/* Change Pn1 to output mode */
#define PMn2_CHANGE_OUTPUT	0xFB	/* Change Pn2 to output mode */
#define PMn3_CHANGE_OUTPUT	0xF7	/* Change Pn3 to output mode */
#define PMn4_CHANGE_OUTPUT	0xEF	/* Change Pn4 to output mode */

/*
	Port register(Pn.1 to 7)
*/
#define Pn0_OUTPUT_0		0x00	/* Pn0 output 0 */
#define Pn1_OUTPUT_0		0x00	/* Pn1 output 0 */
#define Pn2_OUTPUT_0		0x00	/* Pn2 output 0 */
#define Pn3_OUTPUT_0		0x00	/* Pn3 output 0 */
#define Pn4_OUTPUT_0		0x00	/* Pn4 output 0 */

#define Pn0_OUTPUT_1		0x01	/* Pn0 output 1 */
#define Pn1_OUTPUT_1		0x02	/* Pn1 output 1 */
#define Pn2_OUTPUT_1		0x04	/* Pn2 output 1 */
#define Pn3_OUTPUT_1		0x08	/* Pn3 output 1 */
#define Pn4_OUTPUT_1		0x10	/* Pn4 output 1 */

/*
	Pull-up resistor option register(PUn.1 to 7)
*/
#define PUn0_PULLUP_OFF		0x00	/* Pn0 Pull-up not connected */
#define PUn1_PULLUP_OFF		0x00	/* Pn1 Pull-up not connected */
#define PUn2_PULLUP_OFF		0x00	/* Pn2 Pull-up not connected */
#define PUn3_PULLUP_OFF		0x00	/* Pn3 Pull-up not connected */
#define PUn4_PULLUP_OFF		0x00	/* Pn4 Pull-up not connected */

#define PUn0_PULLUP_ON		0x01	/* Pn0 pull-up connected */
#define PUn1_PULLUP_ON		0x02	/* Pn1 pull-up connected */
#define PUn2_PULLUP_ON		0x04	/* Pn2 pull-up connected */
#define PUn3_PULLUP_ON		0x08	/* Pn3 pull-up connected */
#define PUn4_PULLUP_ON		0x10	/* Pn4 pull-up connected */

/*
	Port mode registers default value(PMn.0 to 12)
*/
#define	PM2_DEFAULT			0xF0	/* PM2 default value */
#define	PM3_DEFAULT			0xFB	/* PM3 default value */
#define	PM4_DEFAULT			0xF6	/* PM4 default value */

/*
*******************************************************************************
**  Macro define
*******************************************************************************
*/

/*
*******************************************************************************
**  Function define
*******************************************************************************
*/
void PORT_Init(void);
void PORT_ChangeP23Input(BOOL enablePU);
void PORT_ChangeP23Output(BOOL initialValue);
/* Start user code for definition. Do not edit comment generated here */
/* End user code for definition. Do not edit comment generated here */
#endif
