#ifndef _UART_
#define _UART_

#include "atmega_libs.h"

//Definições  e implementações das funções de utilização da UART

bool Received = false; //Variável global para interrupção

void UART_init(uint16_t ubrr){
    // Não é necessário setar o formato do frame pois 8N1 é usado de default
    // seta  o baudrate no registrador UBRR
    UBRR0L = (uint8_t)(ubrr & 0xFF);
    UBRR0H = (uint8_t)(ubrr >> 8);

           // Habilita transmissor e receptor
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0); //Habilita interrupção de RX
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

#endif

