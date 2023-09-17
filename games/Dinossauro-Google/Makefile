UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -Iinclude -I../../common/pig-0.5.1  `pkg-config --cflags sdl2`
LDFLAGS  := -lSDL2_ttf -lSDL2_image  `pkg-config --static --libs sdl2`

.PHONY: build
build:
	$(CC) src/main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main
	$(MAKE) gerador

.PHONY: gerador
gerador:
	$(CC) src/gerador.cpp -g $(CXXFLAGS) $(LDFLAGS) -o gerador

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

valgrind:
	valgrind --track-origins=yes --leak-check=yes -v --leak-check=full --show-reachable=yes ./main

clean:
	rm -rf main gerador *.dSYM build* release*

cmake:
	mkdir -p build && cd build && cmake .. && make -j2

web:
	EMCC_DEBUG=1 \
	emcc src/main.cpp -Iinclude -I../../common/pig-0.5.1 `pkg-config --cflags sdl2` \
	-s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s SDL2_MIXER_FORMATS='["ogg"]' -s USE_OGG=1 \
	-o web.js \
	--preload-file imagens --preload-file fontes \
	--use-preload-plugins \
	-sALLOW_MEMORY_GROWTH

format:
	find . -regextype posix-extended -regex '.*\.(c|cpp|h)' -exec clang-format -style=Google -i "{}" +;

SYSTEM:=$(shell uname -s)
release:	build
	mkdir -p release-$(SYSTEM)
	cp -r imagens fontes obstaculos.* main release-$(SYSTEM)