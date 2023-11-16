#include "atmega_libs.h"

#define SPEED_UP 2
#define SPEED_DOWN 3
#define TICK_SPEED_UP 5
#define TICK_SPEED_DOWN 6

class Buttons{
    public:
        bool Read_button(char pin); //Rotina de leitura do botão
        Buttons(); //Construtor
};