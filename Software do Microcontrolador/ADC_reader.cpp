#include "ADC_reader.h"

ADC_reader::ADC_reader(){
    ADMUX = 0b01000000;  //Inicializa a referência de tensão para o AVCC conectado no arduino ao VCC (5V)
    ADCSRA |= (1<<ADEN) | 4; //Habilita o ADC pelo ADEN e seta os bits de ADPS para (100) 
                            //afim de dividir o clock por 16 e conseguir realizar a leitura de ambas as portas analógicas 
                            //(Foi escolhido o valor mais baixo para maior velocidade possível)
}

int ADC_reader::read_pin(char pin){
    ADMUX = 0x40 | (pin & 0x07); //Seta o pino a ser lido pelo ADC
    ADCSRA |= (1<<ADSC); //Habilita conversão
    while((ADCSRA & (1<<ADSC))); //Loop para esperar a conversão terminar, ADSC é setado para  0 quando acaba
    return ADCW; //Retorna o registrador com o valor lido do  ADC    
}

