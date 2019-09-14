UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../pig
CXXFLAGS += `sdl2-config --cflags --libs`
CXXFLAGS += -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp

all:
	$(CC) main.cpp -g $(CXXFLAGS) -o main


run:
	./main

run-input:
	./main < input.txt

run-valgrind:
	valgrind --leak-check=full --track-origins=yes ./main < input.txt

clean:
	rm -rf main main.dSYM
