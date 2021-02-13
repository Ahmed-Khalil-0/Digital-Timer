#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "time.h"
#include "OS.h"
#include "SSD.h"
#include "display.h"
#include "GPIO.h"

tWord __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;
tByte flag = 0;

void main(void)
{
    time_Init();
    display_Init();
    OS_Init();
    OS_Start();

    TRISC7 = 0;
    RC7 = 0;
    while (1)
    {
        /* Do nothing */
        while (flag == 0);

        flag = 0;

    }
}
