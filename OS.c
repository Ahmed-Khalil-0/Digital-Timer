#include "OS.h"
#include "SSD. h"
#include "display.h"
#include "time.h"


void OS_Init(void){
    TIMER_PRESCAlER;
    PRESCALER_RATE_SELECT;
    DISABLE_TIMER;
}

void OS_Start(void){
    CLEAR_TIMER_FLAG;
    UPDATE_TIMER(OS_TICKS);
    ENABLE_INTERRUPT;
    ENABLE_GLOBAL_INTERRUPT;
    ENABLE_TIMER;
}


void OS_Update(void) __interrupt 0
{
    //reload the TIMER REGISTER.
    CLEAR_TIMER_FLAG;
    UPDATE_TIMER(OS_TICKS);

    //functions to update
    RC7 = 1 ^ RC7;
    update_Segment();
    display_Update();
    time_Update();
}
