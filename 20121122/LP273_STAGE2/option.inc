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
;*  Filename :	 option.inc
;*  Abstract :	This file implements OPTION-BYTES/SECURITY-ID setting.
;*  APIlib :	Applilet2 for 78K0S/Kx1+ V2.41 [9 Sep. 2008]
;*
;*  Device :	uPD78F9202
;*
;*  Compiler :	CC78K0S
;*
;*  Creation date:	2012-6-8
;*  
;******************************************************************************
;*/

;/*
;******************************************************************************
;*  Macro define
;******************************************************************************
;*/
;/* 
;******************************************************************************
;*  Register bit define
;******************************************************************************
;*/ 
; ********** OPTION-BYTE(at 80H) bit define **********
OPTIONBYTE_INITIALVALUE	EQU	90H
; Oscillation stabilization time on power application or after reset release (DEFOSTS1-0)
CG_OSCRTAB_SELECT10		EQU	00H	; 2^10/fX
CG_OSCRTAB_SELECT12		EQU	20H	; 2^12/fX
CG_OSCRTAB_SELECT15		EQU	40H	; 2^15/fX
CG_OSCRTAB_SELECT17		EQU	60H	; 2^17/fX
; Control RESET pin (RMCE)
RESET_PIN_USED			EQU	08H	; used as RESET pin
RESET_PIN_UNUSED		EQU	00H	; used RESET pin as input port pin (P34)
; Selection system clock source (OSCSEL1-0)
CG_CRYSTAL_OSCILLATION	EQU	00H	; select crystal/ceramic oscillation clock
CG_EXTERNAL_CLOCK		EQU	02H	; select external clock input
CG_HIGH_SPEED_INTERNAL	EQU	04H	; select high-speed internal oscillation clock
; Internal low-speed oscillator operation (LIOCP)
CG_LOWINTERNAL_CANSTOP	EQU	00H	; can be stopped by software
CG_LOWINTERNAL_CANNOT	EQU	01H	; cannot be stopped
