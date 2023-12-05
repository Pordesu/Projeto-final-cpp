#include "Evento.h"

Evento::Evento(){
}

void Evento::set_evento(string dat){
    std::string::size_type pos = dat.find(",ts:");
    data = dat.substr(1, pos-1);
    int t = stoi(dat.substr(pos+4, 10));
    time_date.set_time(t);
}

string Evento::get_output(){
    return data;
}

string Evento::get_date(){
    return time_date.get_timestr();
}

int Evento::get_timestamp(){
    return time_date.get_timestamp();
}