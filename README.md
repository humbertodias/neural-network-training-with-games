# Neural Network Training with Games

Adapted for linux

Credits [JVictorDias](https://github.com/JVictorDias)

# Deps

* sdl2
* sdl2-ttf
* sdl2-image
* libwebp
* make
* g++/clang++

```sh
sudo apt install -y libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libwebp-dev libgsl-dev
```

# How to test


* Flappy-Bird

```
make run-flappy
```
![](doc/flappy.png)

|key|Action|
|---|------|
|esc | Pause |
|space | info |


* Deep-Cars

```
make run-cars
```

![](doc/cars.png)


* Dinossauro

```
make run-dino
```

![](doc/dino.png)


* Tecelao

```
make run-tecelao
```

Parameters (input.txt)

```
Digite o nome da sua imagem (exemplo: teste.bmp): iron.bmp
Digite a quantidade de pregos (maximo 1000): 1000
Digite a quantidade de linhas: 1800
Digite a taxa de reducao do pixel (255 retira o pixel todo, 0 nao retira nada): 255
```
Left mouse click + ENTER to start


Commands

|key|Action|
|---|------|
|a  |Left  |
|d  |Right |
|w  |Up    |
|s  |Down  |
|q  |Zoom In|
|e  |Zoom Out|
|z  |ReDraw|
|ENTER|Start|


![](doc/tecelao.png)

# Source

* [Dinossauro-Google](https://github.com/JVictorDias/Dinossauro-Google)

* [FlappIA-Bird](https://github.com/JVictorDias/FlappIA-Bird)

* [Depp-Cars](https://github.com/JVictorDias/DeepCars)

* [Algoritmo-Tecelao](https://github.com/JVictorDias/AlgoritmoTecelao)
