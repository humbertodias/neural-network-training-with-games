UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig -I./include `sdl2-config --cflags` 
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --static-libs`

build:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

run:
	./main

clean:
	rm -rf main main.dSYM release-$(SYSTEM)

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1-particulas pig
	ln -sTf ../common/cmakes cmakes

unlink:
	rm -rf fontes pig cmakes

SYSTEM:=$(shell uname -s)	
release:	build
	mkdir -p release-$(SYSTEM)
	cp -rl imagens fontes main release-$(SYSTEM)
