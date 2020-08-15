# Neural Network Training with Games

Adapted for Linux/Mac

Credits [JVictorDias](https://github.com/JVictorDias)

# Deps

* sdl2
* sdl2-ttf
* sdl2-image
* libwebp
* make
* g++/clang++
* docker (optional)

Linux
```sh
sudo apt install -y libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libwebp-dev libgsl-dev
```

or
```sh
make docker-compile-all
```


Mac
```sh
sudo brew install sdl2 sdl2-ttf sdl2-image gsl
```

# How to test


## Flappy-Bird

```
make run-flappy
```

or

```
make docker-run make run-flappy
```
for mac

```
make docker-mac-run make run-flappy
```

![](doc/flappy.png)

|key|Action|
|---|------|
|esc | Pause |
|space | info |


[Youtube](https://www.youtube.com/watch?v=vavXvu_SMeM)

## Deep-Cars

```
make run-cars
```

![](doc/cars.png)

[Youtube](https://www.youtube.com/watch?v=gnfkfUQvKDw)


## Dinossauro

```
make run-dino
```

![](doc/dino.png)


[Youtube](https://www.youtube.com/watch?v=NZlIYr1slAk)


## Tecelao

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

[Youtube](https://www.youtube.com/watch?v=YZtx4jNNbx8)

## ParticulasGravitacionais3D

```
make run-particulas
```

|key|Action|
|---|------|
|a  |Left  |
|d  |Right |
|w  |Up    |
|s  |Down  |
|q  |Zoom In|
|e  |Zoom Out|
|h  |Rotate Up X|
|y  |Rotate Down X|
|g  |Rotate Left Y|
|j  |Rotate Right Y|
|ENTER|Join particles|
|Mouse Left|Expand particles|

![](doc/particulas.png)


[Youtube](https://www.youtube.com/watch?v=rTZJtiCAmTI)


## Spirograph

```
make run-spirograph
```

|key|Action|
|---|------|
|ENTER  |Next  |

![](doc/spirograph.png)


[Youtube](https://www.youtube.com/watch?v=o7MOaXh4zFU)


## HardestGame

```
make run-hardestgame
```

|key|Action|
|---|------|
|F2  |Load next map |
|ENTER  |Start map  |

![](doc/hardestgame.png)

[Youtube](https://www.youtube.com/watch?v=QD-gHp81G4M)

## HardestGameEditor

```
make run-hardestgame-editor
```

|key|Action|
|---|------|
|d/f  |Angulo de troca |
|cima/baixo  |Tamanho grade  |
|j/k  |Tempo parado |
|g/h  |Angulo parada |
|i  |Salvar posicao mouse |
|u  |Carregar posicao salva  |
|F1 |Salvar mapa  |
|F2  |Carregar mapa  |

![](doc/hardestgame-editor.png)


## Docker with X11 on MAC

Make sure to install XQuartz

    brew install socat
    brew cask reinstall xquartz

Don't forget to close logout and log back in.
1. Close any 6000

On a new terminal, verify if there's anything running on port 6000

    lsof -i TCP:6000

If there is anything, just kill the process

2. Close any 6000
Open a socket on that port and keep the terminal open

    socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$DISPLAY\"

3. Verify 6000 is open
In a new terminal, verify if it is opened

    lsof -i TCP:6000
    COMMAND   PID     USER   FD   TYPE             DEVICE SIZE/OFF NODE NAME
    socat   29298 mdesales    5u  IPv4 0xe21e43ca9d99bf1d      0t0  TCP *:6000 (LISTEN)


Copy and paste this into a Terminal window of your Mac
    
    sudo defaults write org.macosforge.xquartz.X11 enable_iglx -bool true


# Source

* [HardestGame](https://github.com/JVictorDias/HardestGame)

* [HardestGameEditor](https://github.com/JVictorDias/HardestGameEditor)

* [Spirograph](https://github.com/JVictorDias/Spirograph)

* [ParticulasGravitacionais3D](https://github.com/JVictorDias/ParticulasGravitacionais3D)

* [Dinossauro-Google](https://github.com/JVictorDias/Dinossauro-Google)

* [FlappIA-Bird](https://github.com/JVictorDias/FlappIA-Bird)

* [Depp-Cars](https://github.com/JVictorDias/DeepCars)

* [Algoritmo-Tecelao](https://github.com/JVictorDias/AlgoritmoTecelao)
