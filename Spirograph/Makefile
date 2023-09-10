UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../common/pig `sdl2-config --cflags` 
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --static-libs`

build:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

run:
	./main

clean:
	rm -rf main main.dSYM release*

SYSTEM:=$(shell uname -s)
release:	build
	mkdir -p release-$(SYSTEM)
	cp -r imagens fontes main release-$(SYSTEM)
