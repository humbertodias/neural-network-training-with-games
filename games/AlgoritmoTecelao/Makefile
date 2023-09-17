UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../../common/pig-0.5.1 `pkg-config --cflags sdl2`
LDFLAGS  := -lSDL2_ttf -lSDL2_image `pkg-config --libs --static sdl2`

.PHONY: build
build:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

run:
	./main

run-input:
	./main < input.txt

run-valgrind:
	valgrind --leak-check=full --track-origins=yes ./main < input.txt

clean:
	rm -rf main main.dSYM build* release* cmake*

cmake:
	mkdir -p build && cd build && cmake .. && make -j2

web:
	emcc main.cpp -I../../common/pig-0.5.1 `pkg-config --cflags sdl2` \
	-s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s SDL2_MIXER_FORMATS='["ogg"]' -s USE_OGG=1 \
	-o web.js \
	--preload-file iron.bmp \
	--use-preload-plugins \
	-sALLOW_MEMORY_GROWTH

SYSTEM:=$(shell uname -s)
release:	build
	mkdir -p release-$(SYSTEM)
	cp -r imagens fontes *.bmp input.txt main release-$(SYSTEM)
