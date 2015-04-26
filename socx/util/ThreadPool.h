/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ThreadPool.h -- Thread Pool
 *
 * Version: 1.0  04/26/2015 03:53:06 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_THREADPOOL_H
#define SOCX_UTIL_THREADPOOL_H

#include <queue>
#include <vector>
#include <string>
#include <mutex>
#include <functional>
#include <thread>
#include <condition_variable>

#include "socx/util/noncopyable.h"

namespace socx {
namespace util {

/**
 * C++11 线程池
 */
class ThreadPool : private noncopyable
{
typedef std::function<void ()> Task;

public:
    explicit ThreadPool(size_t threadNums, std::string name = std::string("ThreadPool"));
    ~ThreadPool();

    /// 启动线程池
    void start();

    /// 结束线程池
    void stop();

    /// 线程池添加任务
    void putTask(Task task);

    /// 设置任务队列最大长度
    void setMaxQueueSize(size_t maxSize)
    {
        maxQueueSize_ = maxSize;
    }

    /// 当前任务队列长度
    size_t queueSize() const
    {
        std::lock_guard<std::mutex> lock(mutex_);

        return queue_.size();
    }

    const std::string &name() const
    {
        return name_;
    }

private:
    bool shutdown_;
    std::string name_;
    size_t threadNums_;
    std::vector<std::thread> threads_;

    mutable std::mutex mutex_;
    std::condition_variable notFullCond_;
    std::condition_variable notEmptyCond_;
    size_t maxQueueSize_;
    std::deque<Task> queue_;

    void threadFunc();
};

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_THREADPOOL_H
