#include <stdio.h>
#include "algo.h"
#include "alolog.h"

unsigned int fib(unsigned int id){
    if(id == 1)
        return 1;
    if(id == 2)
        return 1;
    return fib(id - 1) + fib(id - 2);
}
unsigned int fib_itr(unsigned int id){
    printf("--->\n");
    LOG_TERM("mather %d\n",50);
    if(id == 1)
        return 1;
    if(id == 2)
        return 1;
    unsigned int a = 1, b = 1;
    unsigned x = 0;
    for(unsigned int i = 3; i<=id;i++){
        x = a + b;
        a = b;
        b = x;
    }
    return x;
}
unsigned int g_rec[100] = {0};
unsigned int call(unsigned int id){
    if(g_rec[id-1])
        return g_rec[id-1];
    g_rec[id-1] = call(id - 1) + call(id - 2);
    return g_rec[id-1];
}
unsigned int fib_en(unsigned int id){
    g_rec[0] = 1;
    g_rec[1] = 1;
    return call(id);
}

void fib_parameter_parser(void* private_param_arry, void* raw_arry){return;}
void fib_callback(void* private_param_arry){
    unsigned int * fib_param = (unsigned int  *)private_param_arry;
    unsigned int id = fib_param[0];
    printf("%s:%d result:%u",__FUNCTION__,__LINE__,fib(id));
}
