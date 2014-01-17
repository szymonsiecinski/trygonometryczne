## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(datadir)/trygonometryczne/ui
ui_DATA = trygonometryczne.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	$(TRYGONOMETRYCZNE_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = trygonometryczne

trygonometryczne_SOURCES = \
	main.cc

trygonometryczne_LDFLAGS = 

trygonometryczne_LDADD = $(TRYGONOMETRYCZNE_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(datadir)/trygonometryczne

