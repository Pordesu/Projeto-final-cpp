#include <string>
#include "Clock_calendar.h"
using namespace std;
class Evento{
    private:
        string data;
        Clock_calendar time_date;
    public:
        Evento();
        void set_evento(string dat);
        string get_output();
        string get_date();
        int get_timestamp();
};