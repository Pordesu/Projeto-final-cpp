#ifndef _NEW_DEL_
#define _NEW_DEL_
//Implementação dos operadores new e delete utilizando maloc pois o avr-g++ não possui suporte
// para essas operações

#include <stdlib.h>

void* operator new(size_t size);
void operator delete(void* ptr, unsigned int x);

__extension__ typedef int __guard __attribute__((mode(__DI__)));
extern  "C" int __cxa_guard_acquire(__guard*);
extern  "C" void __cxa_guard_release (__guard*);
extern  "C" void __cxa_guard_abort (__guard*);
extern  "C" void __cxa_pure_virtual(void);

#endif