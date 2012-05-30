#!/usr/bin/python
# This is just about the simplest GTK program possible.

import pygtk
import gtk

def main():
    window = gtk.Window(gtk.WINDOW_TOPLEVEL)
    window.show()
    gtk.main()

if __name__ == '__main__':
    main()
