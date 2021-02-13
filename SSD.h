#ifndef __SSD_H__
#define __SSD_H__

#define SEGMENTS_BUFFER_SIZE 4
#define SYMBOLES_NUMBER 11
#define SEGMENT_PRIODE 5

//NOTE: include the tByte.

//NOTE: 1- set all data variables.
//state of segment.
typedef enum{
    segment_off = 0,
    segment_on
}segment_state;


typedef enum{
    segment1 = 0,
    segment2,
    segment3,
    segment4
}Segment_name;

void SSD_Init(void);
void update_Segment(void);
void set_Segment_state(Segment_name segment,segment_state state);
void set_Segment_Data(Disp_Values value);
void set_To_Buffer(Segment_name segment, Disp_Values value);


#endif //__SSD_H__
