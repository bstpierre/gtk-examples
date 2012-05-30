// This example demonstrates the use of a glade UI file.
//
// Note: This file must be compiled with the linker flags emitted by
// $(pkg-config gmodule-2.0) so that the dynamic loader can find the
// signal handler at runtime. See the Makefile for implementation.

#include <gtk/gtk.h>
#include <stdio.h>

G_MODULE_EXPORT void handle_button_click(GtkButton* button,
                                         gpointer user_data)
{
  printf("click: %p, %X\n", button, *(int*)user_data);
}

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);

    // Create a builder object that will load the file.
    GtkBuilder* builder = gtk_builder_new();

    // Load the XML from a file.
    gtk_builder_add_from_file(builder, "test.glade", NULL);

    // Get the object called 'main_window' from the file and show it.
    GObject* window = gtk_builder_get_object(builder, "main_window");
    gtk_widget_show(GTK_WIDGET(window));

    // Connect the signal handlers defined in the glade file.
    // (Note: if you're looking for the c++ way to do this, there's no
    // support for binding C++ signal handlers. You must use 'extern
    // "C"' functions as handlers.)
    int my_user_data = 0xDEADBEEF;
    gtk_builder_connect_signals(builder, &my_user_data);

    // Quit the app when the window is closed.
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Main loop.
    gtk_main();

    return 0;
}
