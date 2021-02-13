#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#define VALUES_SIZE 10
#define DISPLAY_PRIODE 20

typedef enum{
    value_0 = 0,
    value_1,
    value_2,
    value_3,
    value_4,
    value_5,
    value_6,
    value_7,
    value_8,
    value_9,
    value_NULL
}Disp_Values;

void display_Init(void);
void display_Update(void);

#endif //__DISPLAY_H__
