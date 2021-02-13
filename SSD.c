#include "SSD. h"
#include "display.h"
#include "OS.h"
#include "GPIO.h"

Disp_Values segments_Values[SEGMENTS_BUFFER_SIZE];
//toggling the 3
// static void dot_Toggling(void);

//better to make it static as symboles are constent.
static tByte segment_Symboles[SYMBOLES_NUMBER]{
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b00000000,
};

void SSD_Init(void){

    //init the GPIOS for segments.(PORT D CONTROL)
    GPIO_InitPort(GPIO_PORTD_CONTROL, GPIO_OUT);
    //init the GPIOS for segments.(PINS B CONTROL)
    GPIO_InitPortPin(GPIO_PORTB_CONTROL, GPIO_PIN_4, GPIO_OUT);
    GPIO_InitPortPin(GPIO_PORTB_CONTROL, GPIO_PIN_5, GPIO_OUT);
    GPIO_InitPortPin(GPIO_PORTB_CONTROL, GPIO_PIN_6, GPIO_OUT);
    GPIO_InitPortPin(GPIO_PORTB_CONTROL, GPIO_PIN_7, GPIO_OUT);

    //init the GPIOS for segments.(PORT D DATA)
    set_Segment_Data(value_NULL);
    //init the GPIOS for segments.(PINS B DATA)
    set_Segment_state(segment1, segment_off);
    set_Segment_state(segment2, segment_off);
    set_Segment_state(segment3, segment_off);
    set_Segment_state(segment4, segment_off);

}

void update_Segment(void){
    static tByte current_Time = 0;
    static Segment_name current_Segment = segment1;
    current_Time += OS_TICKS;
    if(current_Time < SEGMENT_PRIODE){
        return;
    }
    current_Time = 0;
    //turning off all SEGEMENTS.
    set_Segment_state(segment1,segment_off);
    set_Segment_state(segment2,segment_off);
    set_Segment_state(segment3,segment_off);
    set_Segment_state(segment4,segment_off);

    set_Segment_Data(segments_Values[current_Segment]);

    set_Segment_state(current_Segment,segment_on);

    current_Segment++;
    if(current_Segment == segment4){
        current_Segment = segment1;
    }

}

void set_Segment_Data(Disp_Values value){
    GPIO_WritePort(GPIO_PORTD_DATA, segment_Symboles[value]);
}

//the only interaction outside.(DISPLAY USE IT)
void set_To_Buffer(Segment_name segment, Disp_Values value){
    segments_Values[segment] = value;
}

// static void dot_Toggling(void){
//     static tByte current_state = segment_off;
//     GPIO_WritePort(GPIO_PORTD_DATA,0b10000000);
//     current_state = GPIO_ReadPortPin(GPIO_PORTD_DATA, GPIO_PIN_5);
//
//     if(current_state == segment_on){
//         GPIO_WritePortPin(GPIO_PORTB_DATA, GPIO_PIN_5, segment_off);
//         current_state = segment_off;
//     }else{
//         GPIO_WritePortPin(GPIO_PORTB_DATA, GPIO_PIN_5, segment_on);
//         current_state = segment_on;
//     }
// }

void set_Segment_state(Segment_name segment,segment_state state){
    switch(segment){
        case Segment1:
            GPIO_WritePortPin(GPIO_PORTB_DATA, GPIO_PIN_4, state);
        break;
        case Segment2:
            GPIO_WritePortPin(GPIO_PORTB_DATA, GPIO_PIN_5, state);
        break;
        case Segment3:
            GPIO_WritePortPin(GPIO_PORTB_DATA, GPIO_PIN_6, state);
        break;
        case Segment4:
            GPIO_WritePortPin(GPIO_PORTB_DATA, GPIO_PIN_7, state);
        break;
        default:
        break;
    }
}
