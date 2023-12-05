#include "Buttons.h"
#include "ADC_reader.h"

int main(){
	DDRB |= (1<<PB5);
	ADC_reader input;

	while (true){
		PORTB &= ~(1<<PB5);
		if (input.Read_pin(1) >= 800){
		PORTB |= (1<<PB5);
		_delay_ms(500);
		}
		else{
			PORTB &= ~(1<<PB5);
		}
	}
   return 0;
}
