/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * BlockingQueue_test.cc -- test class BlockingQueue
 *
 * Version: 1.0  2015年04月26日 17时35分25秒
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/BlockingQueue.h"

using namespace socx;

TEST(TEST_BLOCKQUEUE_ONETHREAD, ONLY_TEST)
{
    util::BlockingQueue<int> queue;

    ASSERT_EQ(0 , queue.size());

    for (int i = 1; i <= 1000000; ++i) {
        queue.put(i);
        ASSERT_EQ(i, queue.size());
    }
    ASSERT_EQ(1000000, queue.size());

    for (int i = 1; i <= 1000000; ++i) {
        ASSERT_EQ(i, queue.take());
        ASSERT_EQ(1000000 - i, queue.size());
    }
    ASSERT_EQ(0, queue.size());
}

