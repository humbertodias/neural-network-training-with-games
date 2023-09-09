UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig -I./include `sdl2-config --cflags` `gsl-config --cflags`
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --libs` `gsl-config --libs`

all:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \;

valgrind:
	valgrind --track-origins=yes --leak-check=yes -v --leak-check=full --show-reachable=yes ./main

run:
	./main

clean:
	rm -rf main main.dSYM

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1 pig
