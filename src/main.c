#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hello.h"
#include "measure.h"
#include "common.h"
#include "algo.h"
#include "alolog.h"
#include "multi_thread_demo.h"

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
    time_measure_display(handle->measure);
//============================
    err_code = reset_start_stamp(handle->measure);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return err_code;
    }
    result = fib_itr(data_usr);
    err_code = update_current_stamp(handle->measure);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return err_code;
    }

    printf("    $result:\n");
    printf("    %u\n",result);

    time_measure_display(handle->measure);
//============================
    err_code = reset_start_stamp(handle->measure);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return err_code;
    }
    result = fib_en(data_usr);
    err_code = update_current_stamp(handle->measure);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
        return err_code;
    }

    printf("    $result:\n");
    printf("    %u\n",result);

    time_measure_display(handle->measure);
    return SUCCESS;
}

int main(void)
{
    say_hello();
    LOG_TERM("math:%s\n","math");

    algo_t* algo_handle = NULL;
    int err_code = SUCCESS;
    
    if(!(algo_handle =(algo_t*)malloc(sizeof(algo_t))))
        return -1;
    err_code = measure_builder(algo_handle);
    if(err_code){
        printf("%s%d errcode:%d\n",__FUNCTION__,__LINE__,err_code);
    }

    test_measure(algo_handle);
    
    free(algo_handle->measure);
    free(algo_handle);

    my_thread_test1();
    return 0;
}