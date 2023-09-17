UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./include -I../../common/pig-0.5.1-particulas `pkg-config --cflags sdl2` 
LDFLAGS  := -lSDL2_ttf -lSDL2_image  `pkg-config --static --libs sdl2`

.PHONY: build
build:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

cmake:
	mkdir -p build && cd build && cmake .. && make -j2

run:
	./main

clean:
	rm -rf main main.dSYM build* release*

SYSTEM:=$(shell uname -s)	
release:	build
	mkdir -p release-$(SYSTEM)
	cp -r imagens fontes main release-$(SYSTEM)
