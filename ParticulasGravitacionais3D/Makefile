UNAME := $(shell uname)

ifeq ($(UNAME),Darvin)
	CC=clang++
else
	CC=g++
endif

CXXFLAGS := -I./pig -I./include `sdl2-config --cflags` 
LDFLAGS  := -lSDL2_ttf -lSDL2_image -lpthread -lwebp `sdl2-config --static-libs`

build:
	$(CC) main.cpp -g $(CXXFLAGS) $(LDFLAGS) -o main

run:
	./main

clean:
	rm -rf main main.dSYM ${ZIP_FOLDER}-${SYSTEM}.zip

ln:
	ln -sTf ../common/fontes fontes
	ln -sTf ../common/pig-0.5.1-particulas pig
	ln -sTf ../common/cmakes cmakes

ZIP_FOLDER:=particulas
SYSTEM:=$(shell uname -s)
zip:	build
	mkdir -p ${ZIP_FOLDER} && \
	cp -rl imagens fontes main ${ZIP_FOLDER} && \
	zip -r ${ZIP_FOLDER}-${SYSTEM}.zip ${ZIP_FOLDER} && \
	rm -rf ${ZIP_FOLDER}
