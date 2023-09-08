all:
	cd Spirograph && $(MAKE)
	cd ParticulasGravitacionais3D && $(MAKE)
	cd Dinossauro-Google && $(MAKE)
	cd FlappIA-Bird && $(MAKE)
	cd DeepCars && $(MAKE)
	cd AlgoritmoTecelao && $(MAKE)
	cd CanhaoDeNewton && $(MAKE)

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

run-canhao:
	cd CanhaoDeNewton && make && ./main

clean:
	cd HardestGameEditor && $(MAKE) clean
	cd HardestGame && $(MAKE) clean
	cd Spirograph && $(MAKE) clean
	cd ParticulasGravitacionais3D && $(MAKE) clean
	cd Dinossauro-Google && $(MAKE) clean
	cd FlappIA-Bird && $(MAKE) clean
	cd DeepCars && $(MAKE) clean 
	cd AlgoritmoTecelao && $(MAKE) clean
	cd CanhaoDeNewton && $(MAKE) clean

docker-image:
	docker build . -t pig-compiler

docker-compile-all:	docker-image
	docker run -v $(shell pwd):/home/docker -ti pig-compiler make all

args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`
docker-run:
	docker run --net host \
	-e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
	-v "$(shell pwd):/home/docker" \
	pig-compiler \
	$(args)

docker-mac-run:
	docker run --net host -e DISPLAY=docker.for.mac.host.internal:0 \
	-v "$(shell pwd):/home/docker" \
	pig-compiler \
	$(args)