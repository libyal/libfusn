AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFUSN_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_manpage.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	fusn_test_error \
	fusn_test_record \
	fusn_test_support

fusn_test_error_SOURCES = \
	fusn_test_error.c \
	fusn_test_libfusn.h \
	fusn_test_macros.h \
	fusn_test_unused.h

fusn_test_error_LDADD = \
	../libfusn/libfusn.la

fusn_test_record_SOURCES = \
	fusn_test_libcerror.h \
	fusn_test_libfusn.h \
	fusn_test_macros.h \
	fusn_test_memory.c fusn_test_memory.h \
	fusn_test_record.c \
	fusn_test_unused.h

fusn_test_record_LDADD = \
	../libfusn/libfusn.la \
	@LIBCERROR_LIBADD@

fusn_test_support_SOURCES = \
	fusn_test_libfusn.h \
	fusn_test_macros.h \
	fusn_test_support.c \
	fusn_test_unused.h

fusn_test_support_LDADD = \
	../libfusn/libfusn.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

