#include "Buttons.h"

int main(){
DDRB |= (1<<PB5);

Buttons botao;

   while (1){
		if (botao.Read_button(SPEED_UP)){
			PORTB |= (1<<PB5);
			_delay_ms(500);
		}
		else{
			PORTB &= ~(1<<PB5);
		}
	}
   return 0;
}
