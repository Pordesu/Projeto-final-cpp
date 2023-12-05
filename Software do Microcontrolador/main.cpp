#include "Log_handler.h"


int main(){
   DDRB |= (1<<PB5);
   Plane pln;
   Log_handler log;
   while (1){
	pln.run();
   log.update_log(pln);
   log.uart_check_and_send();
   }
   return 0;
}
