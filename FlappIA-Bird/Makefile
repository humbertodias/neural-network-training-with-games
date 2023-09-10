UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig `sdl2-config --cflags` `gsl-config --cflags`
LDFLAGS := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --libs` `gsl-config --libs`

build:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

clean:
	rm -rf main main.dSYM release

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1 pig
	ln -sTf ../common/cmakes cmakes

release:	build
	mkdir -p release	
	cp -rl imagens fontes main release