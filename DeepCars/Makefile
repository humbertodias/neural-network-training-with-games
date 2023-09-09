UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig `sdl2-config --cflags` `gsl-config --cflags`
CXXFLAGS += -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --libs` `gsl-config --libs`

all:
	$(CC) main.cpp -g $(CXXFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

dep:
	sudo apt install libgsl-dev

clean:
	rm -rf main main.dSYM

ln:
	ln -sF ../common/fontes fontes
	ln -sF ../common/pig-0.5.1 pig

