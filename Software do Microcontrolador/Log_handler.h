#ifndef _LOG_
#define _LOG_

#include "New_angle_ev.h"
#include "New_speed_ev.h"
#include "New_speedtick_ev.h"
#include "Plane.h"
#include "Queue.h"

class Log_handler{  //Classe para lidar com a fila e escrita na UART do microcontrolador
    private:
        Queue<Event> Log;
        Plane past_pln;
        int init; // Variável para guardar o valor inicial do  tempo do microcontrolador
    public:
        Log_handler();
        void update_log(Plane pln);
        Event get_first();
        void uart_check_and_send();
};

//Funções de escrita da UART
void UART_init(uint16_t ubrr);
void UART_putc(unsigned char data);
void UART_puts(char* s);
char UART_getc(void) ;

#endif