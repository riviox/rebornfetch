PREFIX = /usr
MANDIR = $(PREFIX)/share/man

all:
	@echo Run \'make install\' to install rbfetch.

install:
	@mkdir -p $(DESTDIR)$(PREFIX)/bin
	@mkdir -p $(DESTDIR)$(MANDIR)/man1
	@cp -p rbfetch $(DESTDIR)$(PREFIX)/bin/rbfetch
	@cp -p rebornfetch.1 $(DESTDIR)$(MANDIR)/man1
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/rbfetch

uninstall:
	@rm -rf $(DESTDIR)$(PREFIX)/bin/rbfetch
	@rm -rf $(DESTDIR)$(MANDIR)/man1/rebornfetch.1*
