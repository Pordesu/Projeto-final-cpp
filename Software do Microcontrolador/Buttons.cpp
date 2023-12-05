#include "Buttons.h"

Buttons::Buttons(){
    DDRB &= ~(1<<SPEED_UP); // Habilita para  modo de leitura os pinos digitais (2, 3, 5 e 6)
    DDRB &= ~(1<<SPEED_DOWN);
    DDRB &= ~(1<<SPEED_TICK_UP);
    DDRB &= ~(1<<SPEED_TICK_DOWN);
}

bool Buttons::read_button(char pin){
    switch(pin){        //Switch Case para identificação de qual dos 4 botões foi pressionado
        case SPEED_UP: 
            if (PINB & (1<<SPEED_UP)){
                _delay_ms(BTN_DELAY);  //Delay para mitigar o bouncing do botão
                return true;
            }
            else {
                return false;
            }
        case SPEED_DOWN:
            if (PINB & (1<<SPEED_DOWN)){
                _delay_ms(BTN_DELAY);
                return true;
            }
            else {
                return false;
            }
        case SPEED_TICK_UP:
            if (PINB & (1<<SPEED_TICK_UP)){
                _delay_ms(BTN_DELAY);
                return true;
            }
            else {
                return false;
            }

        case SPEED_TICK_DOWN:
            if (PINB & (1<<SPEED_TICK_DOWN)){
                _delay_ms(BTN_DELAY);
                return true;
            }
            else {
                return false;
            }
        
        default:
            return false;
    }
}