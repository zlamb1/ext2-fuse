SRCDIR ?= src
OUTDIR ?= out
OUTEXE ?= $(OUTDIR)/ext2-fuse  

WARN    := -Wall -Wextra -Werror -Wshadow -Wpointer-arith -Wstrict-prototypes \
		   -Wmissing-prototypes -Wno-missing-braces -Wno-missing-field-initializers -Wbad-function-cast \
		   -Winline -Wundef -Wunreachable-code -Wredundant-decls -Wfloat-equal -Wcast-align \
		   -Wcast-qual -Wdeclaration-after-statement -Wmissing-include-dirs -Wnested-externs \
		   -Wno-error=format -Wsequence-point -Wswitch -Wwrite-strings
CFLAGS  := $(WARN) $(shell pkgconf --cflags fuse)
LDFLAGS := $(shell pkgconf --libs fuse)

INCL   := include
SRCS   := main ext2
OBJS   := $(patsubst %,$(OUTDIR)/$(SRCDIR)/%.o,$(SRCS))
DEPS   := $(OBJS:.o=.d)

.PHONY: all clean

all: $(OUTEXE)

$(OUTEXE): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OUTDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -MMD -I$(INCL) $< -o $@

clean:
	rm -rf $(OUTDIR)

-include $(DEPS)