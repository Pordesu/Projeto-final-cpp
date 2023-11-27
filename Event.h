#ifndef _EVENT_
#define _EVENT_

#include <time.h>

class Event{  //Classe a ser utilizada como tipo dos nodes na fila, tipos mais específicos dos eventos herdam Event
    protected:
        int data;
        int timestamp;
    public:
        Event();
        virtual char* get_output(){} //Função virtual para que possa ser chamado get_output() definido das classes filhas
                                    //Esta função retorna a string a ser passada para o log que corresponde a um evento
        virtual int get_timestamp(){}
};

#endif