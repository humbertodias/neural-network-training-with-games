all:
	cd Spirograph && $(MAKE)
	cd ParticulasGravitacionais3D && $(MAKE)
	cd Dinossauro-Google && $(MAKE)
	cd FlappIA-Bird && $(MAKE)
	cd DeepCars && $(MAKE)
	cd AlgoritmoTecelao && $(MAKE)

run-hardestgameeditor:
	cd HardestGameEditor && make && ./main < input.txt

run-hardestgame:
	cd HardestGame && make && ./main

run-spirograph:
	cd Spirograph && make && ./main

run-particulas:
	cd ParticulasGravitacionais3D && make && ./main

run-dino:
	cd Dinossauro-Google && make && ./main

run-flappy:
	cd FlappIA-Bird && make && ./main

run-cars:
	cd DeepCars && make && ./main

run-tecelao:
	cd AlgoritmoTecelao && make && ./main < input.txt

clean:
	cd HardestGameEditor && $(MAKE) clean
	cd HardestGame && $(MAKE) clean
	cd Spirograph && $(MAKE) clean
	cd ParticulasGravitacionais3D && $(MAKE) clean
	cd Dinossauro-Google && $(MAKE) clean
	cd FlappIA-Bird && $(MAKE) clean
	cd DeepCars && $(MAKE) clean 
	cd AlgoritmoTecelao && $(MAKE) clean

docker-image:
	docker build . -t pig-compiler

docker-compile-all:	docker-image
	docker run -v $(PWD):/home/docker -ti pig-compiler make all