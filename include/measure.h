#ifndef     _MEASURE_H_
#define     _MEASURE_H_

#include <sys/time.h>
#include <time.h>
#include "alotype.h"

#ifndef     _FIB_H_
#define     _FIB_H_

#define MID M_FIB

#endif

typedef struct measure_time_s{
    time_t start_sec;
    time_t current_sec;
    struct timeval start_eval;
    struct timeval current_eval;
}measure_time_t;

void display_time(measure_time_t* timep);
int reset_start_stamp(measure_time_t* timep);
int update_current_stamp(measure_time_t* timep);
void time_measure_display(measure_time_t* timep);

#endif