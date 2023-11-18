#include "Event.h"

class New_speed_ev : virtual public Event{
        private:
            char output[15] = "New speed = "; //String a ser comunicada via UART, possui tamanhos diferentes para diferentes tipos de evento
            
        public:
            New_speed_ev(int dat);
            char* get_output();
};