/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Atomic_test.cc -- test class Atomic
 *
 * Version: 1.0  04/26/2015 02:23:56 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/Atomic.h"

using namespace socx;

TEST(TEST_ATOMIC_INT32, ONLY_TEST)
{
    util::AtomicInt32 refCount;

    ASSERT_EQ(0, refCount.get());

    ASSERT_EQ(1, refCount.incrementAndGet());
    ASSERT_EQ(2, refCount.incrementAndGet());
    ASSERT_EQ(3, refCount.incrementAndGet());
    ASSERT_EQ(2, refCount.decrementAndGet());
    ASSERT_EQ(1, refCount.decrementAndGet());
    ASSERT_EQ(0, refCount.decrementAndGet());

    ASSERT_EQ(0, refCount.getAndSet(10));
    ASSERT_EQ(10, refCount.get());
    ASSERT_EQ(10, refCount.getAndSet(0));
    ASSERT_EQ(0, refCount.get());

    ASSERT_EQ(0, refCount.getAndAdd(5));
    ASSERT_EQ(5, refCount.get());
    ASSERT_EQ(5, refCount.getAndAdd(-5));
    ASSERT_EQ(0, refCount.get());

    ASSERT_EQ(5, refCount.addAndGet(5));
    ASSERT_EQ(0, refCount.addAndGet(-5));

    refCount.add(5);
    ASSERT_EQ(5, refCount.get());

    refCount.add(-5);
    ASSERT_EQ(0, refCount.get());
    
    refCount.increment();
    ASSERT_EQ(1, refCount.get());
    refCount.decrement();
    ASSERT_EQ(0, refCount.get());
}

TEST(TEST_ATOMIC_INT64, ONLY_TEST)
{
    util::AtomicInt64 refCount;

    ASSERT_EQ(0, refCount.get());

    ASSERT_EQ(1, refCount.incrementAndGet());
    ASSERT_EQ(2, refCount.incrementAndGet());
    ASSERT_EQ(3, refCount.incrementAndGet());
    ASSERT_EQ(2, refCount.decrementAndGet());
    ASSERT_EQ(1, refCount.decrementAndGet());
    ASSERT_EQ(0, refCount.decrementAndGet());

    ASSERT_EQ(0, refCount.getAndSet(10));
    ASSERT_EQ(10, refCount.get());
    ASSERT_EQ(10, refCount.getAndSet(0));
    ASSERT_EQ(0, refCount.get());

    ASSERT_EQ(0, refCount.getAndAdd(5));
    ASSERT_EQ(5, refCount.get());
    ASSERT_EQ(5, refCount.getAndAdd(-5));
    ASSERT_EQ(0, refCount.get());

    ASSERT_EQ(5, refCount.addAndGet(5));
    ASSERT_EQ(0, refCount.addAndGet(-5));

    refCount.add(5);
    ASSERT_EQ(5, refCount.get());

    refCount.add(-5);
    ASSERT_EQ(0, refCount.get());
    
    refCount.increment();
    ASSERT_EQ(1, refCount.get());
    refCount.decrement();
    ASSERT_EQ(0, refCount.get());
}

