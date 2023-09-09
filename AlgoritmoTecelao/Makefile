UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig `sdl2-config --cflags`
CXXFLAGS += -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --libs`

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

ln:
	ln -sF ../common/fontes fontes
	ln -sF ../common/pig-0.5.1 pig

