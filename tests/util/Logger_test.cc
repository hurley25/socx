/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Logger_test.cc -- test class Logger.
 *
 * Version: 1.0  04/25/2015 06:16:10 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include <gtest/gtest.h>

#include "socx/util/Logger.h"

using namespace socx;

TEST(TEST_LOG_TO_STDERR, ONLY_TEST)
{
    util::Logger &logger = util::Logger::instance();
 
    logger.setLogToStderr();

    LOG(INFO) << "log test";

    int valueint = 10;
    LOG_IF(ERROR, valueint != 10) << "valueint != 10";
}

TEST(TEST_SIGNAL_HANDLER, ONLY_TEST)
{
    util::Logger &logger = util::Logger::instance();

    logger.installFailureSignalHandler();

    // test SIFSEGV signal
    //int *i = NULL;
    //*i = 9527;
    //(void) i;  // make g++ happy
}

