#include "Buttons.h"
#include "LCD_display.h"
#include  "Axis_reader.h"

int main(){
   DDRB |= (1<<PB5);
   Axis_reader axis;
   ADC_reader adc;
   LCD_display LCD;
   while (1){
	LCD.set_cursor_position(0);
	LCD.Write(axis.read_axis(X));
   }
   return 0;
}