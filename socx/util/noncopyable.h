/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * noncopyable.h -- Singleton.
 *
 * Version: 1.0  04/25/2015 06:20:25 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_NONCOPYABLE_H_
#define SOCX_UTIL_NONCOPYABLE_H_

namespace socx {
namespace util {

/**
* 私有继承该类的子类不允许赋值和拷贝(Singleton)
*/
class noncopyable 
{
protected:
    noncopyable() {}
    ~noncopyable() {}

private:
    noncopyable(const noncopyable &);
    const noncopyable &operator=(const noncopyable &);
};

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_NONCOPYABLE_H
