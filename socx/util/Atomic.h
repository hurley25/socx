/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Atomic.h -- atomic number
 *
 * Version: 1.0  04/26/2015 02:09:53 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_ATOMIC_H
#define SOCX_UTIL_ATOMIC_H

#include <stdint.h>

#include "socx/util/noncopyable.h"

namespace socx {
namespace util {

/**
 * 原子整数
 */
template <typename T>
class AtomicInt : private noncopyable
{
public:
    AtomicInt() : value_(0) { }
    
    T get()
    {
        // in g++ >= 4.7: __atomic_load_n(&value_, __ATOMIC_SEQ_CST)
        return __sync_val_compare_and_swap(&value_, 0, 0);
    }

    T getAndAdd(T x)
    {
        return __sync_fetch_and_add(&value_, x);
    }

    T addAndGet(T x)
    {
        return getAndAdd(x) + x;
    }

    T incrementAndGet()
    {
        return addAndGet(1);
    }

    T decrementAndGet()
    {
        return addAndGet(-1);
    }

    void add(T x)
    {
        getAndAdd(x);
    }

    void increment()
    {
        incrementAndGet();
    }

    void decrement()
    {
        decrementAndGet();
    }

    T getAndSet(T newValue)
    {
        return __sync_lock_test_and_set(&value_, newValue);
    }

private:
    volatile T value_;
};

typedef AtomicInt<int32_t> AtomicInt32;
typedef AtomicInt<int64_t> AtomicInt64;

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_ATOMIC_H
