/********************************
Seção de elementos geométricos
********************************/

void PIG_desenharLinha(double x1, double y1, double x2, double y2, PIG_Cor cor, int grossuraLinha)
{
    if(grossuraLinha == 1)
    {
        jogo->DesenhaLinhaSimples(x1,y1,x2,y2,cor);
    }
    else
    {
        for(int i=-grossuraLinha/2; i<round(grossuraLinha/2); i++)
        {
            for(int j=-grossuraLinha/2; j<round(grossuraLinha/2); j++)
            {
                jogo->DesenhaLinhaSimples(x1+i,y1+j,
                                          x2+i,y2+j,
                                          cor);
            }
        }
    }
}

void PIG_desenharLinhasConectadas(SDL_Point* pontos, int quantidadePontos, PIG_Cor cor)
{
    jogo->DesenhaLinhas(pontos, quantidadePontos, cor);
}

void PIG_desenharPonto(double x, double y, PIG_Cor cor, int tamanho)
{
    jogo->DesenharPonto(x,y,cor,tamanho);
}

void PIG_desenharPontos(SDL_Point *points, int count, PIG_Cor cor)
{
    jogo->DesenharPontos(points,count,cor);
}

void PIG_desenharRetangulo(double x, double y, double largura, double altura, PIG_Cor cor, int alinhadoCentro)
{
    if(alinhadoCentro == 1)
    {
        x = x - largura/2.0;
        y = y - altura/2.0;
    }
    jogo->DesenhaRetangulo(x,y,altura,largura,cor);
}

void PIG_desenharRetanguloVazado(double x, double y, double largura, double altura, PIG_Cor cor, int alinhadoCentro)
{
    if(alinhadoCentro == 1)
    {
        x = x - largura/2.0;
        y = y - altura/2.0;
    }

    jogo->DesenhaRetanguloVazado(x, y, altura, largura, cor);
}

void PIG_desenharGrade( double x, double y, double largura, double altura,
                        int qtdColunas, int qtdLinhas, PIG_Cor cor, int grossuraLinha, int alinhadoCentro)
{
    if(alinhadoCentro == 1)
    {
        x = x - largura/2.0;
        y = y - altura/2.0;
    }

    double tamanhoHorizontal = largura/(double)qtdColunas;
    double tamanhoVertical = altura/(double)qtdLinhas;

    for(int i=0; i<=qtdColunas; i++)
    {
        PIG_desenharLinha(  x+(i*tamanhoHorizontal),
                            y,
                            x+(i*tamanhoHorizontal),
                            y+altura,
                            cor,grossuraLinha);
    }
    for(int i=0; i<=qtdLinhas; i++)
    {
        PIG_desenharLinha(  x,
                            y+(i*tamanhoVertical),
                            x+largura,
                            y+(i*tamanhoVertical),
                            cor,grossuraLinha);
    }
}

/********************************
A função desenharSprite() é responsável por desenhar um sprite (que já esteja criado) na tela
********************************/

void PIG_desenharSprite(int id_sprite, double x, double y, double largura, double altura, double angulo, int alinhadoCentro, PIG_Cor cor)
{
    if(alinhadoCentro == 1)
    {
        x = x - largura/2.0;
        y = y - altura/2.0;
    }

    CGerenciadorObjetos::DesenhaSprite(id_sprite,x,y,largura,altura,angulo,cor);
}

