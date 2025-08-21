SRCDIR := src
OUTDIR := out
OUTEXE := $(OUTDIR)/ext2-fuse

INCL := include
SRCS := main
OBJS := $(patsubst %,$(OUTDIR)/$(SRCDIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(OUTEXE)

$(OUTEXE): $(OBJS)
	$(CC) $< -o $@

$(OUTDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c -MMD -I$(INCL) $< -o $@

clean:
	rm -rf $(OUTDIR)

-include $(DEPS)