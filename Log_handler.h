#ifndef _LOG_
#define _LOG_

#include "New_angle_ev.h"
#include "New_speed_ev.h"
#include "New_speedtick_ev.h"
#include "Plane.h"
#include "Queue.h"

class Log_handler{
    private:
        Queue<Event> Log;
        Plane past_pln;
    public:
        Log_handler();
        void update_log(Plane pln);
        Event get_first();
        void uart_check_and_send();
};

void UART_init(uint16_t ubrr);
void UART_putc(unsigned char data);
void UART_puts(char* s);
char UART_getc(void) ;

#endif