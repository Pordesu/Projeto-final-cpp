#include "Event.h"

class New_speedtick_ev : virtual public Event{
    private:
        char output[20] = "New speed tick = "; //String a ser comunicada via UART, possui tamanhos diferentes para diferentes tipos de evento

    public:
        New_speedtick_ev(int dat);
        char* get_output();
        int get_timestamp();
};