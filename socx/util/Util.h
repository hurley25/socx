/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Util.h -- memory barrier, branch prediction and etc ...
 *
 * Version: 1.0  04/26/2015 03:28:26 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_UTIL_H
#define SOCX_UTIL_UTIL_H

namespace socx {
namespace util {

/// 内存屏障
#if __GNUC__ < 4
static inline void __memory_barrier(void)
{
    asm volatile("mfence":::"memory");
}
#else
static inline void __memory_barrier(void)
{
    __sync_synchronize();
}
#endif

// 分支预测
#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_UTIL_H
