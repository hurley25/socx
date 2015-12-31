/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * TimerFd.h -- timerfd
 *
 * Version: 1.0  12/12/2015 03:22:14 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_TIMERFD_H
#define SOCX_UTIL_TIMERFD_H

#include <sys/timerfd.h>

#include "socx/util/Logger.h"
#include "socx/util/noncopyable.h"

namespace socx {
namespace util {

/**
 * timerfd 定时器的封装
 */
class TimerFd : private noncopyable
{
public:
    /// 构造函数默认创建非阻塞的 timerfd
    TimerFd(int fd_flags = TFD_NONBLOCK)
    {
       timer_fd_ = timerfd_create(CLOCK_REALTIME, fd_flags);
       CHECK(timer_fd_ != 0) << "create timer_fd error, errno: " << errno << " msg:" << strerror(errno);
    }

    ~TimerFd()
    {
        close(timer_fd_);
    }

    /// 启动循环触发的毫秒级别定时器
    int startIntervalMSecTimer(long msec)
    {
        struct timespec tv;
        int ret = clock_gettime(CLOCK_REALTIME, &tv);
        if (ret == -1) {
            return ret;
        }

        struct itimerspec itv;

        long sec = msec / 1000;
        long nsec = (msec % 1000) * 1000 * 1000;

        itv.it_value.tv_sec = tv.tv_sec + sec;
        itv.it_value.tv_nsec = tv.tv_nsec + nsec;
        itv.it_interval.tv_sec = sec;
        itv.it_interval.tv_nsec = nsec;

        return timerfd_settime(timer_fd_, TFD_TIMER_ABSTIME, &itv, NULL);
    }

    /// 启动循环触发的秒级别定时器
    int startIntervalSecTimer(long sec)
    {
        return startIntervalMSecTimer(sec * 1000);
    }

    /// 启动一次性的毫秒级别定时器
    int startOnceMSecTimer(long msec)
    {
        struct timespec tv;
        int ret = clock_gettime(CLOCK_REALTIME, &tv);
        if (ret == -1) {
            return ret;
        }

        struct itimerspec itv;
        bzero(&itv, sizeof(itv));

        long sec = msec / 1000;
        long nsec = (msec % 1000) * 1000 * 1000;

        itv.it_value.tv_sec = tv.tv_sec + sec;
        itv.it_value.tv_nsec = tv.tv_nsec + nsec;

        return timerfd_settime(timer_fd_, TFD_TIMER_ABSTIME, &itv, NULL);
    }

    /// 启动一次性的秒级别定时器
    int startOnceSecTimer(long sec)
    {
        return startOnceMSecTimer(sec * 1000);
    }

    /// 启动一次性的绝对时间触发定时器
    int startAbsTimer(struct timespec &tv)
    {
        struct itimerspec itv;
        bzero(&itv, sizeof(itv));
        itv.it_value = tv;

        return timerfd_settime(timer_fd_, TFD_TIMER_ABSTIME, &itv, NULL);
    }

    /// 停止定时器时间（针对循环定时器）
    int stopTimer()
    {
        struct itimerspec itv;
        bzero(&itv, sizeof(itv));
        return timerfd_settime(timer_fd_, TFD_TIMER_ABSTIME, &itv, NULL);
    }

    /// 获得内部的 timerfd 文件描述符
    int fd() const
    {
        return timer_fd_;
    }

private:
    int timer_fd_;
};

} // namespace util
} // namespace socx

#endif // SOCX_UTIL_TIMERFD_H
