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
	/bin/rm -f libfusn.h
	/bin/rm -f libfusn/definitions.h
	/bin/rm -f libfusn/types.h
	/bin/rm -f Makefile

