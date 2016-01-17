/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * NumberUtil_test.cc -- test NumberUtil
 *
 * Version: 1.0  01/17/2016 16:01:48 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/NumberUtil.h"

using namespace socx;

TEST(TEST_ISP2, ONLY_TEST)
{
    // 2 ^ 0 == 1
    ASSERT_EQ(util::isp2(1), true);
    ASSERT_EQ(util::isp2(2), true);
    ASSERT_EQ(util::isp2(4), true);
    ASSERT_EQ(util::isp2(1024), true);
    ASSERT_EQ(util::isp2(4096), true);
    ASSERT_EQ(util::isp2(2147483648U), true);

    ASSERT_EQ(util::isp2(15), false);
    ASSERT_EQ(util::isp2(126), false);
    ASSERT_EQ(util::isp2(3654), false);
    ASSERT_EQ(util::isp2(215525), false);
    ASSERT_EQ(util::isp2(24154588), false);
}

TEST(TEST_UINT32P2, ONLY_TEST)
{
    ASSERT_EQ(util::uint32p2(1), 1);
    ASSERT_EQ(util::uint32p2(3), 4);
    ASSERT_EQ(util::uint32p2(5), 8);
    ASSERT_EQ(util::uint32p2(13), 16);
    ASSERT_EQ(util::uint32p2(23), 32);
    ASSERT_EQ(util::uint32p2(52), 64);
    ASSERT_EQ(util::uint32p2(127), 128);
    ASSERT_EQ(util::uint32p2(250), 256);
    ASSERT_EQ(util::uint32p2(452), 512);
    ASSERT_EQ(util::uint32p2(924), 1024);
    ASSERT_EQ(util::uint32p2(1998), 2048);
    ASSERT_EQ(util::uint32p2(3587), 4096);
    ASSERT_EQ(util::uint32p2(4096), 4096);
    ASSERT_EQ(util::uint32p2(2100000000), 2147483648U);
    ASSERT_EQ(util::uint32p2(2147483648U), 2147483648U);
}

