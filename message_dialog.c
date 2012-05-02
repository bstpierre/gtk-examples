#include <gtk/gtk.h>

int main(int argc, char** argv)
{
	gtk_init(&argc, &argv);

    GtkWidget* hello = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Hi, I'm a message dialog!");
	gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(hello),
                                             "This is secondary text.");
    gtk_dialog_run(GTK_DIALOG(hello));

    GtkWidget* hellom = gtk_message_dialog_new_with_markup(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Hi, I'm a <b>message dialog</b>!");
	gtk_message_dialog_format_secondary_markup(GTK_MESSAGE_DIALOG(hellom),
                                             "This is <i>secondary</i> markup.");
    gtk_dialog_run(GTK_DIALOG(hellom));

    return 0;
}
