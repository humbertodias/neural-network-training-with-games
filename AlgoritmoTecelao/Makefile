#CC=clang++
CC=g++

all:
	$(CC) -g main.cpp -I../pig -I/usr/include/SDL2 -I. \
	-lSDL2 -lSDL2_ttf -lSDL2_image \
	-o main

run:
	./main

run-input:
	./main < input.txt

run-valgrind:
	valgrind --leak-check=full --track-origins=yes ./main < input.txt

clean:
	rm -f main
