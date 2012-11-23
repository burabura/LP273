#
# Project manager generated MAKEFILE
#
TITLE = LP273
DEVFILE = C:\Program Files\NEC Electronics Tools\DEV\DF9202.78K
PROJDIR = G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2
TOOLDIR = C:\Program Files\NEC Electronics Tools\PM+\V6.30\BIN
WORKDIR = G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2
DEBUG = 

CC = "C:\Program Files\NEC Electronics Tools\CC78K0S\V2.01\bin\cc78k0s.exe"
ST = "C:\Program Files\NEC Electronics Tools\RA78K0S\V2.00\bin\st78k0s.exe"
RA = "C:\Program Files\NEC Electronics Tools\RA78K0S\V2.00\bin\ra78k0s.exe"
LK = "C:\Program Files\NEC Electronics Tools\RA78K0S\V2.00\bin\lk78k0s.exe"
OC = "C:\Program Files\NEC Electronics Tools\RA78K0S\V2.00\bin\oc78k0s.exe"
LCNV = "C:\Program Files\NEC Electronics Tools\RA78K0S\V2.00\bin\lc78k0s.exe"

OBJS = main.rel  \
	systeminit.rel  \
	option.rel  \
	system.rel  \
	system_user.rel  \
	port.rel  \
	ad.rel  \
	ad_user.rel  \
	lvi.rel  \
	lvi_user.rel  \
	timer.rel  \
	timer_user.rel 

DEP_main_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\system.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\port.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\ad.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\lvi.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\timer.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_systeminit_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\system.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\port.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\ad.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\lvi.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\timer.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_option_asm = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\option.inc"

DEP_system_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\system.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_system_user_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\system.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_port_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\port.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_ad_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\ad.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_ad_user_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\ad.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_lvi_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\lvi.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_lvi_user_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\lvi.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_timer_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\timer.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

DEP_timer_user_c = "G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\macrodriver.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\timer.h" \
	"G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\user_define.h"

GOAL : G:\test proj\78K0S_test\LED Software\Using\20121122\LP273_STAGE2\a.hex

main.rel : main.c $(DEP_main_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc main.c

systeminit.rel : systeminit.c $(DEP_systeminit_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc systeminit.c

option.rel : option.asm $(DEP_option_asm)
	$(RA) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff  option.asm

system.rel : system.c $(DEP_system_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc system.c

system_user.rel : system_user.c $(DEP_system_user_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc system_user.c

port.rel : port.c $(DEP_port_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc port.c

ad.rel : ad.c $(DEP_ad_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc ad.c

ad_user.rel : ad_user.c $(DEP_ad_user_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc ad_user.c

lvi.rel : lvi.c $(DEP_lvi_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc lvi.c

lvi_user.rel : lvi_user.c $(DEP_lvi_user_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc lvi_user.c

timer.rel : timer.c $(DEP_timer_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc timer.c

timer_user.rel : timer_user.c $(DEP_timer_user_c)
	$(CC) -cF9202 -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -zpc timer_user.c

a.lmf : $(OBJS)
	$(LK) -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff -oa.lmf "C:\Program Files\NEC Electronics Tools\CC78K0S\V2.01\lib78k0s\s0s.rel"  -pa.map -bcl0s.lib -bcl0sf.lib -i"C:\Program Files\NEC Electronics Tools\CC78K0S\V2.01\lib78k0s" -dlk.dr -s  main.rel systeminit.rel option.rel system.rel system_user.rel port.rel ad.rel ad_user.rel lvi.rel lvi_user.rel timer.rel timer_user.rel 

a.hex : a.lmf
	$(OC) -y"C:\Program Files\NEC Electronics Tools\DEV" -_msgoff  a.lmf

























