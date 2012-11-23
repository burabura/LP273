/*~main.idl */
/*file description				+				*/  
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
**  Filename :	 main.c
**  Abstract :	This file implements main function.
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
#include "system.h"
#include "port.h"
#include "ad.h"
#include "lvi.h"
#include "timer.h"
#include "user_define.h"


/*
*******************************************************************************
**  Global define
*******************************************************************************
*/


//USHORT---0x0000  
//UCHAR----0x00
//BOOL=UCHAR

/*variables	definition				+				*/
/*flag*/
BOOL	flagWDTRF;
BOOL	flagLVIRF;
BOOL 	flagTimeUp; //used in Interval Timer      
BOOL	flagDuringDelay;//
//BOOL	flagDuringDEC;
BOOL	flagPIRtrigg;//Being or None
BOOL 	flag_ADfinish;//used in AD as the flag for AD conversion completion
BOOL	flagPWMchanging;
BOOL	flag_DM;
BOOL	flagDM25;
//BOOL	flag_CDS;
BOOL	flagDaylight;
BOOL    flagCDSpermitWork;
BOOL	flagDayNightSwitch;
BOOL	flagPORT4read;
BOOL	flagFirstOpenTest;
BOOL	flag8hours;
BOOL	flag8hours_former;
BOOL	flagBUGtip1;
BOOL	flagP32switch;
BOOL	flagP32LOW;
BOOL	flagINTTMH1;


/*statue & value*/
UCHAR 	gDuty;//used in PWM as duty
UCHAR	St_PIR;//Being or None or Poff 
USHORT	delayLevel;
USHORT	CDS_value;
UCHAR	PORT4_STATUE;
UCHAR	PORT4_STATUE_former;
USHORT	GPCompare;
USHORT	CDScompareH;	
USHORT	CDScompareL;

/*counter*/
USHORT 	delayTick_count; 
UCHAR	ADpirAIM_count;//the counter of PIR got person times
UCHAR	ADsampleTimes_count; //the counter of all PIR sample times 
UCHAR   dm_swAimCount;
UCHAR	DM_SWcount;
UCHAR	cds_swAimCount;
UCHAR	CDS_count;
UCHAR	less200Count;
UCHAR	more730Count;
USHORT	FirstOpenTestCount;
UCHAR	delay_1s_count;
UCHAR	DuringINC_count;
UCHAR	DuringDEC_count;
USHORT	StopMode5sCount;	



