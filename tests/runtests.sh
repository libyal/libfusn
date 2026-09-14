#!/bin/sh
# Script to run tests
#
# Version: 20260714

if [ -f "${PWD}/libfusn/.libs/libfusn.1.dylib" ] && [ -f ./pyfusn/.libs/pyfusn.so ]
then
    install_name_tool -change /usr/local/lib/libfusn.1.dylib "${PWD}/libfusn/.libs/libfusn.1.dylib" ./pyfusn/.libs/pyfusn.so
fi

make check-build > /dev/null

# shellcheck disable=SC2068
make check $@
RESULT=$?

if [ ${RESULT} -ne 0 ]
then
    find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

