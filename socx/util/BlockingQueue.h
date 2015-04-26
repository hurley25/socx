/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * BlockingQueue.h -- Blocking Queue
 *
 * Version: 1.0  04/26/2015 03:59:49 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_BLOCKINGQUEUE_H
#define SOCX_UTIL_BLOCKINGQUEUE_H

#include <deque>
#include <mutex>
#include <condition_variable>

#include "socx/util/noncopyable.h"

namespace socx {
namespace util {

/**
 * 无界阻塞队列(生产者/消费者队列)
 */
template <typename T>
class BlockingQueue : private noncopyable
{
public:
    BlockingQueue() { }
    ~BlockingQueue() { }

    /// 添加任务
    void put(T task)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push_back(task);
        notEmptyCond_.notify_one();
    }

    /// 取得任务
    T take()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        // 避免虚假唤醒
        while (queue_.empty()) {
            notEmptyCond_.wait(lock);
        }
        T task(queue_.front());
        queue_.pop_front();

        return task;
    }

    /// 获得队列长度
    size_t size() const
    {
        std::lock_guard<std::mutex> lock(mutex_);

        return queue_.size();
    }

    /// 判断队列是否为空
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mutex_);

        return queue_.empty();
    }

private:
    mutable std::mutex mutex_;
    std::condition_variable notEmptyCond_;
    std::deque<T> queue_;
};

} // namespace util
} // namespace socx


#endif  // SOCX_UTIL_BLOCKINGQUEUE_H
