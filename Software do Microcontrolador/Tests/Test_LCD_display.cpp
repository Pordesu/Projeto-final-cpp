#include "Buttons.h"
#include "ADC_reader.h"
#include "LCD_display.h"

int main(){
   DDRB |= (1<<PB5);
   LCD_display LCD;
   while (1){
	PORTB |= (1<<PB5);
	LCD.set_cursor_position(9);
	LCD.Write('C');
	_delay_ms(500);
	PORTB &= ~(1<<PB5);
	LCD.set_cursor_position(41);
	LCD.Write(99);
	_delay_ms(500);
   }
   return 0;
}