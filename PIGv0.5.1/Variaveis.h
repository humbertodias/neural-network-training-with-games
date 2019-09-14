
    Atomo               Atomos[100000];
    SDL_Point           AtomosSDL[100000];
    int                 QuantidadeDeAtomos = 0;

    int                 TimerGeral = 0;
    int                 TimerAvisos = 0;
    char                StringAvisos[100];

    int                 MovimentoEsferas = 1;
    int                 GravidadeAtivada = -1;

    float               Periodo = 0.01;

    int                 Distribuicao = DISTRIBUICAO;

    float               X ,Y, Z;
    float               MouseZ = 0, MouseY = 0, MouseX = 0;

    int                 Giro = -1;
