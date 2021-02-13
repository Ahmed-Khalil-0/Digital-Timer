#ifndef __OS_H__
#define __OS_H__
#include "timer.h"

#define OS_TICKS (5)

typedef unsigned char tByte;
typedef unsigned int tWord;

void OS_Init(void);
void OS_Start(void);
void OS_Update(void) __interrupt 0;

#endif //__OS_H__
