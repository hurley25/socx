/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Logger.h -- Logger.
 *
 * Version: 1.0  04/25/2015 05:59:31 PM
 *
 * Authors:  
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_LOGGER_H
#define SOCX_UTIL_LOGGER_H

#include <glog/logging.h>

#include "noncopyable.h"

namespace socx {
namespace util {

/**
 * 日志定制
 */
class Logger : private noncopyable
{
private:
    Logger()
    {
        google::InitGoogleLogging("");
    }

public:
    /// 获得单例的 Logger 类对象的引用
    static Logger &GetInstance()
    {
        // thread safe, see https://gcc.gnu.org/ml/gcc-patches/2004-08/msg01598.html
        static Logger logger;
        return logger;
    }

    /// 设置日志输出到 stderr (默认输出到文件)
    void setLogToStderr()
    {
        google::LogToStderr();
    }

    /// 安装信号处理器 (程序遇到 SIGSEGV 之类的信号结束时将显示更多信息)
    void installFailureSignalHandler()
    {
        google::InstallFailureSignalHandler();
    }
};

} // namespace util
} // namespace socx

#endif  // SOCX_UTIL_LOGGER_H
