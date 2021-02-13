#ifndef __TIMER_H__
#define __TIMER_H__
#include "OS.h"

#define SECONDS_PIROID (1000)

typedef struct{

    //NOTE: include the tByte defintion
    //NOTE:initialization allowed or not.
    tByte seconds;
    tByte minutes;
    tByte hours;
}D_Time;

void time_Init(void);
void time_Update(void);
void time_Get(D_Time*);

#endif //__TIMER_H__
