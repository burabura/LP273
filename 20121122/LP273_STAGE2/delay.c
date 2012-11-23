#include "delay.h"




void delay_us(unsigned int time)
 {     
   while (time--);
 }		  

 
void delay_ms(unsigned int time)
	 {
	  while(time--) delay_us(100);  		 
	 }
	 
	 

