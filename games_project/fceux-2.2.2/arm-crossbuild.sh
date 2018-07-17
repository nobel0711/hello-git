#!/bin/sh

PLATFORM=posix CC=/usr/local/arm/4.5.1/bin/arm-linux-gcc CXX=/usr/local/arm/4.5.1/bin/arm-linux-g++ LDFLAGS="-L/usr/local/arm/4.5.1/arm-none-linux-gnueabi/sys-root/lib -lSDL -lz -liconv -lts" scons -j8 $@
