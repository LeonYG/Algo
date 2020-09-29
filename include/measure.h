#ifndef     _MEASURE_H_
#define     _MEASURE_H_

#include <sys/time.h>
#include <time.h>

typedef struct measure_time_s{
    time_t start_sec;
    time_t current_sec;
    struct timeval start_eval;
    struct timeval current_eval;
}measure_time_t;

void display_time(measure_time_t* timep);

#endif