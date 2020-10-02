unsigned int fib(unsigned int id){
    if(id == 1)
        return 1;
    if(id == 2)
        return 1;
    return fib(id - 1) + fib(id - 2);
}

void fib_parameter_parser(void* private_param_arry, void* raw_arry){return;}
void fib_callback(void* private_param_arry){
    unsigned int * fib_param = (unsigned char *)private_param_arry;
    unsigned int id = fib_param[0];
    printf("%s:%d result:%u",__FUNCTION__,__LINE__,fib(id));
}