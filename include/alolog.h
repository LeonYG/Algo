#ifndef     _ALOLOG_H_
#define     _ALOLOG_H_

#include <stdarg.h>
#include <stdio.h>

#include <string.h>

#include "alotype.h"
#include "common.h"

#ifndef MID
#define MID M_ORIGIN
#endif

void aloPrintf(ModuleId_e module_id, const S8* funcName, U32 line, LogLevel_e level, const S8* format, ...)
__attribute__((format(printf,5,6)));

#define LOG_MAX 512

#define LOG_TERM(module_id, level, format, ...) aloPrintf(module_id, __FUNCTION__, __LINE__, level, format, ##__VA_ARGS__);

#define LOG_TRRM_FATAL(format, ...)        LOG_TERM(MID, LOG_FATAL, format, ##__VA_ARGS__)
#define LOG_TRRM_ERROR(format, ...)        LOG_TERM(MID, LOG_ERROR, format, ##__VA_ARGS__)
#define LOG_TRRM_WARN(format, ...)         LOG_TERM(MID, LOG_WARN, format, ##__VA_ARGS__)
#define LOG_TRRM_DEBUG(format, ...)        LOG_TERM(MID, LOG_DEBUG, format, ##__VA_ARGS__)
#define LOG_TRRM_NOTICE(format, ...)       LOG_TERM(MID, LOG_NOTICE, format, ##__VA_ARGS__)

#endif