#include "Log_class.h"

Log_class::Log_class(){
}

void Log_class::put_logstr(string micro_log){
    Evento ev;
    string aux = micro_log;
    while(aux != "/"){
    std::string::size_type pos = aux.find('/');
    pos = aux.find('/', pos+1);
    ev.set_evento(aux.substr(0,pos));
    log.insert(ev);
    aux.erase(aux.begin(), aux.begin()+pos);
    }
}

string Log_class::get_output_log(int month_a, int day_a, int month_b, int day_b){
    int ts_a, ts_b, min=999999999, max=0;
    int hours, minutes;
    string output_log;
    ts_a = (month_a-1)*(24*30*60*60) + (day_a-1)*(24*60*60); //Converte os meses e dias de input em segundos
    ts_b = (month_b-1)*(24*30*60*60) + (day_b-1)*(24*60*60);

    Node<Evento>* iterando;
    iterando = log.get_head();

    while(iterando != 0){
        Evento auxiliar = iterando->getVal();
        if((auxiliar.get_timestamp() >= ts_a) && (auxiliar.get_timestamp() <= ts_b)){
            output_log = output_log + auxiliar.get_output() + auxiliar.get_date() + "\n";
            if (auxiliar.get_timestamp()< min){
                min = auxiliar.get_timestamp();  //Salva o menor timestamp encontrado no intervalo de datas
            }
            if (auxiliar.get_timestamp() > max)
            {
                max = auxiliar.get_timestamp(); //Salva o maior timestamp encontrado no intervalo de datas
            }
        }
        if(auxiliar.get_timestamp() > ts_b){ //Evitar procurar no restante da lista, dado que a lista é organizada cronologicamente
            break;
        }
        iterando = iterando->getNext();
    }
    hours = (max-min)/(60*60);  //Calcula as horas entre min e max
    minutes = ((max-min)%(60))*60; //Calcula os minutos
    return output_log + "Tempo em execução: " + std::to_string(hours) + "h "+ std::to_string(minutes) + "min";
}

void Log_class::print(){
    Node<Evento>* iterando; 
    iterando = log.get_head();

    while(iterando != 0){
        Evento auxiliar = iterando->getVal();
        cout << auxiliar.get_output() << auxiliar.get_date() << endl;
        iterando = iterando->getNext();
    }
}