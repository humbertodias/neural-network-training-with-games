build:
	cd games/AlgoritmoTecelao && $(MAKE)
	cd games/CanhaoDeNewton && $(MAKE)
	cd games/DeepCars && $(MAKE)
	cd games/Dinossauro-Google && $(MAKE)
	cd games/FlappIA-Bird && $(MAKE)
	cd games/HardestGame && $(MAKE)
	cd games/HardestGameEditor && $(MAKE)
	cd games/ParticulasGravitacionais3D && $(MAKE)
	cd games/Spirograph && $(MAKE)

cmake:
	cd games/AlgoritmoTecelao && $(MAKE) cmake
	cd games/CanhaoDeNewton && $(MAKE) cmake
	cd games/DeepCars && $(MAKE) cmake
	cd games/Dinossauro-Google && $(MAKE) cmake
	cd games/FlappIA-Bird && $(MAKE) cmake
	cd games/HardestGame && $(MAKE) cmake
	cd games/HardestGameEditor && $(MAKE) cmake
	cd games/ParticulasGravitacionais3D && $(MAKE) cmake
	cd games/Spirograph && $(MAKE) cmake

run-hardestgameeditor:
	cd games/HardestGameEditor && make && ./main < input.txt

run-hardestgame:
	cd games/HardestGame && make && ./main

run-spirograph:
	cd games/Spirograph && make && ./main

run-particulas:
	cd games/ParticulasGravitacionais3D && make && ./main

run-dino:
	cd games/Dinossauro-Google && make && ./main

run-flappy:
	cd games/FlappIA-Bird && make && ./main

run-cars:
	cd games/DeepCars && make && ./main

run-tecelao:
	cd games/AlgoritmoTecelao && make && ./main < input.txt

run-canhao:
	cd games/CanhaoDeNewton && make && ./main

clean:
	cd games/AlgoritmoTecelao && $(MAKE) clean
	cd games/CanhaoDeNewton && $(MAKE) clean
	cd games/DeepCars && $(MAKE) clean 
	cd games/Dinossauro-Google && $(MAKE) clean
	cd games/FlappIA-Bird && $(MAKE) clean
	cd games/HardestGame && $(MAKE) clean
	cd games/HardestGameEditor && $(MAKE) clean
	cd games/ParticulasGravitacionais3D && $(MAKE) clean
	cd games/Spirograph && $(MAKE) clean
	rm -rf *.zip

release:
	cd games/AlgoritmoTecelao && $(MAKE) release
	cd games/CanhaoDeNewton && $(MAKE) release
	cd games/DeepCars && $(MAKE) release
	cd games/Dinossauro-Google && $(MAKE) release
	cd games/FlappIA-Bird && $(MAKE) release
	cd games/HardestGame && $(MAKE) release
	cd games/HardestGameEditor && $(MAKE) release
	cd games/ParticulasGravitacionais3D && $(MAKE) release
	cd games/Spirograph && $(MAKE) release

SDL_VERSION=2.28.3
SDL_COMPILER_TAG=hldtux/sdl2-compiler:${SDL_VERSION} 
docker-compile-all:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti ${SDL_COMPILER_TAG} make build

docker-run-it:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti ${SDL_COMPILER_TAG} bash

docker-release-linux:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir ${SDL_COMPILER_TAG} make release

docker-release-windows:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir ${SDL_COMPILER_TAG} make -e CC=x86_64-w64-mingw32-gcc -e CXX=x86_64-w64-mingw32-g++ release

docker-release-darwin:
	make release

zip-all:
	$(MAKE) docker-release-linux && zip -r Linux.zip `find . -name "release-Linux" -print`
	$(MAKE) docker-release-windows && zip -r Windows.zip `find . -name "release-Windows" -print`
	$(MAKE) docker-release-darwin && zip -r Darwin.zip `find . -name "release-Darwin" -print`

linux-dep-install:
	sudo apt install -y libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libwebp-dev libgsl-dev libgtest-dev mingw-w64 mingw-w64-tools

mac-dep-install:
	sudo brew install sdl2 sdl2_ttf sdl2_image gsl googletest

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
