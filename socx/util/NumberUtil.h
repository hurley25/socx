/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * NumberUtil.h -- Number Util ...
 *
 * Version: 1.0  01/17/2016 16:02:26 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_NUMBERUTIL_H
#define SOCX_UTIL_NUMBERUTIL_H

namespace socx {
namespace util {

/// 判断一个数字是否是2的幂次数
static inline bool isp2(uint32_t value)
{
    return ((value & (value - 1)) == 0U);
}

/**
 * 获取大于value的最小的2的n次方的值
 * @param  value
 * @return result
 */
static inline uint32_t uint32p2(uint32_t value)
{
    if (isp2(value)) {
        return value;
    }

    value |= (value >> 1);
    value |= (value >> 2);
    value |= (value >> 4);
    value |= (value >> 8);
    value |= (value >> 16);

    return value + 1;
}

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_NUMBERUTIL_H
