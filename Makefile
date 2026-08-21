PREFIX ?= ~/.local
BINDIR = $(PREFIX)/bin

BINARIES = cru2us cus2ru

all: $(BINARIES)

install: $(BINARIES)
	install -d $(BINDIR)
	install -m 755 $(BINARIES) $(BINDIR)

uninstall:
	$(RM) $(addprefix $(BINDIR)/,$(BINARIES))

cru2us: cru2us.o layouts.o

cus2ru: cus2ru.o layouts.o

clean:
	$(RM) *.o cru2us cus2ru

.PHONY: clean all install uninstall
