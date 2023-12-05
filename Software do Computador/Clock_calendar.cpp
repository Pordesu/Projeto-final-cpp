#include "Clock_calendar.h"

Clock_calendar::Clock_calendar(){
        day = 1;
        month = 1;
        year = 2023; 
        hours = 0;
        minutes = 0;
        timestamp = 536121600;
}

void Clock_calendar::set_time(int ts){
    //Como o timestamp entregue está no formato de segundos desde 1 de janeiro de 2000
    //Descontamos a quantidade de segundos até 2023 para não precisar contar os anos bisextos entre 2000 e 2023
    int aux;
    aux = ts - 725817600;
    timestamp = aux;
    year = 2023 + aux/(360*24*60*60); //Considerando o ano como 12 meses de 30 dias
    month = 1 + (aux - (year-2023)*(360*24*60*60))/(24*60*60*30); //Consideramos os meses como possuindo 30 dias
    day = 1 + (aux - (year-2023)*(24*60*60*360) - (month-1)*(24*60*60*30))/(24*60*60);
    hours = (aux - (year-2023)*(24*60*60*360) - (month-1)*(24*60*60*30) - (day-1)*(24*60*60))/(60*60);
    minutes = (aux - (year-2023)*(24*60*60*360) - (month-1)*(24*60*60*30) - (day-1)*(24*60*60) - (hours)*(60*60))/60;
}

string Clock_calendar::get_timestr(){
    return "D:"+ to_string(day) + " M:" + to_string(month) + " Y:" + to_string(year) + " h:" + to_string(hours) + " min:" +  to_string(minutes);
}

int Clock_calendar::get_timestamp(){
    return timestamp;
}