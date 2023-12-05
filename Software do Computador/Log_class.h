#include <string>
#include "Evento.h"
#include "Queue.h"

class Log_class{
    private:
        Queue<Evento> log;

    public:
        Log_class();
        void put_logstr(string micro_log); //Recebe a string de eventos enviada pelo microcontrolador
        string get_output_log(int month, int day, int month_b, int day_b); //Entrega o log com os eventos entre as datas
        void print();
};
