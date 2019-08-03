run-dino:
	cd Dinossauro-Google && make && ./main

run-flappy:
	cd FlappIA-Bird && make && ./main

run-cars:
	cd DeepCars && make && ./main

clean:
	rm -f Dinossauro-Google/main FlappIA-Bird/main DeepCars/main 