/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * ThreadPool.cc -- Thread Pool
 *
 * Version: 1.0  04/26/2015 03:52:52 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#include "socx/util/ThreadPool.h"

namespace socx {
namespace util {

/// 线程池构造
ThreadPool::ThreadPool(const std::string &name)
    : name_(name),
      maxQueueSize_(0),
      running_(false)
{
}

ThreadPool::~ThreadPool()
{
    if (running_) {
        stop();
    }
}

/// 启动线程池
void ThreadPool::start(int threadNums)
{
    assert(threads_.empty() && threadNums > 0);
    running_ = true;
    threads_.reserve(threadNums);
    for (int i = 0; i < threadNums; ++i) {
        threads_.push_back(new std::thread(&ThreadPool::threadFunc, this));
    }
}

/// 结束线程池
void ThreadPool::stop()
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        running_ = false;
        notEmptyCond_.notify_all();
    }
    for (auto &thread : threads_) {
        thread->join();
        delete thread;
    }
}

/// 线程池添加任务
void ThreadPool::putTask(Task task)
{
    if (threads_.empty()) {
        task();
    } else {
        std::unique_lock<std::mutex> lock(mutex_);
        while (isFull()) {
            notFullCond_.wait(lock);
        }
        assert(!isFull());
        queue_.push_back(task);
        notEmptyCond_.notify_one();
    }
}

ThreadPool::Task ThreadPool::take()
{
    std::unique_lock<std::mutex> lock(mutex_);
    while (queue_.empty() && running_) {
        notEmptyCond_.wait(lock);
    }

    Task task;
    if (!queue_.empty()) {
        task = queue_.front();
        queue_.pop_front();
        if (maxQueueSize_ > 0) {
            notFullCond_.notify_one();
        }
    }

    return task;
}

void ThreadPool::threadFunc()
{
    if (threadInitCallback_) {
        threadInitCallback_();
    }

    while (running_) {
        Task task(take());
        if (task) {
            task();
        }
    }
}

} // namespace util
} // namespace socx

