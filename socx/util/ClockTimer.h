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
#ifndef SOCX_UTIL_CLOCKTIMER_H
#define SOCX_UTIL_CLOCKTIMER_H

#include <time.h>

#include "socx/util/Logger.h"

namespace socx {

/**
 * tsc/ns/us/ms 时间获取
 */
class ClockTimer
{
public:
    static inline uint64_t rdtsc()
    {
        uint64_t rdtsc;
        __asm__ __volatile__("rdtsc" : "=A" (rdtsc));
        return rdtsc;
    }

    static inline uint64_t nowNs()
    {
        struct timespec tv;
        int ret = clock_gettime(CLOCK_REALTIME, &tv);
        CHECK(ret != -1) << "clock_gettime error, errno: " << errno << " msg:" << strerror(errno);
        return (tv.tv_sec * (uint64_t)1000000000 + tv.tv_nsec);
    }

    static inline uint64_t nowUs()
    {
        struct timespec tv;
        int ret = clock_gettime(CLOCK_REALTIME, &tv);
        CHECK(ret != -1) << "clock_gettime error, errno: " << errno << " msg:" << strerror(errno);
        return (tv.tv_sec * (uint64_t)1000000 + tv.tv_nsec / 1000);
    }

    static inline uint64_t nowMs()
    {
        struct timespec tv;
        int ret = clock_gettime(CLOCK_REALTIME, &tv);
        CHECK(ret != -1) << "clock_gettime error, errno: " << errno << " msg:" << strerror(errno);
        return (tv.tv_sec * (uint64_t)1000 + tv.tv_nsec / 1000000);
    }
};

} // namespace socx

#endif  // SOCX_UTIL_CLOCKTIMER_H
