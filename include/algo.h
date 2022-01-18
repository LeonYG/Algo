#ifndef     _ALGO_H_
#define     _ALGO_H_

/*
Calculate Fibonacci number
param       @id:Fibonacci index
return      Fibonacci number
*/
unsigned int fib(unsigned int id);
unsigned int fib_itr(unsigned int id);
unsigned int fib_en(unsigned int id);
void fib_parameter_parser(void* private_param_arry, void* raw_arry);
void fib_callback(void* private_param_arry);

#endif