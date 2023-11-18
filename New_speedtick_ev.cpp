#include "New_speedtick_ev.h"

New_speedtick_ev::New_speedtick_ev(int dat){
    data = dat;
    timestamp = time(NULL);
}

char* New_speedtick_ev::get_output(){
    output[18] = (data/10)+48;
    output[19] = (data%10)+48;
    
    return output;
}

