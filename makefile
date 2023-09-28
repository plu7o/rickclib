CC = gcc
CFLAGS = -Wall -g -Wextra -I./include

SRCDIR = src
BUILDDIR = build
BINDIR = bin
ASMDIR = assembly

SOURCES = $(wildcard $(SRCDIR)/*.c)
EXECUTABLE = $(BUILDDIR)/$(BINDIR)/Clox

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) -Wno-unused-parameter -Wno-unused-variable -o $@ $(SOURCES)

clean: 
	rm -rf $(EXECUTABLE)

asm:

	$(CC) -S $(SOURCES) && mv *.s $(BUILDDIR)/$(ASMDIR)

