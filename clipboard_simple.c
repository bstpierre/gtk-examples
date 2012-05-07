// This example demonstrates the use of clipboards.
//
// There is no "main window". This program prints the contents of the
// clipboard (to demonstrate "copy" functionality), and replaces it
// with a new string (to demonstrate "paste" functionality).

#include <gdk/gdk.h>
#include <gtk/gtk.h>

// This callback is invoked when the clipboard contents have been
// received. The text contents of the clipboard will be in UTF-8 in
// the `text` parameter.
void text_request_callback(GtkClipboard *clipboard,
                           const gchar *text,
                           gpointer data)
{
    // To demonstrate setting a new value into the clipboard, we
    // choose some text.
    const gchar* new_clipboard_text = "Clipboard test 1";
    if(g_utf8_collate(text, new_clipboard_text) == 0)
    {
        // If the program was already run, and the clipboard contains
        // our string already, use a different string. This way when
        // you run the program multiple times in a row, you'll see the
        // string changing.
        new_clipboard_text = "Clipboard test 2";
    }

    // This sets the text. I'm passing -1 because I'm lazy -- the
    // function will call strlen on the string to figure out how long
    // it is.
    gtk_clipboard_set_text(clipboard, new_clipboard_text, -1);

    // Display the content and the contents of the variable we passed
    // in.
    printf("Clipboard text was %s, value is %8X\n",
           text, *(int*)data);

    // Now that we've monkeyed with the clipboard, our job is done
    // here.
    gtk_main_quit();
}

int main(int argc, char** argv)
{
    // Standard boilerplate: initialize the toolkit.
    gtk_init(&argc, &argv);

    // Get a handle to the given clipboard. You can also ask for
    // GDK_SELECTION_PRIMARY (the X "primary selection") or
    // GDK_SELECTION_SECONDARY.
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

    // This is just an arbitrary value to pass through to the
    // callback. You could pass a pointer to a local struct or
    // something similar if that was useful to you.
    int value = 0xDECAFBAD;

    // There are more complex things you can place in the clipboard,
    // but this demonstrates text. The callback will be invoked when
    // the clipboard contents has been received.
    gtk_clipboard_request_text(clipboard, text_request_callback, &value);

    // We have to run the GTK main loop so that the events required to
    // fetch the clipboard contents can be processed.
    gtk_main();

    return 0;
}
