if HAVE_LIB_FUZZING_ENGINE
AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common

bin_PROGRAMS = \
	record_fuzzer

record_fuzzer_SOURCES = \
	ossfuzz_libfusn.h \
	record_fuzzer.cc

record_fuzzer_LDADD = \
	@LIB_FUZZING_ENGINE@ \
	../libfusn/libfusn.la
endif

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f Makefile

splint-local:
	@echo "Running splint on record_fuzzer ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(record_fuzzer_SOURCES)

