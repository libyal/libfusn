AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCNOTIFY_CPPFLAGS@ \
	@LIBUNA_CPPFLAGS@ \
	@LIBFDATETIME_CPPFLAGS@ \
	@LIBFUSN_DLL_EXPORT@

lib_LTLIBRARIES = libfusn.la

libfusn_la_SOURCES = \
	fusn_record.h \
	libfusn.c \
	libfusn_debug.c libfusn_debug.h \
	libfusn_definitions.h \
	libfusn_extern.h \
	libfusn_error.c libfusn_error.h \
	libfusn_libcerror.h \
	libfusn_libcnotify.h \
	libfusn_libfdatetime.h \
	libfusn_libuna.h \
	libfusn_record.c libfusn_record.h \
	libfusn_support.c libfusn_support.h \
	libfusn_types.h \
	libfusn_unused.h

libfusn_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCNOTIFY_LIBADD@ \
	@LIBUNA_LIBADD@ \
	@LIBFDATETIME_LIBADD@

libfusn_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libfusn_definitions.h.in \
	libfusn.rc \
	libfusn.rc.in

DISTCLEANFILES = \
	libfusn_definitions.h \
	libfusn.rc \
	Makefile \
	Makefile.in

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libfusn ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libfusn_la_SOURCES)

