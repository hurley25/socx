/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ClockTimer_test.cc -- test class ClockTimer
 *
 * Version: 1.0  12/12/2015 12:59:56 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/ClockTimer.h"

using namespace socx;

TEST(TEST_CLOCKTIMER, ONLY_TEST)
{
    ASSERT_NE(ClockTimer::rdtsc(), ClockTimer::rdtsc());
    ASSERT_NE(ClockTimer::rdtsc(), ClockTimer::rdtsc());
    ASSERT_NE(ClockTimer::rdtsc(), ClockTimer::rdtsc());
    ASSERT_NE(ClockTimer::rdtsc(), ClockTimer::rdtsc());
    ASSERT_NE(ClockTimer::rdtsc(), ClockTimer::rdtsc());
    
    ASSERT_GE(ClockTimer::nowMs(), ClockTimer::nowMs());
    ASSERT_GE(ClockTimer::nowMs(), ClockTimer::nowMs());
    ASSERT_GE(ClockTimer::nowMs(), ClockTimer::nowMs());
    ASSERT_GE(ClockTimer::nowMs(), ClockTimer::nowMs());
    ASSERT_GE(ClockTimer::nowMs(), ClockTimer::nowMs());

    ASSERT_GE(ClockTimer::nowUs(), ClockTimer::nowUs());
    ASSERT_GE(ClockTimer::nowUs(), ClockTimer::nowUs());
    ASSERT_GE(ClockTimer::nowUs(), ClockTimer::nowUs());
    ASSERT_GE(ClockTimer::nowUs(), ClockTimer::nowUs());
    ASSERT_GE(ClockTimer::nowUs(), ClockTimer::nowUs());

    ASSERT_GE(ClockTimer::nowNs(), ClockTimer::nowNs());
    ASSERT_GE(ClockTimer::nowNs(), ClockTimer::nowNs());
    ASSERT_GE(ClockTimer::nowNs(), ClockTimer::nowNs());
    ASSERT_GE(ClockTimer::nowNs(), ClockTimer::nowNs());
    ASSERT_GE(ClockTimer::nowNs(), ClockTimer::nowNs());
}

