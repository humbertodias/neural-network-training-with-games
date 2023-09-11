
#define OBSTACULOS_SPRITE_QUANTIDADE    8

typedef struct sprite
{
    int Largura, Altura;
    int Objeto;

}   Sprite;

    Sprite SpriteObstaculo[OBSTACULOS_SPRITE_QUANTIDADE];
    Sprite SpriteAviao[2];

    int SpriteNeuronDesativado;
    int SpriteNeuronAtivado;
    int SpriteLuz;
    int SpriteSeta;


void InicializarSpriteAviao()
{
    char String[1000];

    for(int i=0; i<2; i++)
    {
        sprintf(String,"imagens/aviao%d.png", i);
        SpriteAviao[i].Objeto = CriarSprite(String,1);
        SpriteAviao[i].Largura = 70;
        SpriteAviao[i].Altura = 37;
    }
}

void InicializarSpritesObstaculos()
{
    int i;
    int LarguraObstaculos[OBSTACULOS_SPRITE_QUANTIDADE] = {32,23,15,49,73, 42,42, 810};
    int AlturaObstaculos[OBSTACULOS_SPRITE_QUANTIDADE]  = {33,46,33,33,47, 36,36, 31};

    char String[1000];

    for(i=0; i<OBSTACULOS_SPRITE_QUANTIDADE-1; i++)
    {

        sprintf(String, "imagens/obs%d.png", i);
        SpriteObstaculo[i].Objeto = CriarSprite(String,1);
        SpriteObstaculo[i].Largura = LarguraObstaculos[i];
        SpriteObstaculo[i].Altura = AlturaObstaculos[i];
    }
    SpriteObstaculo[i].Objeto = CriarSprite("imagens/obs7.png",0);
    SpriteObstaculo[i].Largura = LarguraObstaculos[i];
    SpriteObstaculo[i].Altura = AlturaObstaculos[i];
}

void InicializarSprites()
{
    InicializarSpritesObstaculos();
    InicializarSpriteAviao();

    SpriteNeuronDesativado = CriarSprite("imagens/neuronio7.png",0);
    DefinirColoracao(SpriteNeuronDesativado, PRETO);
    SpriteNeuronAtivado = CriarSprite("imagens/neuronio7.png",0);
    DefinirColoracao(SpriteNeuronAtivado, BRANCO);
    SpriteLuz = CriarSprite("imagens/luz.png",0);

    SpriteSeta = CriarSprite("imagens/seta2.png",0);
    DefinirColoracao(SpriteSeta, PRETO);
}

Sprite getMontanhaSprite(int codigo)
{
    Sprite sprite;

    sprite.Largura = 1366;
    sprite.Altura = 180;

    switch(codigo)
    {
        case 1:
        {
            sprite.Objeto = CriarSprite("imagens/fundo0.png",1);
        }   break;
        case 2:
        {
            sprite.Objeto = CriarSprite("imagens/fundo1.png",1);
        }   break;
        case 11:
        {
            sprite.Objeto = CriarSprite("imagens/fundo2.png",1);
        }   break;
        case 12:
        {
            sprite.Objeto = CriarSprite("imagens/fundo3.png",1);
        }   break;
        case 21:
        {
            sprite.Objeto = CriarSprite("imagens/fundo4.png",1);
        }   break;
        case 22:
        {
            sprite.Objeto = CriarSprite("imagens/fundo5.png",1);
        }   break;
    }

    return sprite;
}

Sprite getChaoSprite()
{
    static int cont = 0;
    char String[1000];
    int Indice;
    Sprite sprite;

    if(cont == 4)
    {
        Indice = rand()%2 + 4;
        cont = 0;

    }
    else
    {
        Indice = rand()%4;
        cont = cont + 1;
    }

    sprintf(String,"imagens/chao%d.png", Indice);
    sprite.Objeto = CriarSprite(String,1);
    sprite.Largura = 60;
    sprite.Altura = 12;

    return sprite;
}

Sprite getDinossauroSprite(int Indice, PIG_Cor cor)
{
    int LarguraFramesDino[10] = {40,40,55,55,40,40,40,40,39,39};
    int AlturaFramesDino[10] = {43,43,25,26,43,43,43,43,37,37};
    char String[1000];
    Sprite sprite;

    sprintf(String, "imagens/dino%d.png", Indice);
    sprite.Objeto = CriarSprite(String,1);

    sprite.Largura = LarguraFramesDino[Indice];
    sprite.Altura = AlturaFramesDino[Indice];

    DefinirColoracao(sprite.Objeto, cor);

    return sprite;
}

Sprite* getObstaculosSprite(int Tipo, int Frame)
{
    if(Tipo == PASSARO_CODIGO_TIPO)
    {
        if(Frame == 0)
        {
            return &SpriteObstaculo[5];
        }
        else
        {
            return &SpriteObstaculo[6];
        }
    }
    else
    {
        if(Tipo == ESPINHO_CODIGO_TIPO)
        {
            return &SpriteObstaculo[7];
        }
        else
        {
            return &SpriteObstaculo[Tipo];
        }
    }
}

Sprite getNuvemSprite()
{
    Sprite sprite;

    sprite.Objeto = CriarSprite("imagens/nuvem.png",1);
    sprite.Largura = 46;
    sprite.Altura = 13;

    return sprite;
}




