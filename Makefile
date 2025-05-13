PROJECTS = `ls games`
build:
	for PROJECT in ${PROJECTS} ; do \
		$(MAKE) -C games/$$PROJECT build && echo OK || break; \
	done

cmake:
	for PROJECT in ${PROJECTS} ; do \
		$(MAKE) -C games/$$PROJECT cmake && echo OK || break; \
	done

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
	for PROJECT in ${PROJECTS} ; do \
		$(MAKE) -C games/$$PROJECT clean ; \
	done
	rm -rf *.zip

release:
	for PROJECT in ${PROJECTS} ; do \
		$(MAKE) -C games/$$PROJECT release ; \
	done

SDL_VERSION=2.32.4
SDL_COMPILER_TAG=hldtux/sdl-compiler:${SDL_VERSION} 
docker-compile-all:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti ${SDL_COMPILER_TAG} make build

docker-run-it:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir -ti ${SDL_COMPILER_TAG} bash

docker-release-linux:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir ${SDL_COMPILER_TAG} make release

docker-release-windows:
	docker run -v $(shell pwd):/tmp/workdir -w /tmp/workdir ${SDL_COMPILER_TAG} make -e CC=i686-w64-mingw32-gcc -e CXX=i686-w64-mingw32-g++ release

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
