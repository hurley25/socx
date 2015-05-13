/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * CountDownLatch.h -- for count down latch
 *
 * Version: 1.0  05/13/2015 04:59:35 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_COUNTDOWNLATCH_H
#define SOCX_UTIL_COUNTDOWNLATCH_H

#include <glog/logging.h>

#include <mutex>
#include <condition_variable>

#include "noncopyable.h"

namespace socx {
namespace util {

/**
 * 倒计时门闩同步
 */
class CountDownLatch : private noncopyable
{
public:
    explicit CountDownLatch(int count) : count_(count)
    {
    }

    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex_);

        while (count_ > 0) {
            cond_.wait(lock);
        }
    }

    void countDown()
    {
        std::lock_guard<std::mutex> lock(mutex_);

        -- count_;
        if (count_ == 0) {
            cond_.notify_all();
        }
    }

    int getCount() const
    {
        std::lock_guard<std::mutex> lock(mutex_);

        return count_;
    }

private:
    mutable std::mutex mutex_;
    std::condition_variable cond_;
    int count_;
};

} // namespace util
} // namespace socx

#endif // SOCX_UTIL_COUNTDOWNLATCH_H
