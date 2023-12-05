#include "Axis_reader.h"


int Axis_reader::read_axis(char axis){
    float result=read_pin(axis);
    return ((result/1024)*90 - 45); //Converte a leitura do adc em graus de inclinação do avião
                                      // o resultado é entregue entre um intervalo de -45º a 45º
}