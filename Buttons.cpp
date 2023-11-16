#include "Buttons.h"

Buttons::Buttons(){
    DDRD &= ~(1<<PD2); // Habilita para  modo de leitura os pinos digitais (2, 3, 5 e 6)
    DDRD &= ~(1<<PD3);
    DDRD &= ~(1<<PD5);
    DDRD &= ~(1<<PD6);
}

bool Buttons::Read_button(char pin){
    switch(pin){        //Switch Case para identificação de qual dos 4 botões foi pressionado
        case SPEED_UP: 
            if (PIND & (1<<PD2)){
                _delay_ms(50);  //Delay para mitigar o bouncing do botão
                return true;
            }
            else {
                return false;
            }
        case SPEED_DOWN:
            if (PIND & (1<<PD3)){
                _delay_ms(50);
                return true;
            }
            else {
                return false;
            }
        case TICK_SPEED_UP:
            if (PIND & (1<<PD5)){
                _delay_ms(50);
                return true;
            }
            else {
                return false;
            }

        case TICK_SPEED_DOWN:
            if (PIND & (1<<PD6)){
                _delay_ms(50);
                return true;
            }
            else {
                return false;
            }
        
        default:
            return false;
    }
}