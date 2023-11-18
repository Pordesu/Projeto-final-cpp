#include "Log_handler.h"

Log_handler::Log_handler(){}

void Log_handler::update_log(Plane pln){

    //Checagem de mudança nos atributos do avião
    //Checagem de mudança nas angulações, aplicado um amortecimento de 3 graus para contar o evento, buscando ignorar oscilações naturais não aplicadas pelo usuário
    int pln_axis_x = get_axis_X(&pln), pastpln_axis_x = get_axis_X(&past_pln);
    if ((pln_axis_x >= (pastpln_axis_x+3))||(pln_axis_x <= (pastpln_axis_x+3))){
        Log.insert(New_angle_ev('X', pln_axis_x));
    }
    int pln_axis_y = get_axis_Y(&pln), pastpln_axis_y = get_axis_Y(&past_pln);
    if ((pln_axis_y >= (pastpln_axis_y+3))||(pln_axis_y <= (pastpln_axis_y+3))){
        Log.insert(New_angle_ev('Y', pln_axis_y));
    }

    //Checagem de mudança de velocidade
    int pln_speed = get_speed(&pln), pastpln_speed = get_speed(&past_pln);
    if (pln_speed != pastpln_speed){
        Log.insert(New_speed_ev(pln_speed));
    }

    //Checagem de mudança de passo de incremento de velocidade (tick)
    int pln_speed_tick = get_speed_tick(&pln), pastpln_speed_tick = get_speed_tick(&past_pln);
    if (pln_speed_tick != pastpln_speed_tick){
        Log.insert(New_speed_ev(pln_speed_tick));
    }

    past_pln = pln; //Atualização do past_pln
}

void Log_handler::uart_send(){
}