#include "time.h"

static D_Time d_time;

void time_Init(void){

    d_time.seconds = 0;
    d_time.minutes = 0;
    d_time.hours = 0;

}


void time_Update(void){
    //check if the time comes, TIME_PIROID
    static tWord current_sec_timing += OS_TICKS;
    if(current_sec_timing < SECONDS_PIROID){
        return;
    }
    current_sec_timing = 0;
    d_time.seconds++;
    if(d_time.seconds == 60)
    {
        d_time.seconds = 0;
        d_time.minutes++;
        if(d_time.minutes == 60)
        {
            d_time.minutes = 0;
            d_time.hours++;
            if(d_time.hours == 24)
            {
                d_time.hours = 0;
            }
        }
    }
}


void time_Get(D_Time* time){
    time->seconds = d_time.seconds;
    time->minutes = d_time.minutes;
    time->hours   = d_time.hours;

}
