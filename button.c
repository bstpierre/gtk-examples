// This example primarily demonstrates the use of a GtkButton, but to
// do so requires the use of packing and signals.

#include <stdio.h>
#include <gtk/gtk.h>

// This is a callback that will be called when the button is clicked.
void button_clicked(GtkButton *button,
                    gpointer user_data)
{
    // The user_data is the value we passed to g_signal_connect.
    int* my_data = (int*)user_data;

    printf("button_clicked: %p, %#x\n", button, *my_data);

    // Since the location that we're pointing to is a static in main,
    // we can do stuff like increment the value each time the button
    // is clicked:
    ++*my_data;
}

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Create a button with a label.
    GtkWidget* button = gtk_button_new_with_label((gchar*)"Click me");

    // (Note that we could also use gtk_button_new() and add our own
    // children to it. Or gtk_button_new_with_mnemonic() so that you
    // can use the keyboard to "click" the button. Or
    // gtk_button_new_from_stock() to create a "stock" button like
    // "OK".)
    // :TODO: Create a "buttons.c" demo that displays multiple
    // buttons -- one of each type.

    // Add the button to the window.
    gtk_container_add(GTK_CONTAINER(window), button);

    // Arrange for a callback function to be called when the button is
    // clicked.
    static int some_data = 0xdeadbeef;
    g_signal_connect(G_OBJECT(button), "clicked",
                     G_CALLBACK(button_clicked), &some_data);

    // Display the button.
    gtk_widget_show(button);

    // Quit the app when the window is closed.
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Display the top level window.
    gtk_widget_show(window);

    gtk_main();

    return 0;
}
