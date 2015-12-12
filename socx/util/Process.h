/*
 * (C) 2007-2015 Alibaba Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Process.h -- Process Util
 *
 * Version: 1.0  12/12/2015 08:39:03 PM
 *
 * Authors:
 *     Qianyi.lh (liuhuan), qianyi.lh@alibaba-inc.com
 *
 */

#ifndef SOCX_UTIL_PROCESS_H_
#define SOCX_UTIL_PROCESS_H_

#include <unistd.h>
#include <linux/limits.h>
#include <sys/syscall.h>
#include <stdio.h>

#include <string>

namespace socx {

class Process
{
public:
    static inline pid_t pid()
    {
        return ::getpid();
    }

    static inline pid_t ppid()
    {
        return ::getppid();
    }

    static inline pid_t tid()
    {
        return static_cast<pid_t>(::syscall(SYS_gettid));          
    }

    static inline uid_t uid()
    {
        return ::getuid();
    }

    static inline int getStartTime(std::string &stime)
    {
        char time_buff[20];
        struct stat st;
        int ret = ::lstat("/proc/self/exe", &st);
        if (ret < 0) {
            return ret;
        }

        struct tm *tm_loc = localtime(&st.st_mtime);
        snprintf(time_buff, sizeof(time_buff), "%04d-%02d-%02d %02d:%02d:%02d",
                tm_loc->tm_year + 1900, tm_loc->tm_mon + 1, tm_loc->tm_mday,
                tm_loc->tm_hour, tm_loc->tm_min, tm_loc->tm_sec);

        stime = time_buff;

        return 0;
    }

    static inline int getExeFilePath(std::string &path)
    {
        char path_buf[PATH_MAX];
        ssize_t ret = readlink("/proc/self/exe", path_buf, sizeof(path_buf));
        if (ret > 0) {
            path.assign(path_buf, ret);
            return 0;
        }

        return static_cast<int>(ret);
    }

};

} // namespace socx

#endif  // SOCX_UTIL_PROCESS_H_
