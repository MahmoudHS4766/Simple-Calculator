/*
 * simple_calculator_project.c
 *
 * Created: 10/6/2023 12:07:35 AM
 *  Author: mahmo
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "LCD.h"
#include "Keybad_driver.h"

int main(void)
{
	LCD_Init();
	Keybad_Init();
	unsigned char flag=0, first_digit, second_digit, key_input;
	short result;
	
    while(1)
    {
		while (flag == 0)
		{
	        do
	        {
		        key_input=Keybad_getKey();
	        } while (key_input==NOT_PRESSED || key_input=='+' || key_input=='-' || key_input=='*' ||  key_input=='/' ||  key_input=='=');
	        first_digit = key_input-48;
			LCD_sendChar(key_input-48);
	        _delay_ms(300);
			
	        do
	        {
		        key_input=Keybad_getKey();
	        } while (key_input==NOT_PRESSED || key_input=='+' || key_input=='-' || key_input=='*' ||  key_input=='/' ||  key_input=='=');
	        first_digit = first_digit*10 + (key_input+48);
			LCD_sendChar(key_input-48);
	        _delay_ms(300);
			
			
		}
 	 }
	    
}