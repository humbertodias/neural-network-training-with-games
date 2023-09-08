UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../pig-particulas -I/usr/include/SDL2 -I./include
CXXFLAGS += `sdl2-config --cflags --libs`
CXXFLAGS += -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp

all:
	$(CC) main.cpp -g $(CXXFLAGS) -o main

run:
	./main

clean:
	rm -rf main main.dSYM

ln:
	ln -sF ../fontes fontes
	ln -sF ../pig-0.5.1 pig

