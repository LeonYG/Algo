#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hello.h"
#include "measure.h"
#include "common.h"

typedef struct algo_s
{
    measure_time_t* measure;
}algo_t;

int measure_builder(algo_t* handle){
    handle->measure = (measure_time_t*)malloc(sizeof(measure_time_t));
    if(!handle->measure)
        return NOMEMERY;
    display_time(handle->measure);
    return SUCCESS;
}

unsigned int fib(unsigned int id){
    if(id == 1)
        return 1;
    if(id == 2)
        return 1;
    return fib(id - 1) + fib(id - 2);
}

int test_measure(algo_t* handle){
    int err_code = SUCCESS;
    printf("    \n$give a num:\n");
    unsigned int data_usr;
    scanf("%u",&data_usr);

    err_code = reset_start_stamp(handle->measure);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return err_code;
    }
    unsigned int result = fib(data_usr);
    err_code = update_current_stamp(handle->measure);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return err_code;
    }

    printf("    $result:\n");
    printf("    %u\n",result);
    printf("    $time used: %lu(s) %lu(us)\n",
        (handle->measure->current_sec - handle->measure->start_sec),
        (handle->measure->current_eval.tv_usec - handle->measure->start_eval.tv_usec));

    return SUCCESS;
}

int main(void)
{
    say_hello();

    algo_t* algo_handle = NULL;
    int err_code = SUCCESS;
    if(!(algo_handle =(algo_t*)malloc(sizeof(algo_t))))
        return -1;
    err_code = measure_builder(algo_handle);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
    }

    test_measure(algo_handle);

    free(algo_handle);
    return 0;
}