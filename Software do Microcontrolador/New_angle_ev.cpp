#include "New_angle_ev.h"

New_angle_ev::New_angle_ev(char ax, int dat){
    axis = ax;
    data = dat;
    timestamp = time(NULL);
}

char* New_angle_ev::get_output(){
    output[13] = axis;
    output[14] = ' '; output[15] = '='; output[16] = ' ';

    if (data >= 0){
        output[17] = '+';
        output[18] = (data/10)+48; //Converte dígito mais significativo para ASCII
        output[19] = (data%10)+48; //Converte dígito menos significativo para ASCII
    }
    else{
        output[17] = '-';
        output[18] = (data/10)+48;
        output[19] = (data%10)+48;
    }
    
    return output;
}

int  New_angle_ev::get_timestamp(){
    return timestamp;
}
