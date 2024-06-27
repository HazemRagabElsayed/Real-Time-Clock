#include <avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#include"LCD.h"
#include"timer.h"
#include"keypad_driver.h"
#include"seven_segment.h"

volatile unsigned char seconds_counter = 0;
unsigned char minutes_counter = 0, hours_counter = 0;
char first_digit = NOTPRESSED, second_digit = NOTPRESSED, button = NOTPRESSED;
int main(void)
{
	
	LCD_vInit();
	keypad_vInit();
	seven_seg_vinit('D');
	LCD_vSend_string("Press 1 to");
	LCD_movecursor(2,1);
	LCD_vSend_string("set time:");
	timer2_overflow_init_interrupt();
	DIO_vsetPINDir('C',0,1);
	DIO_vsetPINDir('C',1,1);
	DIO_vsetPINDir('C',2,1);
	DIO_vsetPINDir('C',3,1);
	DIO_vsetPINDir('C',4,1);
	DIO_vsetPINDir('C',5,1);
	
	while(1)
	{
		do 
		{
			button = keypad_u8check_press();
			PORTC = 0b111110;
			if(60 == seconds_counter)
			{
				minutes_counter++;
				seconds_counter = 0;
			}
			seven_seg_write('D',seconds_counter%10);
			_delay_ms(5);
			PORTC = 0b111101;
			seven_seg_write('D',seconds_counter/10);
			_delay_ms(5);
			PORTC = 0b111011;
			seven_seg_write('D',minutes_counter%10);
			_delay_ms(5);
			PORTC = 0b110111;
			seven_seg_write('D',minutes_counter/10);
			_delay_ms(5);
			PORTC = 0b101111;
			seven_seg_write('D',hours_counter%10);
			_delay_ms(5);
			PORTC = 0b011111;
			seven_seg_write('D',hours_counter/10);
			_delay_ms(5);
			if(60 == minutes_counter)
			{
				hours_counter++;
				minutes_counter = 0;
			}
			if(24 <= hours_counter)
			{
				hours_counter = 0;
			}
			
			
		} while (button == NOTPRESSED);
		if(button == '1')
		{
			LCD_clearscreen();
			_delay_ms(300);
			LCD_vSend_string("hours:--");
			LCD_movecursor(1,7);
			do{
				first_digit = keypad_u8check_press();
				
			}while(NOTPRESSED == first_digit);
			_delay_ms(300);
			LCD_vSend_char(first_digit);
			do{
				second_digit = keypad_u8check_press();
			}while(NOTPRESSED == second_digit);
			_delay_ms(300);
			LCD_vSend_char(second_digit);
			_delay_ms(180);
			hours_counter = (first_digit-48)*10 + (second_digit-48);
			LCD_clearscreen();
			LCD_vSend_string("minutes:--");
			LCD_movecursor(1,9);
			do{
				first_digit = keypad_u8check_press();
				
			}while(NOTPRESSED == first_digit);
			_delay_ms(300);
			LCD_vSend_char(first_digit);
			do{
				second_digit = keypad_u8check_press();
			}while(NOTPRESSED == second_digit);
			_delay_ms(300);
			LCD_vSend_char(second_digit);
			_delay_ms(180);
			minutes_counter = (first_digit-48)*10 + (second_digit-48);
			LCD_clearscreen();
			LCD_vSend_string("seconds:--");
			LCD_movecursor(1,9);
			do{
				first_digit = keypad_u8check_press();
				
			}while(NOTPRESSED == first_digit);
			_delay_ms(300);
			LCD_vSend_char(first_digit);
			do{
				second_digit = keypad_u8check_press();
			}while(NOTPRESSED == second_digit);
			_delay_ms(300);
			LCD_vSend_char(second_digit);
			seconds_counter = (first_digit-48)*10 + (second_digit-48);
			_delay_ms(180);
			LCD_clearscreen();
			LCD_vSend_string("Press 1 to");
			LCD_movecursor(2,1);
			LCD_vSend_string("set time:");
			
		}
		else
		{
			
		}
		
	}
	
}


ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}