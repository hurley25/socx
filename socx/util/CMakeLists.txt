# 要编译的源码文件
SET (UTIL_SRCS
    ThreadPool.cc
)

# 编译库文件
ADD_LIBRARY (socx_util ${UTIL_SRCS})

# 设置附加链接库
TARGET_LINK_LIBRARIES (socx_util pthread rt glog)
