// file timing.h

// Timer
#ifndef _TIMINGS_
#define _TIMINGS_

// old variant
//#include <time.h>
//
//#define MARKTIME(t) \
//	t = (double) clock(); \
//	t /= CLOCKS_PER_SEC;

#include <Windows.h>

static __int64 countsPerSec = 0;
static __int64 curTimer = 0;

// Macros MARKTIME should be used in pair MARKTIME(t2) - MARKTIME(t1)
// that will calculate elapsed time in seconds.

#ifndef MARKTIME
#define MARKTIME(t)														\
	if (countsPerSec == 0)												\
			{QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);};	\
	QueryPerformanceCounter((LARGE_INTEGER*)&curTimer);					\
	t = (double)curTimer / (double)countsPerSec;
#endif

#endif //_TIMINGS_