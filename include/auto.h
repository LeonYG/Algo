#ifndef     _AUTO_H_
#define     _AUTO_H_

#include "algo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "common.h"
#include "fcntl.h"

typedef struct auto_driver_s
{
    void (*parameter_parser)(void* private_param_arry, void* raw_arry);
    void (*algo_callback)(void* private_param_arry);
}auto_driver_t;


typedef struct auto_s
{
    auto_driver_t * driver;
    char * algo_name;
    char * param_file_name;
    char * result_file_name;
    unsigned int * runtime_buffer;
    unsigned char execution_times;
}auto_t;

#define MAX_ALGO_MEM        100
#define MAX_PARAM_LEN       1024
char* g_algo_name[MAX_ALGO_MEM] = {};
#ifdef OPTION_FIB
auto_driver_t driver{
    .parameter_parser = fib_parameter_parser,
    .algo_callback = fib_callback
}
*g_algo_name[0] = "fib";
#endif

int parse_common_param(char * file_name, unsigned char* out);

int init(auto_t* handle);

void auto_test(auto_t* handle);

#endif