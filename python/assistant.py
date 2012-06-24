#!/usr/bin/python

"""
This example demonstrates the use of an assistant.

This assistant has three pages. Each Assistant page contains a
Widget. The first page has a Calendar, the second has an Entry, and
the last has some text.
"""

import pygtk
import gtk


def main():
    calendar = gtk.Calendar()
    entry = gtk.Entry()
    text = gtk.TextView()

    text.set_editable(False)
    text.get_buffer().set_text("""You chose to:
    * Frobnicate the foo.
    * Reverse the glop.
    * Enable future auto-frobnication.""")

    assistant = gtk.Assistant()

    assistant.append_page(calendar)
    assistant.append_page(entry)
    assistant.append_page(text)

    # It's important to set the page type so that the widget knows
    # which buttons to display. In this case, the Intro page won't
    # show a "Back" button. Note that the "Forward" button isn't
    # enabled until the page is marked as complete -- see the
    # "day_selected" signal handler below. When the user selects a day
    # in the calendar widget, the "Forward" button is enabled.
    assistant.set_page_type(calendar, gtk.ASSISTANT_PAGE_INTRO)
    assistant.set_page_title(calendar, "This is an assistant.")

    # The Content page type is for "ordinary" pages. Note that this
    # page is marked as complete here, so the user can press Forward
    # without doing any real action on the page.
    assistant.set_page_type(entry, gtk.ASSISTANT_PAGE_CONTENT)
    assistant.set_page_title(entry, "Enter some information on this page.")
    assistant.set_page_complete(entry, True)

    # The Summary page type is for the final page of the Assistant.
    assistant.set_page_type(text, gtk.ASSISTANT_PAGE_SUMMARY)
    assistant.set_page_title(text, "Congratulations, you're done.")

    # Handle the cancel and close buttons.
    assistant.connect("cancel", done)
    assistant.connect("close", done)

    # Get a callback when a calendar day is selected -- we'll allow
    # the user to move "Forward" when this is done.
    calendar.connect("day_selected", calendar_day_selected, assistant)

    calendar.show()
    entry.show()
    text.show()

    assistant.show()
    gtk.main()

def done(assistant):
    # If the user presses Cancel, just quit the app.
    # If the user presses Close (at the end page), just quit the app.
    gtk.main_quit()

def calendar_day_selected(calendar, assistant):
    # Setting the page as "complete" enables the Forward button.
    assistant.set_page_complete(calendar, True)

if __name__ == '__main__':
    main()
