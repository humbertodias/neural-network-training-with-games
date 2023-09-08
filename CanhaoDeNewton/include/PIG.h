
#ifndef INCLUDE_PIG
    #define INCLUDE_PIG

    /********************************
    Versão 0.5.1 da Biblioteca Pig.h
    ********************************/

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include <time.h>

    /// -------
    #include "SDL.h"
    #include "SDL_ttf.h"
    #include "SDL_image.h"

    /// --------
    #include "Tipos_PIG.h"
    #include "CPoolNumeros.h"
    #include "CAssetLoader.h"
    #include "CMapaCaracteres.h"
    #include "CGerenciadorObjetos.h"
    #include "CGerenciadorTimers.h"
    #include "CGerenciadorParticulas.h"
    #include "CGerenciadorAnimacoes.h"
    #include "CMouse.h"
    #include "CJogo.h"

    /********************************
    / Variáveis Globais
    /********************************/

    #define DEGTORAD (0.01745329251994329576)
    #define RADTODEG (57.29577951307854999853275233034)

    Jogo        jogo = NULL;
    PIG_Evento  PIG_evento;
    PIG_Teclado PIG_teclado;
    PIG_Mouse   PIG_mouse;

    int PIG_tecla, PIG_botao;

    /********************************
    / Funções
    /********************************/

    #include "PIG_Jogo.h"
    #include "PIG_Desenhos.h"
    #include "PIG_Fontes.h"
    #include "PIG_Sprites.h"
    #include "PIG_Timers.h"
    #include "PIG_Extras.c"

#endif


