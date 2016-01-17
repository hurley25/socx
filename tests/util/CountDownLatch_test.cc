/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * CountDownLatch_test.cc -- for test CountDownLatch
 *
 * Version: 1.0  05/13/2015 05:31:36 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <thread>

#include <gtest/gtest.h>

#include "socx/util/CountDownLatch.h"
#include "socx/util/Atomic.h"

using namespace socx;

static util::AtomicInt32 count;
static util::CountDownLatch countDown(10);

void thread_func(int num)
{
    count.add(num);
    countDown.countDown();
}

TEST(TEST_COUNTDOWNLATCH, ONLY_TEST)
{
    std::thread *thread[10];
    
    for (int i = 0; i < 10; ++i) {
        thread[i] = new std::thread(thread_func, 10);
    }

    countDown.wait();
    ASSERT_EQ(100, count.get());
    
    for (int i = 0; i < 10; ++i) {
        thread[i]->join();
    }
}

