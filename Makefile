all:
	cd AlgoritmoTecelao && $(MAKE)
	cd CanhaoDeNewton && $(MAKE)
	cd DeepCars && $(MAKE)
	cd Dinossauro-Google && $(MAKE)
	cd FlappIA-Bird && $(MAKE)
	cd HardestGame && $(MAKE)
	cd HardestGameEditor && $(MAKE)
	cd ParticulasGravitacionais3D && $(MAKE)
	cd Spirograph && $(MAKE)

ln:
	cd AlgoritmoTecelao && $(MAKE) ln
	cd CanhaoDeNewton && $(MAKE) ln
	cd DeepCars && $(MAKE) ln
	cd Dinossauro-Google && $(MAKE) ln
	cd FlappIA-Bird && $(MAKE) ln
	cd HardestGame && $(MAKE) ln
	cd HardestGameEditor && $(MAKE) ln
	cd Spirograph && $(MAKE) ln
	cd ParticulasGravitacionais3D && $(MAKE) ln

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
	cd AlgoritmoTecelao && $(MAKE) clean
	cd CanhaoDeNewton && $(MAKE) clean
	cd DeepCars && $(MAKE) clean 
	cd Dinossauro-Google && $(MAKE) clean
	cd FlappIA-Bird && $(MAKE) clean
	cd HardestGame && $(MAKE) clean
	cd HardestGameEditor && $(MAKE) clean
	cd ParticulasGravitacionais3D && $(MAKE) clean
	cd Spirograph && $(MAKE) clean

zip:
	cd AlgoritmoTecelao && $(MAKE) zip
	cd CanhaoDeNewton && $(MAKE) zip
	cd DeepCars && $(MAKE) zip
	cd Dinossauro-Google && $(MAKE) zip
	cd FlappIA-Bird && $(MAKE) zip
	cd HardestGame && $(MAKE) zip
	cd HardestGameEditor && $(MAKE) zip
	cd ParticulasGravitacionais3D && $(MAKE) zip
	cd Spirograph && $(MAKE) zip

docker-image:
	docker build . -t pig-compiler

docker-compile-all:	docker-image
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti pig-compiler make all

docker-compile-it:	docker-image
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti pig-compiler bash

args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`
docker-run:
	docker run --net host \
	-e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
	-v "$(shell pwd):/tmp/workdir" \
	-w /tmp/workdir \
	pig-compiler \
	$(args)

docker-mac-run:
	docker run --net host -e DISPLAY=docker.for.mac.host.internal:0 \
	-v "$(shell pwd):/tmp/workdir" \
	-w /tmp/workdir \
	pig-compiler \
	$(args)

docker-clean:
	docker ps -f name=pig-compiler -qa | xargs docker rm -f
	docker image ls --filter 'reference=pig-compiler' -qa | xargs docker rmi -f

dep-install:
	sudo apt install -y libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libwebp-dev libgsl-dev libgtest-dev mingw-w64 mingw-w64-tools

emcc-install:
	# Get the emsdk repo
	git clone https://github.com/emscripten-core/emsdk.git

	# Enter that directory
	cd emsdk

	# Fetch the latest version of the emsdk (not needed the first time you clone)
	git pull

	# Download and install the latest SDK tools.
	./emsdk install latest

	# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
	./emsdk activate latest

	# Activate PATH and other environment variables in the current terminal
	source ./emsdk_env.sh
