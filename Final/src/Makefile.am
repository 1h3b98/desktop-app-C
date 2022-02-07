## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = final

final_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	equipements.c equipements.h \
	clients.c clients.h \
	troups.c troups.h \
	ouvrier.c ouvrier.h \
	employes.c employes.h \
	capteur.c capteur.h

final_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

