CC = ccache_cc

INSTALL_CMD = /usr/bin/install -c

RANLIB = mips-openwrt-linux-uclibc-gcc-ranlib
SRCDIR = .


prefix = /usr
exec_prefix = /usr
DAEMONDIR = /usr/sbin
MANDIR = /usr/man
topdir = .

LIBS = -lsio -lstr -lmisc -lxlog -lportable -lpset -lm -lcrypt 

CFLAGS += -Os -pipe -mno-branch-likely -mips32r2 -mtune=34kc -fno-caller-saves -fhonour-copts -Wno-error=unused-but-set-variable -Wno-error=unused-result -msoft-float -mips16 -minterlink-mips16 -DNO_RPC  
DCFLAGS = -Wall -Wredundant-decls -W -Wfloat-equal -Wundef -Wcast-qual -Wwrite-strings -Wmissing-noreturn -Wmissing-format-attribute -Wshadow -Wpointer-arith -Wno-unused -g


DEFS = -DHAVE_CONFIG_H

SIO_DEFS  = -DHAVE_CONFIG_H
MISC_DEFS = -DHAVE_CONFIG_H
LIB_DEFS = -DHAVE_CONFIG_H 
PROG_DEFS = -DHAVE_CONFIG_H

LIBMAKEDEFS = CC='$(CC)' CFLAGS='$(CFLAGS) -I../../include'
PROGMAKEDEFS = CC='$(CC)' CFLAGS='$(CFLAGS) -I../libs/include' LDFLAGS='$(LDFLAGS) -L../libs/lib'
DEBUGLIBMAKEDEFS = CC='$(CC)' CFLAGS='$(DCFLAGS) -I../../include'
DEBUGMAKEDEFS = CC='$(CC)' CFLAGS='$(DCFLAGS) -I../libs/include' LDFLAGS='$(LDFLAGS) -L../libs/lib'

MANDATORY_LIBS	= portable sio str misc xlog pset 
ALL_LIBS	= portable sio str misc xlog pset 

build: makelibs makeprog

debug: debugmakelibs debugmakeprog

makeprog: makelibs
	cd xinetd ; $(MAKE) $(PROGMAKEDEFS)

debugmakeprog:
	cd xinetd ; $(MAKE) $(DEBUGMAKEDEFS)

makelibs: libmisc libportable libpset libsio libstr libxlog

debugmakelibs: dlibmisc dlibportable dlibpset dlibsio dlibstr dlibxlog

libmisc: libstr
	cd libs/src/misc ; $(MAKE) $(LIBMAKEDEFS) install
libportable:
	cd libs/src/portable ; $(MAKE) $(LIBMAKEDEFS) install
libpset:
	cd libs/src/pset ; $(MAKE) $(LIBMAKEDEFS) install
libsio: libportable
	cd libs/src/sio ; $(MAKE) $(LIBMAKEDEFS) install
libstr: libsio
	cd libs/src/str ; $(MAKE) $(LIBMAKEDEFS) install
libxlog: libsio libstr
	cd libs/src/xlog ; $(MAKE) $(LIBMAKEDEFS) install

dlibmisc: dlibstr
	cd libs/src/misc ; $(MAKE) $(DEBUGLIBMAKEDEFS) install
dlibportable:
	cd libs/src/portable ; $(MAKE) $(DEBUGLIBMAKEDEFS) install
dlibpset:
	cd libs/src/pset ; $(MAKE) $(DEBUGLIBMAKEDEFS) install
dlibsio: dlibportable
	cd libs/src/sio ; $(MAKE) $(DEBUGLIBMAKEDEFS) install
dlibstr: dlibsio
	cd libs/src/str ; $(MAKE) $(DEBUGLIBMAKEDEFS) install
dlibxlog: dlibsio dlibstr
	cd libs/src/xlog ; $(MAKE) $(DEBUGLIBMAKEDEFS) install

install: build
	for i in $(DAEMONDIR) $(BINDIR) $(MANDIR)/man5 $(MANDIR)/man8 ; do \
	   test -d $(DESTDIR)$$i || mkdir -p $(DESTDIR)$$i ; done
	$(INSTALL_CMD) -m 755 xinetd/xinetd $(DESTDIR)$(DAEMONDIR)
	$(INSTALL_CMD) -m 755 xinetd/itox $(DESTDIR)$(DAEMONDIR)
	$(INSTALL_CMD) -m 755 $(SRCDIR)/xinetd/xconv.pl $(DESTDIR)$(DAEMONDIR)
	$(INSTALL_CMD) -m 644 $(SRCDIR)/xinetd/xinetd.conf.man $(DESTDIR)$(MANDIR)/man5/xinetd.conf.5
	$(INSTALL_CMD) -m 644 $(SRCDIR)/xinetd/xinetd.log.man $(DESTDIR)$(MANDIR)/man8/xinetd.log.8
	$(INSTALL_CMD) -m 644 $(SRCDIR)/xinetd/xinetd.man $(DESTDIR)$(MANDIR)/man8/xinetd.8
	$(INSTALL_CMD) -m 644 $(SRCDIR)/xinetd/itox.8 $(DESTDIR)$(MANDIR)/man8/itox.8
	$(INSTALL_CMD) -m 644 $(SRCDIR)/xinetd/xconv.pl.8 $(DESTDIR)$(MANDIR)/man8/xconv.pl.8
	@echo "You must put your xinetd.conf in /etc/xinetd.conf"
	@echo "There is a sample config file in xinetd/sample.conf and you can"
	@echo "use xconv.pl to convert your old inetd.conf file to an xinetd format"

uninstall:
	rm -f $(DAEMONDIR)/xinetd
	rm -f $(DAEMONDIR)/itox
	rm -f $(DAEMONDIR)/xconv.pl
	rm -f $(MANDIR)/man5/xinetd.conf.5
	rm -f $(MANDIR)/man8/xinetd.log.8
	rm -f $(MANDIR)/man8/xinetd.8
	rm -f $(MANDIR)/man8/itox.8
 
distclean: clean
	rm -f config.cache config.log Makefile config.status xinetd/itox
	rm -f config.h ./libs/include/* ./libs/man/*
	for lib in $(ALL_LIBS) ; do \
		cd ./libs/src/$$lib ; $(MAKE) distclean ; \
		cd ../../.. ; \
	done
	cd xinetd ; $(MAKE) distclean

clean: cleanlibs cleanprog 
	rm -f ./libs/lib/*.a 

cleanlibs:
	for lib in $(ALL_LIBS) ; do \
		cd ./libs/src/$$lib ; $(MAKE) clean ; \
		cd ../../.. ; \
	done

cleanprog:
	cd xinetd ; $(MAKE) clean

spotless: clean
	rm -f ./libs/include/*.h ./libs/man/*.3
	cd libs ; for i in lib include man ; do rm $$i/* ; done
