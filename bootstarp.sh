#!/bin/bash

SOCX_DIR=`pwd`

build_all()
{
    mkdir build && cd build && cmake .. && make
}

run_tests()
{
    if [ -f ${SOCX_DIR}/build/bin/all_test ]; then
        ${SOCX_DIR}/build/bin/all_test
    fi
}

clean_all()
{
    rm -rf ${SOCX_DIR}/build
}

if [ $# == 1 ]; then
    if [ $1 = "clean" ]; then
        clean_all
    elif [ $1 = "build" ]; then
            build_all
    fi
    exit 0
fi

clean_all
build_all
run_tests
