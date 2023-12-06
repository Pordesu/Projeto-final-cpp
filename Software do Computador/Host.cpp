#include "Host.h"

using namespace std;

Host::Host(){
    //Valor inicial  do input é o valor sintético utilizado para o teste do software
    input = "/New angle on X = 2 ,ts:0725817600/New angle on Y = -3 ,ts:0725817666/New angle on Y = 7 ,ts:0728409666/New speed tick = 1 ,ts:0728409670/New speed = 1 ,ts:0728409672/New speed tick = 2 ,ts:0728409680/New speed = 3 ,ts:0728409720/New speed tick = 1 ,ts:0731001600/New angle on Y = -12 ,ts:0731001600/New angle on X = 22 ,ts:0738747600/New angle on Y = -22 ,ts:0738777600/New angle on X = 10 ,ts:1728409720/";
}

void Host::run(){
    char in;
    int day_a=1, month_a=1, day_b=1, month_b=1;
    bool flag;
    cout << "Insira 'l' para requisitar os logs do microcontrolador, ou 'e' para ler os eventos desejados" << endl;
    cin >> in;
    if (in == 'l'){
        //Host.send_UART('C'); // Caractere para o microcontrolador enviar o log 
        //input = Host.read_UART(); //Função de leitura da UART
        log.put_logstr(input);
    }
    else if (in == 'e'){

        flag=true;
        while (flag){  //WHile para proteção de valores inválidos de entrada
        cout << "Insira o dia inicial" << endl;
        cin >> day_a;
        if (day_a > 30 || day_a <= 0){
        cout << "Valor inválido, tente novamente:" << endl;
        flag = true;
        }
        else {flag=false;}
        }
        
        flag=true;
        while (flag){
        cout << "Insira o mês inicial" << endl;
        cin >> month_a;
        if (month_a > 12 || month_a <= 0){
            cout << "Valor inválido, tente novamente:" << endl;
            flag=true;
        }
        else {flag=false;}
        }

        
        flag=true;
        while (flag){
        cout << "Insira o dia final" << endl;
        cin >> day_b;
        if (day_b > 30 || day_b <= 0){
        cout << "Valor inválido, tente novamente:" << endl;
        flag = true;
        }
        else {flag=false;}
        }
        
        flag=true;
        while (flag){
        cout << "Insira o mês final" << endl;
        cin >> month_b;
        if (month_b > 12 || month_b <= 0){
            cout << "Valor inválido, tente novamente:" << endl;
            flag=true;
        }
        else {flag=false;}
        }

        cout << log.get_output_log(month_a, day_a, month_b, day_b) << endl;
    }
    else{
        cout << "Entrada inválida" << endl;
    }


}