CC=clang++
#CC=g++

all:
	$(CC) main.cpp -g -I../pig -I/usr/include/SDL2 -I. \
	-lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp  \
	-o main

gerador:
	$(CC) gerador.cpp -g -I../pig -I/usr/include/SDL2 -I. \
	-lSDL2 -lSDL2_ttf -lSDL2_image -lpthread -lwebp  \
	-o gerador

png-fix:
	find imagens -type f -iname '*.png' -exec pngcrush -ow -rem allb -reduce {} \; 

run:
	./main

valgrind:
	valgrind --track-origins=yes --leak-check=yes -v --leak-check=full --show-reachable=yes ./main

clean:
	rm -f main gerador
