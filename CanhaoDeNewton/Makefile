UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../pig -I/usr/include/SDL2 -I./include
CXXFLAGS += `sdl2-config --cflags --libs`
CXXFLAGS += -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp
CXXFLAGS += `gsl-config --cflags --libs`

all:
	$(CC) src/main.cpp -g $(CXXFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \;

valgrind:
	valgrind --track-origins=yes --leak-check=yes -v --leak-check=full --show-reachable=yes ./main

run:
	./main

clean:
	rm -rf main main.dSYM
