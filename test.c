#include <stdio.h>
#include <ibus.h>
#include <dbus/dbus.h>

IBusBus *bus=NULL;

void f() {

    gchar *icname=NULL;
    const gchar *addr=NULL;
    GDBusConnection *connection=NULL;
    IBusInputContext *ic=NULL;

    
    connection = ibus_bus_get_connection(bus);
    if (bus) {
        icname = ibus_bus_current_input_context(bus);
        if (icname) {
            ic = ibus_input_context_get_input_context(icname, connection); 
            ibus_input_context_enable(ic);
            g_object_unref(ic);
            g_free(icname);
        }

    }
}

void main() {
    int i;
    ibus_init();
    bus = ibus_bus_new();
    while (1) {
        char buf[80];
printf("--------------\n");
        fgets(buf, 80, stdin);
        for (i=0; i < 10000; i++)
            f();
    }

    g_object_unref(bus);
}

