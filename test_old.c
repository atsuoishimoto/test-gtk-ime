#include <stdio.h>
#include <ibus.h>
#include <dbus/dbus.h>

void f() {

    IBusBus *bus=NULL;
    gchar *icname=NULL;
    const gchar *addr=NULL;
    DBusConnection *connection=NULL;

    ibus_init();
    
    addr = ibus_get_address();
    connection = dbus_connection_open(addr, NULL);
    bus = ibus_bus_new();
    printf("connection:%x bus:%x\n", connection, bus);
    if (bus) {
        icname = ibus_bus_current_input_context(bus);
        printf("%s\n", icname);
        if (icname) {
            ibus_input_context_new(icname,  connection, NULL, NULL);
            g_free(icname);
        }
    }

    g_object_unref(bus);
}

void main() {
    while (1) {
        char buf[80];
        fgets(buf, 80, stdin);
        printf("%s\n", buf);
        f();
    }
}

