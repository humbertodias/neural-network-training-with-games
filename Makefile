all:
	cd Dinossauro-Google && $(MAKE)
	cd FlappIA-Bird && $(MAKE)
	cd DeepCars && $(MAKE)
	cd AlgoritmoTecelao && $(MAKE)

run-dino:
	cd Dinossauro-Google && make && ./main

run-flappy:
	cd FlappIA-Bird && make && ./main

run-cars:
	cd DeepCars && make && ./main

run-tecelao:
	cd AlgoritmoTecelao && make && ./main < input.txt

clean:
	cd Dinossauro-Google && $(MAKE) clean
	cd FlappIA-Bird && $(MAKE) clean
	cd DeepCars && $(MAKE) clean 
	cd AlgoritmoTecelao && $(MAKE) clean 