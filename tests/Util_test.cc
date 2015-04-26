/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Util_test.cc -- test Util
 *
 * Version: 1.0  04/26/2015 03:32:48 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/Util.h"

using namespace socx;

TEST(TEST_MEMORY_BARRIER, ONLY_TEST)
{
    int i = 0;
    i = 1;
    util::__memory_barrier();
    ASSERT_EQ(1 , i);
}

TEST(TEST_BRANCH_PREDICTION, ONLY_TEST)
{
    int i = 5;
    
    if (likely(i > 0)) {
        i = 1;
    } else {
        i = -1;
    }

    ASSERT_EQ(1, i);
}

