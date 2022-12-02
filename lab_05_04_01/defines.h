#ifndef __DEFINES__H__
#define __DEFINES__H__

#define MAX_LEN                         100
#define MAX_LEN_NAME                    10
#define MAX_LEN_SURNAME                 25
#define NUMBER_MARKS                    4

typedef struct student
{
    char surname[MAX_LEN_SURNAME + 1];
    char name[MAX_LEN_NAME + 1];
    unsigned int marks[NUMBER_MARKS];
} student_t;

#endif
