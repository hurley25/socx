/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ThreadPool_test.cc -- for ThreadPool test
 *
 * Version: 1.0  05/12/2015 03:50:28 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <unistd.h>
#include <iostream>
#include <functional>
#include <gtest/gtest.h>

#include "socx/util/Atomic.h"
#include "socx/util/ThreadPool.h"

using namespace socx;

static util::AtomicInt32 count;

void test_task(int num)
{
    count.addAndGet(num);
}

TEST(TEST_THREADPOOL, ONLY_TEST)
{
    util::ThreadPool pool;
    pool.setMaxQueueSize(10);
    pool.start(4);
    
    for (int i = 1; i <= 100; ++i) {
        pool.putTask(std::bind(test_task, i));
    }

    // wait finish
    sleep(1);

    pool.stop();

    ASSERT_EQ(5050, count.get());
}

