#include "atmega_libs.h"
#define RS PD2 //Definindo os pinos PDX usados para controle
#define EN PD3

class LCD_display{
    private:
        void cmd(unsigned char code, bool is_Data=false); //Método de envio de comando ou dados para o display
        void EN_pulse(); //Pulso do pino EN para envio de comandos e dados em modo 4 bits
    public:
        LCD_display(); //Construtor
        void Write(char data); // Sobrecarga de função pois pode-se querer 
        void Write(int data); //escrever um número ou caracter no display
        void set_cursor_position(unsigned char pos);

};