// This example demonstrates the use of message dialogs.
//
// The program displays two message dialogs:
//
// 1. The first has plain text.
// 2. The second has text formatted with markup.
//
// There is no "main window". When you dismiss the dialogs, the
// program exits.

#include <gtk/gtk.h>

static void first_dialog(void)
{
    // This creates (but does not yet display) a message dialog with
    // the given text as the title.
    GtkWidget* hello = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Hi, I'm a message dialog!");

    // The (optional) secondary text shows up in the "body" of the
    // dialog. Note that printf-style formatting is available.
    gtk_message_dialog_format_secondary_text(
        GTK_MESSAGE_DIALOG(hello),
        "This is secondary text with printf-style formatting: %d",
        99);

    // This displays our message dialog as a modal dialog, waiting for
    // the user to click a button before moving on. The return value
    // comes from the :response signal emitted by the dialog. By
    // default, the dialog only has an OK button, so we'll get a
    // GTK_RESPONSE_OK if the user clicked the button. But if the user
    // destroys the window, we'll get a GTK_RESPONSE_DELETE_EVENT.
    int response = gtk_dialog_run(GTK_DIALOG(hello));

    printf("response was %d (OK=%d, DELETE_EVENT=%d)\n",
           response, GTK_RESPONSE_OK, GTK_RESPONSE_DELETE_EVENT);

    // If we don't destroy the dialog here, it will still be displayed
    // (in back) when the second dialog below is run.
    gtk_widget_destroy(hello);
}

static void second_dialog(void)
{
    // In the second dialog, we use markup (just bold and italics in
    // this case).
    GtkWidget* hello_markup = gtk_message_dialog_new_with_markup(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Hi, I'm a <b>message dialog</b> with <i>markup</i>!");

    // We *could* add secondary text, either plain text or with
    // markup, but we haven't done it here, just to show what the end
    // result looks like. Either way, printf-style formatting is
    // available.

    // gtk_message_dialog_format_secondary_markup(
    //     GTK_MESSAGE_DIALOG(hello_markup),
    //     "This is <i>secondary</i> markup.");

    // Again, this displays the second dialog as a modal dialog.
    gtk_dialog_run(GTK_DIALOG(hello_markup));

    gtk_widget_destroy(hello_markup);
}

int main(int argc, char** argv)
{
    // Standard boilerplate: initialize the toolkit.
    gtk_init(&argc, &argv);

    first_dialog();
    second_dialog();

    return 0;
}
