
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "measure.h"
#include "common.h"

/*year month day hour min sec sec*e-3 sec*e-6*/
void display_time(measure_time_t* timep){
    timep->start_sec = time(NULL);
    struct tm* tmp_tm = NULL;
    tmp_tm = gmtime(&(timep->start_sec));
    printf("year:%d mon%d wday:%d day:%d hour:%d min:%d sec:%d\n",
        tmp_tm->tm_year+1900,tmp_tm->tm_mon+1,tmp_tm->tm_wday,tmp_tm->tm_yday,
        tmp_tm->tm_hour,tmp_tm->tm_min,tmp_tm->tm_sec);
    struct timeval tmp_eval;
    gettimeofday(&tmp_eval,NULL);
    printf("sec*e-3:%lu sec*e-6:%ld\n",tmp_eval.tv_usec/1000,tmp_eval.tv_usec);
    memcpy(&(timep->start_eval),&tmp_eval,sizeof(struct timeval));
}

int reset_start_stamp(measure_time_t* timep){
    if(!timep)
        return UNEXPECTED;
    timep->start_sec = time(NULL);
    // gmtime(&(timep->start_sec));
    gettimeofday(&(timep->start_eval),NULL);
    return SUCCESS;
}

int update_current_stamp(measure_time_t* timep){
    if(!timep)
        return UNEXPECTED;
    timep->current_sec = time(NULL);
    // gmtime(&(timep->current_sec));
    gettimeofday(&(timep->current_eval),NULL);
    return SUCCESS;
}