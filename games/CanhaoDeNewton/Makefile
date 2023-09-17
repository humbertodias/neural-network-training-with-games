UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I../../common/pig-0.5.1 -I./include `pkg-config --cflags sdl2` `gsl-config --cflags`
LDFLAGS  := -lSDL2_ttf -lSDL2_image  `pkg-config --static --libs sdl2` `gsl-config --libs`

.PHONY: build
build:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \;

valgrind:
	valgrind --track-origins=yes --leak-check=yes -v --leak-check=full --show-reachable=yes ./main

run:
	./main

clean:
	rm -rf main main.dSYM build release*

cmake:
	mkdir -p build && cd build && cmake .. && make -j2

web:
	emcc src/main.cpp -I../../common/pig-0.5.1 -I./include `pkg-config --cflags sdl2` \
	-s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s SDL2_MIXER_FORMATS='["ogg"]' -s USE_OGG=1 \
	-o web.js \
	--preload-file fontes \
	--preload-file imagens \
	--use-preload-plugins \
	-sALLOW_MEMORY_GROWTH

format:
	find . -regextype posix-extended -regex '.*\.(c|cpp|h)' -exec clang-format -style=Google -i "{}" +;

SYSTEM:=$(shell uname -s)
release:	build
	mkdir -p release-$(SYSTEM)
	cp -r imagens fontes main release-$(SYSTEM)