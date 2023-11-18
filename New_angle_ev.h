#include "Event.h"

class New_angle_ev : virtual public Event{
    private:
        char output[21] = "New Angle on "; //String a ser comunicada via UART, possui tamanhos diferentes para diferentes eventos
        char axis = 'X';
    public:
        New_angle_ev(char ax, int dat);
        char* get_output(); // Substitui o valor de dat para comparação de alteração nos valores e escreve em output = operation + char(dat)
};