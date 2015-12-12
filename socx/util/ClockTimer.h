/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ClockTimer.hpp -- ClockTimer
 *
 * Version: 1.0  12/12/2015 12:37:26 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */
#ifndef SOCX_UTIL_CLOCKTIMER_H_
#define SOCX_UTIL_CLOCKTIMER_H_

#include <time.h>

namespace socx {

class ClockTimer
{
public:
    static uint64_t rdtsc()
    {
        uint64_t rdtsc;
        __asm__ __volatile__("rdtsc" : "=A" (rdtsc));
        return rdtsc;
    }

    static uint64_t nowNs()
    {
        struct timespec tv;
        clock_gettime(CLOCK_REALTIME, &tv);
        return (tv.tv_sec * (uint64_t)1000000000 + tv.tv_nsec);
    }

    static uint64_t nowUs()
    {
        struct timespec tv;
        clock_gettime(CLOCK_REALTIME, &tv);
        return (tv.tv_sec * (uint64_t)1000000 + tv.tv_nsec / 1000);
    }

    static uint64_t nowMs()
    {
        struct timespec tv;
        clock_gettime(CLOCK_REALTIME, &tv);
        return (tv.tv_sec * (uint64_t)1000 + tv.tv_nsec / 1000000);
    }
};

} // namespace socx

#endif  // SOCX_UTIL_CLOCKTIMER_H_