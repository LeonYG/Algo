#ifndef     _ALOLOG_H_
#define     _ALOLOG_H_

#include <stdarg.h>
#include <stdio.h>

#include <string.h>

#include "alotype.h"

void aloPrintf(const S8* format, const S8* funcName, U32 line, ...)
	__attribute__((format(printf,1,4)));

#define LOG_MAX 512
#define LOG_TERM(format, ...) aloPrintf(format, __FUNCTION__, __LINE__, ##__VA_ARGS__)


#endif