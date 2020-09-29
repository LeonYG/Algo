#include <stdio.h>
#include "hello.h"
#include "measure.h"

int main(void)
{
    say_hello();
    measure_time_t* demo_time = (measure_time_t*)malloc(sizeof(measure_time_t));
    display_time(demo_time);
    free(demo_time);
    return 0;
}