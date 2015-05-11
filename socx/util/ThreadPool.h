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

#include <assert.h>

#include "socx/util/noncopyable.h"

namespace socx {
namespace util {

/**
 * C++11 线程池
 */
class ThreadPool : private noncopyable
{
    /// 线程池回调定义
    typedef std::function<void ()> Task;

public:
    /// 线程池构造
    explicit ThreadPool(const std::string &name = std::string());
    ~ThreadPool();

    /// 启动线程池
    void start(int threadNums);

    /// 结束线程池
    void stop();

    /// 线程池添加任务
    void putTask(Task task);

    /// 设置线程池初始化回调
    void setThreadPoolInitCallback(Task callback)
    {
        threadInitCallback_ = callback;
    }

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

private:
    bool isFull() const
    {
        assert(!mutex_.try_lock());
        return maxQueueSize_ > 0 && queue_.size() >= maxQueueSize_;
    }

    Task take();

    void threadFunc();

private:
    std::string name_;
    size_t maxQueueSize_;
    bool running_;

    mutable std::mutex mutex_;
    std::condition_variable notFullCond_;
    std::condition_variable notEmptyCond_;

    Task threadInitCallback_;
    std::vector<std::thread*> threads_;
    std::deque<Task> queue_;
};

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_THREADPOOL_H
