#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libfusn/.libs/libfusn.1.dylib && test -f ./pyfusn/.libs/pyfusn.so
then
	install_name_tool -change /usr/local/lib/libfusn.1.dylib ${PWD}/libfusn/.libs/libfusn.1.dylib ./pyfusn/.libs/pyfusn.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

