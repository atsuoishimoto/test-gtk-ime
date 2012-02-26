GLIB_CFLAGS = -pthread -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
GLIB_LIBS = -pthread -lgobject-2.0 -lgthread-2.0 -lrt -lglib-2.0

DBUS_CFLAGS = -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include
DBUS_LIBS = -ldbus-1 -lpthread -lrt

IBUS_CFLAGS = -pthread -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/ibus-1.0
IBUS_LIBS = -pthread -libus-1.0 -lgio-2.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lrt -lglib-2.0

CFLAGS = $(GLIB_CFLAGS) $(DBUS_CFLAGS) $(IBUS_CFLAGS)
LFLAGS = $(GLIB_LIBS) $(DBUS_LIBS) $(IBUS_LIBS)

test: test.c
	gcc  test.c -o test $(CFLAGS) $(LFLAGS)

