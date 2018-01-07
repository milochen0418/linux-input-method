EXES = $(basename $(wildcard *.c))
CC = cc

DYNAMIC_LIBGLADE_CFLAGS = -export-dynamic
GTK_CFLAGS = -Wall -g `pkg-config --cflags --libs gtk+-2.0 libglade-2.0`
MY_CFLAGS = -I./include
CFLAGS = $(DYNAMIC_LIBGLADE_CFLAGS) $(GTK_CFLAGS) $(MY_CFLAGS)



all: 
	$(CC) $(CFLAGS) -o oxim-setup-gtk ./src/main.c 

clean:
	rm -f oxim-setup-gtk

install:
	install -D -m 755 oxim-setup-gtk $(DESTDIR)/usr/bin/oxim-setup-gtk
	install -D -m 644 gui/oxim-setup-glade.glade $(DESTDIR)/usr/share/oxim-setup-gtk/oxim-setup-glade.glade
	install -D -m 644 config/gtkrc $(DESTDIR)/usr/share/oxim-setup-gtk/gtkrc

.PHONY: all clean install