void Fn_change_and_runTMH1(void)
{
		TMHE1=0; //STOP the counter
		NOP( );
		NOP( );
		NOP( );
		LSRSTOP = 0;
		TMHMD1=0x00; //clear the register
		TMHMD1 = TMH_INTER_CLOCK_6 | TMH_INTERVAL_SQUARE_MODE | TMH_OUTPUT_LVL_LOW;
		CMP01=0xFF;   //the initial value of counter in low speed freq.
		TMH1_Start( );
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**	Parameters:	UCHAR count=AIM_count	
**	Returns:	BOOL flag
**		
**-----------------------------------------------------------------------------
*/
	
BOOL FN_SWconfirm(UCHAR count)
{
	if(count>=2)	
		return	1;
	else	return	0;
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**	Parameters:	BOOL flag=flag_ADfinish	
**	Returns:	USHORT	buffer		
**
**-----------------------------------------------------------------------------
*/

USHORT Fn_CDSsampleOneShot(BOOL* flag)
{
	USHORT	buffer=0;
	AD_SelectADChannel(AD_INPUT_CHANNEL1);        
	AD_Start();
	while((*flag)==0);//while(!flag_ADfinish);
	AD_Read(&buffer);  
	AD_Stop();
	*flag=0;        
	return buffer;	
}     

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**	Parameters:	BOOL flag=flag_ADfinish	
**	Returns:	BOOL flag
**	//100=0x64,150=0x96,180=0xb4,200=0xc8,220=0xdc,230=0xe6,247=0xF7,280=0x118,290=0x122,300=0x12c,310=0x136,360=0x168
**	//433=0X1B1,
**	//560=0x230,580=0x244,590=0x24E,618=0X26A,650=0x28a,660=0x294,680=0x2a8,730=0x2da,800=0x320,900=0x384,
**
**-----------------------------------------------------------------------------
*/

BOOL Fn_ADsampleOneShot(BOOL* flag)
{
	USHORT	buffer=0;
	AD_SelectADChannel(AD_INPUT_CHANNEL2);	   
	AD_Start();
	while((*flag)==0);//while(!flag_ADfinish);
	AD_Read(&buffer);  
	AD_Stop();
	*flag=0; 
	#ifdef	Supply3V
		#ifdef	NotRailToRail
			if(buffer>=0x24E||buffer<=0x118)   //"LP273" project using NJM2904@3.3V(actual @2.8V cuz not rail to rail)
				return	1;					   //cuz point@2.8/2=1.4 0x118=0.9V(1.4-0.5)  0x24E=1.9v(1.4+0.5)
			else	return	0;		
		#endif
		
		#ifdef	RailToRail
			if(buffer>=0x294||buffer<=0x168)	 //"LED tubo" project using SGM358@3.3V rail-to-rail   point@3.3/2=1.6V  0x294=2.1V 0x168=1.1V
				return	1;
			else	return	0;
		#endif
	#endif
	
	#ifdef	Supply5V
		#ifdef	NotRailToRail
			if(buffer>=0x233||buffer<=0x166)
				return	1;
			else	return	0;
		#endif
		
		#ifdef	RailToRail
			if(buffer>=0x266||buffer<=0x19a)
				return	1;
			else	return	0;
		#endif
	#endif
}

/*
**-----------------------------------------------------------------------------
**
**	Abstract:
**	Parameters:	UCHAR count=AIM_count
**	Returns:	BOOL flag
**
**-----------------------------------------------------------------------------
*/
	
BOOL Fn_PIR_ADaverage(UCHAR count)
{
	if(count>=2)
	{
		delayTick_count=0;	//got person,the delay counter CLEAR
		return	1;
	}
	else	return	0;
}


/* Start adding user code. Do not edit comment generated here */
/* End user code adding. Do not edit comment generated here */



void  main( void )
{

/*variables initialization				+				*/
/*flag initial*/
	flagPIRtrigg=0;
	flagTimeUp=0;		
	flagPWMchanging=0;
	flag_ADfinish=0;
	flagDuringDelay=0;
	flag_DM=0;
	flagDM25=0;
	flagDaylight=0;//initial CDS as Night
	flagCDSpermitWork=1;
	flagDayNightSwitch=0;	//(e)
	flagPORT4read=0;
	flagFirstOpenTest=1;	//(c)
	flag8hours_former=0;
	flag8hours=0;
	flagBUGtip1=0;
	flagP32LOW=0;	 //(b)
	flagP32switch=0;	 //(a)
	flagINTTMH1=0;	
/*counter initial*/	
	ADpirAIM_count=0;
	ADsampleTimes_count=0;
	delayTick_count=0;
	dm_swAimCount=0;
	DM_SWcount=0;
	CDS_count=0;
	less200Count=0;
	more730Count=0;
	FirstOpenTestCount=0;
	delay_1s_count=0;
	DuringINC_count=0;
	DuringDEC_count=0;
	StopMode5sCount=0;
/*statue&value initial*/
	delayLevel=150;//150
	gDuty=TMH1_CMP1_VALUE;
	St_PIR=STPIR_NONE;
	PORT4_STATUE=0;
	PORT4_STATUE_former=0;
	P4=0;
	GPCompare=1500;//150=3s
	CDScompareH=730;
	CDScompareL=200;
	CTRL_GND_PORT=0;
	
	
		
/*HARDWERA initial*/	
	AD_ComparatorOn();   //the "comparator" should be turn on before using AD
	TM00_Start();		//20ms interval start
	TMH1_Start();  		//8-bit PWM start 
	
	

	
	while(1)
	{	

		//semaphore
		while(flagTimeUp==0);
		WDTE = 0xAC;	//wei gou
		flagTimeUp=0;  
			
#ifdef _8HoursHANDLE		
		if(VAC_DETECTION_PORT==0)		//dai wan shan
		{
			flagP32LOW=1;		// (b)
			PWM_PORT=0;
		}	
		while(flagP32LOW)	//(b)
		{
				WDTE = 0xAC;		
				if(flagP32switch==0)	 // (a)  each reset or 8hours done implement once
				{
					flagP32switch=1;     // (a)
					
					//reduce current consumption
					AD_Stop();
					AD_ComparatorOff();
					TM00_Stop();
					CTRL_GND_PORT=1;
					
					//change PWM to low speed Interval timer for waking up from STOP mode
					Fn_change_and_runTMH1();
					StopMode5sCount=0;
				}
				
				flagINTTMH1=0;
				STOP( );       
				StopMode5sCount++;  //255x4us (CMP01x(1/fRL))
				if((StopMode5sCount==0x1262)||(VAC_DETECTION_PORT==1)) //4706x255x4us = 5s ,4706=0x1262
				{
					StopMode5sCount=0;
					flagP32LOW=0; 	   // (b)
					flag8hours=1;
					flagP32switch=0;   // (a)
					
					//turn on the hardware
					CTRL_GND_PORT=0;
					AD_ComparatorOn();
					TM00_Start();
					AD_Start();
					
					//switch the Interval timer to PWM
					TMHE1=0;	//TMH1 STOP
					TMH1_Init();
					NOP();
					NOP();
					NOP();
					//TMH1_Start;
				}
				
					
		}
									
//8 hours HANDLE
		if(flag8hours==1)
		{
			flag8hours=0;
			
			//PWM on
			CMP01 = TMH1_CMP0_VALUE;
			CMP11 = TMH1_CMP1_VALUE;
			TMH1_Start();
			
			GPCompare=6000;//600=12s		
			FirstOpenTestCount=0;	
			flagFirstOpenTest=1;	//(c)
		}
#endif
		
/*FirstOpenTest 30s light*/
		if(FirstOpenTestCount==GPCompare)//this segment is multi used by FirstOpenTest 
		{								 //function and 8hours function
			//shut down PWM
			PWM_PORT=0;
			TMH1_Stop();
			gDuty=1;
			delay_1s_count++;
			if(delay_1s_count==50)
			{	
				FirstOpenTestCount=0;
				delay_1s_count=0;
				flagFirstOpenTest=0;	//(c)
				//TMH1_Start();
				flagBUGtip1=1;			//dai gai jin
				
			}
			else goto OVER_BEING;
			
		}
		else if(flagFirstOpenTest)	//(c)
		{
			FirstOpenTestCount++;
			if(gDuty==199)
				PWM_PORT=1;
			else
			{
				if(DuringINC_count<RISE_TIME_RATIO)		//feng pin
					DuringINC_count++;
				else
				{
					gDuty+=1;
					DuringINC_count=0;
					CMP11=gDuty;
				}	
			}
			goto OVER_BEING;
		}



/*CDS_SW HANDLE*/

#ifdef CDS_HANDLE

		if(flagCDSpermitWork)	
		{		
			CDS_count++;
			CDS_value=Fn_CDSsampleOneShot(&flag_ADfinish);
			
			//PWM25 condition correct process
			if(flagDM25)	
			{					
				CDScompareH=510;	
				CDScompareL=220;  //1.0v-310
			}
			else
			{	
				CDScompareH=510;
				CDScompareL=270;  //1.5v-465
			}
		
			if(flagDaylight==0)
			{
				if(CDS_value<CDScompareL)
					less200Count++;	
			}
			else 
			{	
				if(CDS_value>CDScompareH)
					more730Count++;
			}
			if(CDS_count==4)
			{
				
				if((less200Count>2)&&(flagDaylight==0))
					flagDaylight=1;
				else if((more730Count>2)&&(flagDaylight==1))
					flagDaylight=0;
		
				CDS_count=0;
				less200Count=0;
				more730Count=0;
					
			}		
		}
		else
		{
				CDS_count=0;
				less200Count=0;
				more730Count=0;
		}
#endif
			
/*COUNTER ++ */		
		
		if(flagDuringDelay) 
			delayTick_count++;
		DM_SWcount++;
		ADsampleTimes_count++; 	
		
		
/*DELAY HANDLE*/
		PORT4_STATUE=P4;
		PORT4_STATUE&=0x09; //0000 1001   P40,P43
		if(PORT4_STATUE==PORT4_STATUE_former)
			flagPORT4read=1;		//(d)
		else
		{	
			flagPORT4read=0;		//(d)
			PORT4_STATUE_former=PORT4_STATUE;
		}
		
		
		if(flagPORT4read)		//(d)
		{
			flagPORT4read=0;	//(d)
			if(PORT4_STATUE==0x09)
				delayLevel=150;//150=3s
			else if (PORT4_STATUE==0x08)
				delayLevel=500;//500=10s
			else if (PORT4_STATUE==0x01)
				delayLevel=900;//900=18s
		}
		
		if(((delayTick_count>=150)&&(delayLevel==150))
			||((delayTick_count>=500)&&(delayLevel==500))
			||((delayTick_count>=900)&&(delayLevel==900)))
			{
				delayTick_count=0;
				flagDuringDelay=0;
			}
		/*when  "delayLevel" set in 3000 and "delayTick_count" reached 600 ,
		you toggle the switch from 3000 to 500,in this situation it will be
		handle as "delayTick_count" reached the compare value immediately  */
 		
		
			
/*PIR HANDLE*/
if(flagFirstOpenTest==0)	//(c)
{		
		if(ADsampleTimes_count==4)
		{
			flagPIRtrigg=((Fn_PIR_ADaverage(ADpirAIM_count))|(flagDuringDelay));// 0,1,1
			ADpirAIM_count=0;			//4 times cycle end,clear the counter	
			ADsampleTimes_count=0;	
		}
		if(Fn_ADsampleOneShot(&flag_ADfinish))
		{
			ADpirAIM_count++;
		}
		
}		
/*DM_SW HANDLE*/
		
		if(P3.4==1)
		{
			dm_swAimCount++;
		}
		if(DM_SWcount==4)
		{	
			flag_DM=FN_SWconfirm(dm_swAimCount);
			dm_swAimCount=0;
			DM_SWcount=0;
		}
		
		
		
		
		
		if(flagDaylight)
		{
			flagDayNightSwitch=1;	//(e)
			flagPIRtrigg=0;
			delayTick_count=0;
			flagDuringDelay=0;
		}
		else if(flagDayNightSwitch)		//(e)
			{
				flagDayNightSwitch=0;	//(e)
				gDuty=1;
				TMH1_Start(); 	
			}
		

		if(flag_DM)
		{	
			if(flagBUGtip1)		
			{
				gDuty=1;
				TMH1_Start();
				flagBUGtip1=0;
			}
		}
				
/*flagPIRtrigg==0-----------------------------------------------------*/
		if(!flagPIRtrigg)			//NONE
		{
			if(St_PIR==STPIR_NONE)		
			{
				if((flag_DM)&&(flagDaylight==0))		
				{
						if(gDuty==DUTY_THRESHOLD)	
						{	
							flagPWMchanging=0;
							flagCDSpermitWork=1;
							flagDM25=1;
							goto OVER_NONE;
								 	
						}
						else if(gDuty>DUTY_THRESHOLD)				
						{
							PWM_PORT=0;
								
							////////////////////////////////////	
							if(DuringDEC_count<DM_DOWN_TIME_RATIO)    //DM down time ratio
								DuringDEC_count++;
							else	
							{
								gDuty -=1;
								DuringDEC_count=0;
								CMP11=gDuty;
							}
							////////////////////////////////////
							
							flagPWMchanging=1;
							flagCDSpermitWork=0; 
					  		flagDM25=0;
						}	
						
						else 	//CDS control DM
						{
							if(gDuty==1)
								TMH1_Start();
								
							////////////////////////////////////	
							if(DuringINC_count<DM_RISE_TIME_RATIO)    //DM up time ratio
								DuringINC_count++;
							else
							{
								gDuty+=1;
								DuringINC_count=0;
								CMP11=gDuty;
							}	
							////////////////////////////////////
							
							flagPWMchanging=1;
							flagCDSpermitWork=0;
							flagDM25=0;
							
						}
				}
				
				else if((flag_DM==0)||(flagDaylight==1))
				{
					if(gDuty>1)
					{	
						PWM_PORT=0;
							/////////////////////////////
							if(DuringDEC_count<DOWN_TIME_RATIO)	//down time ratio
								DuringDEC_count++;
							else
							{
								gDuty -=1;
								DuringDEC_count=0;
								CMP11=gDuty;
							}
							/////////////////////////////
						
						flagPWMchanging=1;
						flagCDSpermitWork=0;
						
					}
					
					else
					{	
						TMH1_Stop();
						flagPWMchanging=0;
						flagCDSpermitWork=1;
						gDuty=1;
					}
					flagDM25=0;
				}
			}
			
			else
			{	
				PWM_PORT=0;
				
				////////////////////////////
				if(DuringDEC_count<DOWN_TIME_RATIO)		//down time ratio
					DuringDEC_count++;
				else	
				{
					gDuty -=1;
					DuringDEC_count=0;
					CMP11=gDuty;
				}
				////////////////////////////
				
				flagPWMchanging=1;
				flagCDSpermitWork=0;
				St_PIR=STPIR_NONE;
				flagDM25=0;
			}
OVER_NONE:	;
		}
		


/*flagPIRtrigg==1-----------------------------------------------------*/		
		
		else 				//BEING
		{
			if(St_PIR==STPIR_BEING) 			//i
			{
				if (gDuty ==199)			
				{
					flagPWMchanging=0;
					flagCDSpermitWork=0;
					PWM_PORT=1;
					goto OVER_BEING;	//got 100 percent
				}
					
				else 
				{					//100 uncompelet
					//if((flagDayNightSwitch==1)&&(flagDaylight==0)&&(flagPWMchanging==0))
					//{
					//	flagDayNightSwitch=0;
					//	gDuty=1;
					//	TMH1_Start(); 	
					//}
					//if(flagBUGtip1)
					//{
					//	flagBUGtip1=0;
					//	gDuty=1;
					//	TMH1_Start(); 	
					//}
					
					//////////////////////////////////////////
					if(DuringINC_count<RISE_TIME_RATIO)
						DuringINC_count++;
					else
					{
						gDuty+=1;
						DuringINC_count=0;
						CMP11=gDuty;
					}	
										
					//////////////////////////////////////////
					flagPWMchanging=1; 
					flagCDSpermitWork=0;     
				
				}
			}
			
			else								//j
			{
				if((flag_DM==0)&&(flagPWMchanging==0))
				{
					gDuty=1;
					TMH1_Start();
				}
				
				/////////////////////////////////
				if(DuringINC_count<RISE_TIME_RATIO)
					DuringINC_count++;
				else
				{					
					gDuty+=1;
					DuringINC_count=0;
					CMP11=gDuty;
				}	
				//////////////////////////////////
				
				flagPWMchanging=1;  
				flagCDSpermitWork=0;    
				St_PIR=STPIR_BEING;	
				delayTick_count=0;
				flagDuringDelay=1;
				
			}
OVER_BEING:		flagDM25=0;
		}			
	}//End of while(1);
}//End of main();




