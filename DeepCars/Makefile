UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig `sdl2-config --cflags` `gsl-config --cflags`
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --static-libs` `gsl-config --libs`

build:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

dep:
	sudo apt install libgsl-dev

clean:
	rm -rf main main.dSYM build ${ZIP_FOLDER}-${SYSTEM}.zip ${ZIP_FOLDER}

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1 pig

ZIP_FOLDER:=cars
SYSTEM:=$(shell uname -s)
zip:	build
	mkdir -p ${ZIP_FOLDER} && \
	mkdir -p redes && \
	cp -rl imagens fontes matrizDistancias rede redes main ${ZIP_FOLDER} && \
	zip -r ${ZIP_FOLDER}-${SYSTEM}.zip ${ZIP_FOLDER} && \
	rm -rf ${ZIP_FOLDER}

