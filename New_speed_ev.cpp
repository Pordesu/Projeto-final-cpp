#include "New_speed_ev.h"

New_speed_ev::New_speed_ev(int dat){
    data = dat;
    timestamp = time(NULL);
}

char* New_speed_ev::get_output(){
    output[12] = (data/10)+48;
    output[13] = (data%10)+48;
    
    return output;
}

int New_speed_ev::get_timestamp(){
    return timestamp;
}