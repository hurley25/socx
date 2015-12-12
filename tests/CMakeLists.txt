# 要编译的源码文件
SET (TEST_SRCS 
    AllTest.cc
    Logger_test.cc
    Atomic_test.cc
    Util_test.cc
    BlockingQueue_test.cc
    ThreadPool_test.cc
    CountDownLatch_test.cc
    ClockTimer_test.cc
    TimerFd_test.cc
)

ADD_EXECUTABLE (all_test ${TEST_SRCS})
TARGET_LINK_LIBRARIES (all_test glog gtest pthread socx_util)

