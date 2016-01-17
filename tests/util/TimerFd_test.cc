/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * TimerFd_test.cc -- test class TimerFd_test
 *
 * Version: 1.0  12/12/2015 16:45:56 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/TimerFd.h"

#include <time.h>

using namespace socx::util;

TEST(TEST_TIMERFD, ONLY_TEST)
{
    TimerFd timer_fd1(0);
    TimerFd timer_fd2;

    time_t stime = time(NULL);

    timer_fd1.startOnceSecTimer(1);
    timer_fd2.startIntervalMSecTimer(100);

    uint64_t fdtime1, fdtime2;
    ssize_t rsize1 = read(timer_fd1.fd(), &fdtime1, sizeof(uint64_t));
    ssize_t rsize2 = read(timer_fd2.fd(), &fdtime2, sizeof(uint64_t));
    timer_fd2.stopTimer();

    ASSERT_EQ(rsize1, sizeof(uint64_t));
    ASSERT_EQ(rsize2, sizeof(uint64_t));
    ASSERT_EQ(fdtime1, 1);
    ASSERT_EQ(fdtime2, 10);

    timer_fd2.stopTimer();
    sleep(1);
    rsize2 = read(timer_fd2.fd(), &fdtime2, sizeof(uint64_t));
    ASSERT_EQ(fdtime2, 10);

    time_t etime = time(NULL);

    ASSERT_EQ(stime + 2, etime);
}

