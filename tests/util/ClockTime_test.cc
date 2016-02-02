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

#include "socx/util/ClockTime.h"

using namespace socx::util;

TEST(TEST_CLOCKTIMER, ONLY_TEST)
{
    ASSERT_NE(ClockTime::rdtsc(), ClockTime::rdtsc());
    ASSERT_NE(ClockTime::rdtsc(), ClockTime::rdtsc());
    ASSERT_NE(ClockTime::rdtsc(), ClockTime::rdtsc());
    ASSERT_NE(ClockTime::rdtsc(), ClockTime::rdtsc());
    ASSERT_NE(ClockTime::rdtsc(), ClockTime::rdtsc());
    
    ASSERT_GE(ClockTime::nowMs(), ClockTime::nowMs());
    ASSERT_GE(ClockTime::nowMs(), ClockTime::nowMs());
    ASSERT_GE(ClockTime::nowMs(), ClockTime::nowMs());
    ASSERT_GE(ClockTime::nowMs(), ClockTime::nowMs());
    ASSERT_GE(ClockTime::nowMs(), ClockTime::nowMs());

    ASSERT_GE(ClockTime::nowUs(), ClockTime::nowUs());
    ASSERT_GE(ClockTime::nowUs(), ClockTime::nowUs());
    ASSERT_GE(ClockTime::nowUs(), ClockTime::nowUs());
    ASSERT_GE(ClockTime::nowUs(), ClockTime::nowUs());
    ASSERT_GE(ClockTime::nowUs(), ClockTime::nowUs());

    ASSERT_GE(ClockTime::nowNs(), ClockTime::nowNs());
    ASSERT_GE(ClockTime::nowNs(), ClockTime::nowNs());
    ASSERT_GE(ClockTime::nowNs(), ClockTime::nowNs());
    ASSERT_GE(ClockTime::nowNs(), ClockTime::nowNs());
    ASSERT_GE(ClockTime::nowNs(), ClockTime::nowNs());
}

