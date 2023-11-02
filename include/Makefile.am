include_HEADERS = \
	libfusn.h

pkginclude_HEADERS = \
	libfusn/codepage.h \
	libfusn/definitions.h \
	libfusn/error.h \
	libfusn/extern.h \
	libfusn/features.h \
	libfusn/types.h

EXTRA_DIST = \
	libfusn.h.in \
	libfusn/definitions.h.in \
	libfusn/features.h.in \
	libfusn/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libfusn.h
	-rm -f libfusn/definitions.h
	-rm -f libfusn/features.h
	-rm -f libfusn/types.h
	-rm -f Makefile

