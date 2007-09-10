#ifndef __MATH_H__
#define __MATH_H__

#if (defined(__ppc__) || defined(__ppc64__))
#include <architecture/ppc/math.h>
#elif (defined(__i386__) || defined(__x86_64__))
#include <architecture/i386/math.h>
#elif defined(__arm__)
#include <architecture/arm/math.h>
#endif

#endif

