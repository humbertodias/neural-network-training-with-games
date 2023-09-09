UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig -I./include `sdl2-config --cflags` 
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --libs`

all:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

run:
	./main

clean:
	rm -rf main main.dSYM

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1-particulas pig

