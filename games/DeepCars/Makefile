UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../../common/pig-0.5.1 -Iinclude `pkg-config --cflags sdl2` `gsl-config --cflags`
LDFLAGS  := -lSDL2_ttf -lSDL2_image  `pkg-config --static --libs sdl2` `gsl-config --libs`

.PHONY: build
build:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

cmake:
	mkdir -p build && cd build && cmake .. && make -j2

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

dep:
	sudo apt install libgsl-dev

clean:
	rm -rf main main.dSYM build release*

SYSTEM:=$(shell uname -s)
release:	build
	mkdir -p redes release-$(SYSTEM)
	cp -r imagens fontes matrizDistancias rede redes main release-$(SYSTEM)
