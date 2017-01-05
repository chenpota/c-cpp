DESTDIR=/
INSTALL_LOCATION=$(DESTDIR)/usr/
CFLAGS:=$(shell dpkg-buildflags --get CFLAGS)
LDFLAGS:=$(shell dpkg-buildflags --get LDFLAGS)

all: main.o
	gcc $(CFLAGS) $(LDFLAGS) -o hello-world main.o

install:
	mkdir -p $(INSTALL_LOCATION)/bin
	cp hello-world $(INSTALL_LOCATION)/bin

clean:
	rm -f *.o hello-world
