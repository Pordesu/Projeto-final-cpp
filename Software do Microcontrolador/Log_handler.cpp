#include "Log_handler.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


bool Received = false; //Variável global para interrupção

void UART_init(uint16_t ubrr){
    // Não é necessário setar o formato do frame pois 8N1 é usado de default
    // seta  o baudrate no registrador UBRR
    UBRR0L = (uint8_t)(ubrr & 0xFF);
    UBRR0H = (uint8_t)(ubrr >> 8);

           // Habilita transmissor e receptor
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1<<RXCIE0); //Habilita interrupção de RX
}

void UART_putc(unsigned char data) //Escreve um char na UART
{
    // Espera pelo buffer de transmissão ser esvaziado
    while(!(UCSR0A & (1 >> UDRE0)));

    // Carrega dado no registrador de transmissão
    UDR0 = data;
}

void UART_puts(char* s) //Escreve uma  string na UART
{
    while(*s > 0) UART_putc(*s++);
}

char UART_getc(void) //Lê um char da UART
{
    // Espera pelo char a ser lido
    while(!(UCSR0A & (1 << RXC0)));

    return UDR0;
}

ISR(USART_RX_vect){ //Tratador de interrupção seta Received = true para escrita do log no pc
    Received = true;
}



Log_handler::Log_handler(){
    UART_init(9600);
    init = time(NULL); //Guarda o valor do tempo na inicialização
}

void Log_handler::update_log(Plane pln){

    //Checagem de mudança nos atributos do avião
    //Checagem de mudança nas angulações, aplicado um amortecimento de 3 graus para contar o evento, buscando ignorar oscilações naturais não aplicadas pelo usuário
    int pln_axis_x = get_axis_X(&pln), pastpln_axis_x = get_axis_X(&past_pln);
    if ((pln_axis_x >= (pastpln_axis_x+3))||(pln_axis_x <= (pastpln_axis_x+3))){
        if (Log.get_size() >= 1000){
        Log.remove_first();
        Log.insert(New_angle_ev('X', pln_axis_x));
        }
        else{
            Log.insert(New_angle_ev('X', pln_axis_x));
        }
    }
    int pln_axis_y = get_axis_Y(&pln), pastpln_axis_y = get_axis_Y(&past_pln);
    if ((pln_axis_y >= (pastpln_axis_y+3))||(pln_axis_y <= (pastpln_axis_y+3))){
        if (Log.get_size() >= 1000){
        Log.remove_first();
        Log.insert(New_angle_ev('Y', pln_axis_y));
        }
        else{
            Log.insert(New_angle_ev('Y', pln_axis_y));
        }
    }

    //Checagem de mudança de velocidade
    int pln_speed = get_speed(&pln), pastpln_speed = get_speed(&past_pln);
    if (pln_speed != pastpln_speed){
        if(Log.get_size()>=1000){
            Log.remove_first();
            Log.insert(New_speed_ev(pln_speed));
        }
        else{
            Log.insert(New_speed_ev(pln_speed));
        }
    }

    //Checagem de mudança de passo de incremento de velocidade (tick)
    int pln_speed_tick = get_speed_tick(&pln), pastpln_speed_tick = get_speed_tick(&past_pln);
    if (pln_speed_tick != pastpln_speed_tick){
        if(Log.get_size()>=1000){
            Log.remove_first();
            Log.insert(New_speedtick_ev(pln_speed_tick));
        }
        else{
            Log.insert(New_speedtick_ev(pln_speed_tick));
        }
    }

    past_pln = pln; //Atualização do past_pln
}

Event Log_handler::get_first(){  //Retorna o primeiro Evento da fila
    return Log.get_head()->getVal();
}
void Log_handler::uart_check_and_send(){ //Checa se foi recebido algo pela UART, se sim, retorna o log
    int aux = 0;
    int vaux[10];
    if(Received){
        for(int i=0; i<Log.get_size();i++){
            UART_putc('/'); //Caractere para dividir cada evento, assim o hospedeiro pode identificar cada evento individualmente
            UART_puts(get_first().get_output());
            aux = get_first().get_timestamp();
            UART_putc(',');UART_putc('t'); UART_putc('s'); UART_putc(':'); // Timestamp
            for(int i=0; i<10; i++){ //Como timestamp é em 32 bits, possui no máximo 10 digitos
                vaux[9-i] = aux%10; //Dígito do inteiro
                aux = aux/10; 
            }
            for(int i=0; i<10; i++){
                UART_putc(vaux[i]);
            }
            Log.remove_first();
    }
    UART_putc('/');
    Received = false;
    }

}
