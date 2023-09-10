UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig `sdl2-config --cflags` 
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --static-libs`

build:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

run:
	./main

clean:
	rm -rf main main.dSYM release.zip

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1 pig
	ln -sTf ../common/cmakes cmakes

release:	build
	zip -r release.zip imagens fontes main

