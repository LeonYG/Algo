#ifndef     _ALOLOG_H_
#define     _ALOLOG_H_

#include <stdarg.h>
#include <stdio.h>

#include <string.h>

#include "alotype.h"

void aloPrintf(const S8* funcName, U32 line, const S8* format, ...)
	__attribute__((format(printf,3,4)));

#define LOG_MAX 512
#define LOG_TERM(format, ...) aloPrintf(__FUNCTION__, __LINE__, format, __VA_ARGS__)


#endif