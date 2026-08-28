CFLAGS += -MMD

PREFIX ?= ~/.local
BINDIR = $(PREFIX)/bin

BINARIES = cru2us cus2ru

all: $(BINARIES)

install: $(BINARIES)
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 $(BINARIES) $(DESTDIR)$(BINDIR)

uninstall:
	$(RM) $(addprefix $(DESTDIR)$(BINDIR)/,$(BINARIES))

cru2us: cru2us.o layouts.o

cus2ru: cus2ru.o layouts.o

-include *.d

clean:
	$(RM) *.d *.o $(BINARIES)

.PHONY: clean all install uninstall
