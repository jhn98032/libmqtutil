include makefile.local
include makefile.defs

SUBDIRS = src tests



all: tests/Makefile src/Makefile dist/bin/libmqtutil-config
	mkdir -p dist/lib dist/include
	mkdir -p dist/bin
	$(MAKE) -C src
	$(MAKE) -C tests
	$(MAKE) -C docs
	cp -f src/lib*.a   dist/lib/
	cp -R src/mqtutil   dist/include/

dist/bin/libmqtutil-config: libmqtutil-config
	mkdir -p dist/bin
	sed 's+^prefix=.*+prefix=$(PREFIX)+' libmqtutil-config > dist/bin/libmqtutil-config
	chmod a+x dist/bin/libmqtutil-config


src/Makefile: version.pri
	cd src && qmake

tests/Makefile:
	cd tests && qmake

makefile.local:
	@echo "Please run configure"
	@exit 1


install: all
	#$(MAKE) -C tests run_tests
	mkdir -p $(PREFIX)/bin
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/lib
	rm -Rf $(PREFIX)/include/mqtutil
	cp -Rfav dist/include/* $(PREFIX)/include
	rm -f $(PREFIX)/lib/libmqtutil*
	cp -Rfav dist/lib/* $(PREFIX)/lib
	mkdir -p $(PREFIX)/docs/libmqtutil/
	cp -Rfa  dist/docs/libmqtutil/* $(PREFIX)/docs/libmqtutil/
	cp -afv dist/bin/libmqtutil-config $(PREFIX)/bin


clean: src/Makefile tests/Makefile
	$(MAKE) -C src clean
	$(MAKE) -C tests  clean
	$(MAKE) -C docs clean
	rm -fR dist

distclean:
	@$(MAKE) clean
	rm -f src/libmqtutil.*
	rm -f *~
	chmod a+rx libmqtutil-config
	rm -fR dist
	rm -f src/.qmake.stash
	rm -f src/Makefile
	rm -f tests/Makefile
	rm -f tests/test


.PHONY: $(SUBDIRS) clean distclean


