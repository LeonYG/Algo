#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "common.h"
#include "alolog.h"
#include "multi_thread_demo.h"
#include "time.h"

void* my_thread(void){
	pid_t pid = getpid();
	while(1){
		LOG_TERM(M_ORIGIN, LOG_NOTICE, "thread id:%d\n",pid);
		sleep(2);
	}
}

void my_thread_test1(void){
	pthread_t pid;
	S32 ret = pthread_create(&pid, NULL, (void*)my_thread, NULL);
	if(ret != SUCCESS){
		LOG_TERM(M_ORIGIN, LOG_NOTICE, "creat thread error:%d\n",ret);
		return;
	}
	pthread_join(pid, NULL);

	return;
}