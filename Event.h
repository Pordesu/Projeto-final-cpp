#ifndef _EVENT_
#define _EVENT_

#include <time.h>

class Event{  //Classe a ser utilizada como tipo dos nodes na fila, tipos mais específicos dos eventos herdam Event
    protected:
        int data;
        int timestamp;
    public:
        Event();
        virtual char* get_output(){}
};

#endif