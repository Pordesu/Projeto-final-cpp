#include  "LCD_display.h"
#include <string.h>

void LCD_display::EN_pulse(){
    PORTD |= (1<<EN);
    _delay_ms(1);
    PORTD &= ~(1<<EN);
}

void LCD_display::cmd(unsigned char code, bool is_Data){
    if (is_Data){
        PORTD |= (1<<RS); //RS=1 para enviar dados
    }
    else{
        PORTD &= ~(1<<RS); //RS=0 para enviar comando
    }

    
    PORTD = (PORTD & 0x0F) | (code & 0xF0); //Envia os  4 MSB para o display
    EN_pulse();
    PORTD = (PORTD & 0x0F) | code << 4; //Envia os 4 LSB para o display
    EN_pulse();
}

LCD_display::LCD_display(){
    DDRD = 0xFF; //Designa todas as portas PD0 a PD7 como saída
    PORTD &= ~(1<<EN); //Inicializa EN como  0
    _delay_ms(15); //Espera a inicialização do LCD
    cmd(0x02); // Inicializa como 4bits
    cmd(0x28); //Inicializa como modo 4 bits
    cmd(0x0E); //Liga display com cursor desligado
    cmd(0x01); //limpa o display
    _delay_ms(2);
    cmd(0x80);
}   

void LCD_display::Write(char data){
    cmd(data, true); //Escreve o caractere
}


void LCD_display::Write(int data){
    int aux1, aux2, aux3, aux4;
    if (data < 0){
        cmd(45, true);
        data = data*-1;
    }
    else{
        cmd(32, true); 
    }

    aux1 = 48+(data/10);
    aux2 = 48+(data%10);
    cmd(aux1, true);
    cmd(aux2, true);
}

void LCD_display::set_cursor_position(unsigned char pos){
    if(pos < 40){
        cmd(0x80); //Seta o curso para o início da  primeira linha
        for (char i=0; i < pos; i++){
            cmd(0x14);
        }
    }
    else{
        cmd(0xC0);
        for (char i=0; i<(pos-40); i++){
            cmd(0x14);
        }
    }
}