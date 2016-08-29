AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBFUSN_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fusn_test_error \
	fusn_test_get_version \
	fusn_test_record

fusn_test_error_SOURCES = \
	fusn_test_error.c \
	fusn_test_libcstring.h \
	fusn_test_libfusn.h \
	fusn_test_macros.h \
	fusn_test_unused.h

fusn_test_error_LDADD = \
	../libfusn/libfusn.la \
	@LIBCSTRING_LIBADD@

fusn_test_get_version_SOURCES = \
	fusn_test_get_version.c \
	fusn_test_libcstring.h \
	fusn_test_libfusn.h \
	fusn_test_macros.h \
	fusn_test_unused.h

fusn_test_get_version_LDADD = \
	../libfusn/libfusn.la \
	@LIBCSTRING_LIBADD@

fusn_test_record_SOURCES = \
	fusn_test_record.c \
	fusn_test_libcstring.h \
	fusn_test_libfusn.h \
	fusn_test_macros.h \
	fusn_test_memory.c fusn_test_memory.h \
	fusn_test_unused.h

fusn_test_record_LDADD = \
	../libfusn/libfusn.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

