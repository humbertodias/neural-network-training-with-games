UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -Iinclude -I../../common/pig-0.5.1 `pkg-config --cflags sdl2` `gsl-config --cflags`
LDFLAGS := -lSDL2_ttf -lSDL2_image  `sdl2-config --libs` `gsl-config --libs`

.PHONY: build
build:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

cmake:
	mkdir -p build && cd build && cmake .. && make -j2

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

clean:
	rm -rf main main.dSYM build* release*

SYSTEM:=$(shell uname -s)
release:	build
	mkdir -p release-$(SYSTEM)
	cp -r imagens fontes main release-$(SYSTEM)