;/*
;******************************************************************************
;*
;*  This device driver was created by Applilet2 for the Applilet2 for 78K0S/Kx1+
;*  8-Bit Single-Chip Microcontrollers
;*
;*  Copyright(C) NEC Electronics Corporation 2002 - 2012
;*  All rights reserved by NEC Electronics Corporation.
;*
;*  This program should be used on your own responsibility.
;*  NEC Electronics Corporation assumes no responsibility for any losses
;*  incurred by customers or third parties arising from the use of this file.
;*
;*  Filename :	 option.asm
;*  Abstract :	This file implements OPTION-BYTES/SECURITY-ID setting.
;*  APIlib :	Applilet2 for 78K0S/Kx1+ V2.41 [9 Sep. 2008]
;*
;*  Device :	uPD78F9202
;*
;*  Compiler :	CC78K0S
;*
;*  Creation date:	2012-7-16
;*  
;******************************************************************************
;*/

;/*
;******************************************************************************
;*  Include files
;******************************************************************************
;*/
$ INCLUDE (option.inc)
;/*
;******************************************************************************
;*  Macro define
;******************************************************************************
;*/

;/*
;******************************************************************************
;*  Global define
;******************************************************************************
;*/
	OPT_SET CSEG AT 80H
OPTION:	  DB OPTIONBYTE_INITIALVALUE OR CG_OSCRTAB_SELECT17 OR RESET_PIN_UNUSED OR CG_HIGH_SPEED_INTERNAL OR CG_LOWINTERNAL_CANNOT

	ONC_RESERVED CSEG AT 81H
RESERVED: DB 0FFH

; Start adding user code. Do not edit comment generated here
; End user code adding. Do not edit comment generated here
	END
