#CC=clang++
CC=g++

all:
	$(CC) main.cpp -I../pig-flappy -I/usr/include/SDL2 -I. \
	-lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp  \
	-std=c++11 \
	-o main

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

clean:
	rm -f main 