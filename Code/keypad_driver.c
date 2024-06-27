#include "keypad_driver.h"
 void keypad_vInit()
 {
	 DIO_vsetPINDir('B',0,1);
	 DIO_vsetPINDir('B',1,1);
	 DIO_vsetPINDir('B',2,1);
	 DIO_vsetPINDir('B',3,1);
	 DIO_vsetPINDir('B',4,0);
	 DIO_vsetPINDir('B',5,0);
	 DIO_vsetPINDir('B',6,0);
	 DIO_vsetPINDir('B',7,0);
	 DIO_vconnectpullup('B',4,1);
	 DIO_vconnectpullup('B',5,1);
	 DIO_vconnectpullup('B',6,1);
	 DIO_vconnectpullup('B',7,1);
	  
 }
 char keypad_u8check_press()
 {
	 char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 char row,coloumn,x;
	 char returnval=NOTPRESSED;
	 for(row=0;row<4;row++)
	 {
		DIO_write('B',0,1);
		DIO_write('B',1,1);
		DIO_write('B',2,1);
		DIO_write('B',3,1);
		DIO_write('B',row,0);
	
		for(coloumn=0;coloumn<4;coloumn++)
		{
			x=DIO_u8read('B',(coloumn+4));
			if(x==0)
			 {
				 returnval=arr[row][coloumn];
				 break;
			 }  
		}	
		if(x==0)
		{
			break;
		}
	}	 
	 return returnval ;	 
 }