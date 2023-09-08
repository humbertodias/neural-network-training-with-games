UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig -I/usr/include/SDL2
CXXFLAGS += `sdl2-config --cflags --libs`
CXXFLAGS += -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp
CXXFLAGS += `gsl-config --cflags --libs`

all:
	$(CC) main.cpp -g $(CXXFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

dep:
	sudo apt install libgsl-dev libwebp-dev

clean:
	rm -rf main main.dSYM

ln:
	ln -sF ../fontes fontes
	ln -sF ../pig-0.5.1 pig
