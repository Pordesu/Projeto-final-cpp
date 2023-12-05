#include "atmega_libs.h"

#define SPEED_UP 0
#define SPEED_DOWN 1
#define SPEED_TICK_UP 2
#define SPEED_TICK_DOWN 3
#define BTN_DELAY 100
class Buttons{
    public:
        bool read_button(char pin); //Rotina de leitura do botão
        Buttons(); //Construtor
};