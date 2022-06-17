#ifndef     _ALOTYPE_H_
#define     _ALOTYPE_H_

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;
typedef unsigned long long int U64;


typedef char S8;
typedef short S16;
typedef int S32;
typedef long long int S64;

typedef enum LogLevel
{
	LOG_NOTICE = 0,
	LOG_DEBUG,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL,
	LOG_RESERVE,
}LogLevel_e;


#endif