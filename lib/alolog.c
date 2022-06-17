#include <string.h>
#include "common.h"
#include "alotype.h"
#include "alolog.h"

#define LOG_BUFFER_RESAVE 128

char* glogLevelStr[LOG_RESERVE]={
	[LOG_NOTICE] = "NOTICE",
	[LOG_DEBUG]  = "DEBUG",
	[LOG_WARN]   = "WARN",
	[LOG_ERROR]  = "ERROR",
	[LOG_FATAL]  = "FATAL",
};

void aloPrintf(const S8* funcName, U32 line, LogLevel_e level, const S8* format, ...)
{
	U32 buffer_size = LOG_MAX+LOG_BUFFER_RESAVE;
	S8 buffer[LOG_MAX+LOG_BUFFER_RESAVE] = {0};
	S32 len = 0;
	va_list valist;

	len = snprintf(buffer+strlen(buffer), buffer_size - strlen(buffer) - 1, "%s:%d ", funcName, line);
	va_start(valist, format);
	len += vsnprintf(buffer+strlen(buffer), buffer_size - strlen(buffer) - 1, format, valist);
	va_end(valist);
	printf("[%s] %s", glogLevelStr[level], buffer);
}