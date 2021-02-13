#include "display.h"
#include "time.h"
#include "SSD.h"

D_Time time;

void display_Init(void){
    set_To_Buffer(segment1,value_0);
    set_To_Buffer(segment2,value_0);
    set_To_Buffer(segment3,value_0);
    set_To_Buffer(segment4,value_0);
}

void display_Update(void){
    static tByte current_time = 0;

    current_time += OS_TICKS;
    if(current_time < DISPLAY_PRIODE){
        return;
    }
    current_time = 0;
    time_Get(&time);

    set_To_Buffer( segment1, time.minutes%10);
    set_To_Buffer( segment2, time.minutes/10);
    set_To_Buffer( segment3, time.hours%10);
    set_To_Buffer( segment4, time.hours/10);

}
