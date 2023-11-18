#include "Log_handler.h"

int main(){
   DDRB |= (1<<PB5);
   Plane pln;
   while (1){
	pln.run();
   }
   return 0;
}
