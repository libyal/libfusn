#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libfusn/.libs/libfusn.1.dylib && test -f ./pyfusn/.libs/pyfusn.so;
then
	install_name_tool -change /usr/local/lib/libfusn.1.dylib ${PWD}/libfusn/.libs/libfusn.1.dylib ./pyfusn/.libs/pyfusn.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

