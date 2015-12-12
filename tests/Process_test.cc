/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Process_test.cc -- test class Process
 *
 * Version: 1.0  12/12/2015 21:21:56 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string>
#include <iostream>

#include "socx/util/Process.h"

using namespace socx;

TEST(TEST_PROCESS, ONLY_TEST)
{
    ASSERT_EQ(Process::pid(), ::getpid());
    ASSERT_EQ(Process::ppid(), ::getppid());
    ASSERT_EQ(Process::uid(), ::getuid());
    ASSERT_EQ(Process::tid(), ::syscall(SYS_gettid));

    std::string start_time;
    ASSERT_EQ(Process::getStartTime(start_time), 0);
    ASSERT_FALSE(start_time.empty());

    std::string exe_path;
    ASSERT_EQ(Process::getExeFilePath(exe_path), 0);
    ASSERT_FALSE(exe_path.empty());
}

