CC = gcc
CFLAGS =  -ggdb -fsanitize=address -fno-omit-frame-pointer -Wall -g -Wextra -I./include

SRCDIR = src
LIBDIR = src/lib
COMMONDIR = src/common
BUILDDIR = build
BINDIR = bin
ASMDIR = assembly

SOURCES = $(wildcard $(SRCDIR)/*.c $(LIBDIR)/*.c $(COMMONDIR)/*.c)
EXECUTABLE = $(BUILDDIR)/$(BINDIR)/RickCLib

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) -Wno-unused-parameter -Wno-unused-variable -o $@ $(SOURCES)

clean: 
	rm -rf $(EXECUTABLE)

asm:

	$(CC) -S $(SOURCES) && mv *.s $(BUILDDIR)/$(ASMDIR)

