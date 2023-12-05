#include <iostream>
#include <string>
using namespace std;

class Clock_calendar{
    private:
        int day, month, year, hours, minutes, timestamp;
    public: 
        Clock_calendar();
        void set_time(int ts);
        string get_timestr();
        int get_timestamp();
};


