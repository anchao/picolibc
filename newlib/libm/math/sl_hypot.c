/* Copyright (C) 2015 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

#include "fdlibm.h"

#if defined(_NEED_FLOAT_HUGE) && !defined(_HAVE_LONG_DOUBLE_MATH)

long double
hypotl(long double x, long double y)
{
    /* Keep it simple for now...  */
    long double z = sqrtl((x * x) + (y * y));
#ifdef _WANT_MATH_ERRNO
    if (!finite(z) && finite(x) && finite(y))
        errno = ERANGE;
#endif
    return z;
}

#endif
