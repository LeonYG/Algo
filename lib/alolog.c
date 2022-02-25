#include <string.h>
#include "common.h"
#include "alotype.h"
#include "alolog.h"

#define LOG_BUFFER_RESAVE 128

void aloPrintf(const S8* format, const S8* funcName, U32 line, ...)
{
	printf("enen\n");
	U32 buffer_size = LOG_MAX+LOG_BUFFER_RESAVE;
	S8 buffer[LOG_MAX+LOG_BUFFER_RESAVE];
	S32 len = 0;
	va_list valist;

	len = snprintf(buffer+strlen(buffer), buffer_size - strlen(buffer) - 1, "%s:%d ", funcName, line);
	va_start(valist, format);
	len += snprintf(buffer+strlen(buffer), buffer_size - strlen(buffer) - 1, format, valist);
	va_end(valist);
	printf(buffer);
}