#include "atmega_libs.h"
class ADC_reader{
    public:
        int Read_pin(char pin); // Rotina para leitura do valor de saída do adc no pino especificado
        ADC_reader(); //Construtor
};