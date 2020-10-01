unsigned int fib(unsigned int id){
    if(id == 1)
        return 1;
    if(id == 2)
        return 1;
    return fib(id - 1) + fib(id - 2);
}