build:
	cd AlgoritmoTecelao && $(MAKE)
	cd CanhaoDeNewton && $(MAKE)
	cd DeepCars && $(MAKE)
	cd Dinossauro-Google && $(MAKE)
	cd FlappIA-Bird && $(MAKE)
	cd HardestGame && $(MAKE)
	cd HardestGameEditor && $(MAKE)
	cd ParticulasGravitacionais3D && $(MAKE)
	cd Spirograph && $(MAKE)

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
	rm -rf *.zip

release:
	cd AlgoritmoTecelao && $(MAKE) release
	cd CanhaoDeNewton && $(MAKE) release
	cd DeepCars && $(MAKE) release
	cd Dinossauro-Google && $(MAKE) release
	cd FlappIA-Bird && $(MAKE) release
	cd HardestGame && $(MAKE) release
	cd HardestGameEditor && $(MAKE) release
	cd ParticulasGravitacionais3D && $(MAKE) release
	cd Spirograph && $(MAKE) release

docker-image:
	docker build . \
	--build-arg UID=$(shell id -u) \
	--build-arg GID=$(shell id -g) \
	-t sdl2-compiler

docker-tag:
	docker tag sdl2-compiler hldtux/sdl2-compiler

docker-push: 	docker-tag
	docker push hldtux/sdl2-compiler

docker-compile-all:	docker-image
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti sdl2-compiler make build

docker-run-it:	docker-image
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir \
	-ti sdl2-compiler \
	--build-arg UID=$(shell id -u) \
	--build-arg GID=$(shell id -g) \
	bash

docker-release-linux:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir hldtux/sdl2-compiler make release

docker-release-windows:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir hldtux/sdl2-compiler make -e CC=x86_64-w64-mingw32-g++ release

docker-release-darwin:
	make release

zip-all:
	$(MAKE) docker-release-linux && zip -r Linux.zip `find . -name "release-Linux" -print`
	$(MAKE) docker-release-windows && zip -r Windows.zip `find . -name "release-Windows" -print`
	$(MAKE) docker-release-darwin && zip -r Darwin.zip `find . -name "release-Darwin" -print`

args = `arg="$(filter-out $@,$(MAKECMDGOALS))" && echo $${arg:-${1}}`
docker-run:
	docker run --net host \
	-e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
	-v "$(shell pwd):/tmp/workdir" \
	-w /tmp/workdir \
	sdl2-compiler \
	$(args)

docker-mac-run:
	docker run --net host -e DISPLAY=docker.for.mac.host.internal:0 \
	-v "$(shell pwd):/tmp/workdir" \
	-w /tmp/workdir \
	sdl2-compiler \
	$(args)

docker-clean:
	docker ps -f name=sdl2-compiler -qa | xargs docker rm -f
	docker image ls --filter 'reference=sdl2-compiler' -qa | xargs docker rmi -f

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
