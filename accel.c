// This example demonstrates the use of accelerators.
//
// The GTK+ documentation says that you won't normally create
// accelerators directly because the UI manager will handle them as
// part of building menus. Which is of course true, but there are no
// real examples of how to do it manually if you need an accelerator
// that isn't attached to a menu item.
//
// This program demonstrates the direct use of an accelerator group:
//
// 1. Create the group.
// 2. Connect an accelerator (in this case Ctrl-A) to a callback.
// 3. Add the group to the window.

#include <stdio.h>
#include <gtk/gtk.h>

// This is a callback that will be called when the accelerator is
// pressed.
void accelerator_pressed(void)
{
    printf("accelerator_pressed\n");
}

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GClosure* closure = g_cclosure_new(accelerator_pressed, 0, 0);

    // Set up the accelerator group.
    GtkAccelGroup* accel_group = gtk_accel_group_new();
    gtk_accel_group_connect(accel_group,
                            GDK_KEY_A,
                            GDK_CONTROL_MASK,
                            0,
                            closure);
    gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

    // Quit the app when the window is closed.
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Display the top level window.
    gtk_widget_show(window);

    gtk_main();

    return 0;
}
