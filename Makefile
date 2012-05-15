SRCS := $(wildcard *.c)
APPS := $(patsubst %.c,%,$(wildcard *.c))

CFLAGS := -O2 -Wall -Wextra -Werror
CFLAGS += $(shell pkg-config --cflags --libs gtk+-3.0 gmodule-2.0)

LIBS := $(shell pkg-config --libs gtk+-3.0 gmodule-2.0)

all: $(APPS)

%: %.c
	gcc -o $@ $(CFLAGS) $< $(LIBS)

clean:
	-rm -f $(APPS)
