#include "PIG.h"

    PIG_Cor AZUL_FORA       = {180,180,255,255};
    PIG_Cor VERDE_START     = {180,255,180,255};
    PIG_Cor VERDE_END       = {255,255,180,255};
    PIG_Cor BRANCO_FUNDO    = {247,247,255,255};
    PIG_Cor CINZA_FUNDO     = {230,230,255,255};

#define LARGURA_BORDA   5

#define VAZIO        0
#define INICIO       1
#define FINAL        2
#define ANDAVEL      3
#define OBSTACULO    4
#define MOEDA        5
#define INICIO_PONTO 6
#define FINAL_PONTO  7
#define CAMINHO      8
#define PIVO         9

#define QTD_CORES   9
#define QTD_MAX_OBSTACULOS  1000
#define QTD_MAX_MOEDAS      1000
#define QTD_MAX_PIVO        100

typedef struct pivo
{
    int x, y;
    int existe;

}   Pivo;

typedef struct caminho
{
    double destinoX, destinoY;
    double velocidade;

    int angular, direcao, direcaoAtual;
    double anguloSwap, anguloSwapAtual;
    double anguloParada, anguloParadaAtual;
    int IteracoesParado, IteracoesParadoAtual;

}   Caminho;

typedef struct moeda
{
    double X, Y;
    int existe;

}   Moeda;

typedef struct obstaculo
{
    double x, y;
    double xInicial, yInicial;
    Caminho caminho[50];

    int quantidadeCaminhos;
    int caminhoAtual;

    int existe;

}   Obstaculo;

typedef struct mapa
{
    int cenario[100][100];
    int quantidadeBlocos;

    Obstaculo obstaculos[1000];
    Moeda moedas[1000];

    int inicioX, inicioY;
    int finalX, finalY;

    Pivo pivo[100];

}   Mapa;

    int TAM_BLOCOS;
    int TAM_PERSONAGEM;
    int TAM_OBSTACULO;
    int QTD_BLOCOS;

    Mapa mapaAtual;

    double Periodo;

    int matrizColisao[ALT_TELA][ALT_TELA];

    int mouseXSalvo, mouseYSalvo;
    int tipoSelecionado, inimigoSelecionado, angularAtivado, direcaoAngular, tamanhoGrade;
    double anguloSwap, tempoParado, anguloParado;

    double velocidadeInimigo, tempoCaminho;
    int inicioCenarioX,inicioCenarioY;
    int spriteObstaculo, spritePersonagem[QTD_CORES], spriteMoeda;
    int spriteInicio, spriteFinal, spriteX, spriteLuz;

    char StringAviso[1000];
    int TimerAviso;

    int quantidadeBlocos;
    int mapaIniciado;
    int TimerGeral;
    int Geracao, Colididos;
    int TimerPartida;
    int FontePreta, FonteBranca, FonteVermelha, FontePretaGrande;
    int Iteracoes;
    int alinharMouse, mouseX, mouseY;

    PIG_Cor cores[QTD_CORES] = {VERMELHO,VERDE,AZUL,CIANO,AMARELO,ROSA,ROXO,CINZA,LARANJA};


void desenharCenario(int X, int Y)
{
    PIG_Cor cor;
    int codigo;

    for(int i=0; i<QTD_BLOCOS; i++)
    {
        for(int j=0; j<QTD_BLOCOS; j++)
        {
            if(mouseX/TAM_BLOCOS == i &&
               mouseY/TAM_BLOCOS == j)
            {
                codigo = tipoSelecionado;
                if(codigo == OBSTACULO || codigo == MOEDA || codigo == INICIO_PONTO || codigo == FINAL_PONTO ||
                   codigo == PIVO)
                {
                    codigo = mapaAtual.cenario[i][j];
                }
            }
            else
            {
                codigo = mapaAtual.cenario[i][j];
            }

            switch(codigo)
            {
                case VAZIO:
                {
                    cor = AZUL_FORA;
                }   break;
                case INICIO:
                {
                    cor = VERDE_START;
                }   break;
                case FINAL:
                {
                    cor = VERDE_END;
                }   break;
                case ANDAVEL:
                {
                    if((i+j)%2 == 0)
                    {
                        cor = BRANCO_FUNDO;
                    }
                    else
                    {
                        cor = CINZA_FUNDO;
                    }
                }   break;
            }

            if(codigo != VAZIO)
            {
                DesenharRetangulo(X + inicioCenarioX + i*TAM_BLOCOS,
                                  Y + inicioCenarioY + j*TAM_BLOCOS,
                                  TAM_BLOCOS, TAM_BLOCOS,
                                  cor);
            }
        }
    }
}

void desenharBordas(int X, int Y)
{
    PIG_Cor cor = PRETO;
    for(int i=0; i<QTD_BLOCOS; i++)
    {
        for(int j=0; j<QTD_BLOCOS; j++)
        {
            if(mapaAtual.cenario[i][j] == VAZIO)
            {
                if(i+1 < QTD_BLOCOS && mapaAtual.cenario[i+1][j] != VAZIO)
                {
                    DesenharRetangulo(X + inicioCenarioX + (i+1)*TAM_BLOCOS - LARGURA_BORDA,
                                      Y + inicioCenarioY + j*TAM_BLOCOS,
                                      TAM_BLOCOS, LARGURA_BORDA, cor);

                    if(mapaAtual.cenario[i+1][j+1] == VAZIO)
                    {
                        DesenharRetangulo(X + inicioCenarioX + (i+1)*TAM_BLOCOS - LARGURA_BORDA,
                                          Y + inicioCenarioY +               (j+1)*TAM_BLOCOS,
                                                LARGURA_BORDA, LARGURA_BORDA, cor);
                    }

                    if(mapaAtual.cenario[i+1][j-1] == VAZIO)
                    {
                        DesenharRetangulo(X + inicioCenarioX + (i+1)*TAM_BLOCOS - LARGURA_BORDA,
                                          Y + inicioCenarioY +              (j)*TAM_BLOCOS - LARGURA_BORDA,
                                                LARGURA_BORDA, LARGURA_BORDA, cor);
                    }

                }
                if(i-1 >= 0 && mapaAtual.cenario[i-1][j] != VAZIO)
                {
                    DesenharRetangulo(X + inicioCenarioX + (i)*TAM_BLOCOS,
                                      Y + inicioCenarioY +                 j*TAM_BLOCOS,
                                      TAM_BLOCOS, LARGURA_BORDA, cor);

                    if(mapaAtual.cenario[i-1][j+1] == VAZIO)
                    {
                        DesenharRetangulo(X + inicioCenarioX + (i)*TAM_BLOCOS,
                                          Y + inicioCenarioY +               (j+1)*TAM_BLOCOS,
                                                LARGURA_BORDA, LARGURA_BORDA, cor);
                    }

                    if(mapaAtual.cenario[i-1][j-1] == VAZIO)
                    {
                        DesenharRetangulo(X + inicioCenarioX + (i)*TAM_BLOCOS,
                                          Y + inicioCenarioY +               (j)*TAM_BLOCOS - LARGURA_BORDA,
                                                LARGURA_BORDA, LARGURA_BORDA, cor);
                    }
                }
//
//
                if(j+1 < QTD_BLOCOS && mapaAtual.cenario[i][j+1] != VAZIO)
                {
                    DesenharRetangulo(X + inicioCenarioX +       i*TAM_BLOCOS,
                                      Y + inicioCenarioY +                 (j+1)*TAM_BLOCOS - LARGURA_BORDA,
                                      LARGURA_BORDA, TAM_BLOCOS, cor);
                }
                if(j-1 >= 0 && mapaAtual.cenario[i][j-1] != VAZIO)
                {
                    DesenharRetangulo(X + inicioCenarioX + i*TAM_BLOCOS,
                                      Y + inicioCenarioY +             (j)*TAM_BLOCOS,
                                      LARGURA_BORDA, TAM_BLOCOS, cor);
                }
            }
        }
    }
}


void desenharLimites(double X, double Y)
{
    /// - Limite Mapa

    int larguraMapa = TAM_BLOCOS*((int)QTD_BLOCOS);

    DesenharLinhaSimples(inicioCenarioX, inicioCenarioY,
                         inicioCenarioX, inicioCenarioY + larguraMapa,
                         PRETO);
    DesenharLinhaSimples(inicioCenarioX + larguraMapa, inicioCenarioY,
                         inicioCenarioX + larguraMapa, inicioCenarioY + larguraMapa,
                         PRETO);

    DesenharLinhaSimples(inicioCenarioX, inicioCenarioY,
                         inicioCenarioX + larguraMapa, inicioCenarioY, PRETO);
    DesenharLinhaSimples(inicioCenarioX, inicioCenarioY +larguraMapa,
                         inicioCenarioX + larguraMapa, inicioCenarioY +larguraMapa, PRETO);


   /// -------------------------------------
   /// - Limite Bloco

    int i = mouseX/TAM_BLOCOS;
    int j = mouseY/TAM_BLOCOS;
    int x = X + inicioCenarioX + i*TAM_BLOCOS;
    int y = Y + inicioCenarioY + j*TAM_BLOCOS;
    DesenharLinhaSimples(x,y,x + TAM_BLOCOS,y,PRETO);
    DesenharLinhaSimples(x,y,x,y + TAM_BLOCOS,PRETO);
    DesenharLinhaSimples(x+ TAM_BLOCOS,y+ TAM_BLOCOS,x,y+ TAM_BLOCOS,PRETO);
    DesenharLinhaSimples(x+ TAM_BLOCOS,y+ TAM_BLOCOS,x + TAM_BLOCOS,y,PRETO);

}

void desenharDebug()
{
    int X =  PIG_evento.mouse.posX - inicioCenarioX;
    int Y = PIG_evento.mouse.posY - inicioCenarioY;
    char String[1000];

    sprintf(String,"%d", matrizColisao[X][Y]);
    EscreverCentralizada(String, X+inicioCenarioX,Y+inicioCenarioY, FontePreta);
}


void desenharObstaculos(int X, int Y)
{
    DefinirColoracao(spriteObstaculo, AZUL);

    for(int i=0; i<QTD_MAX_OBSTACULOS; i++)
    {
        if(mapaAtual.obstaculos[i].existe == 1)
        {
            DesenharSprite(spriteObstaculo,
                           X+mapaAtual.obstaculos[i].x+inicioCenarioX,
                           Y+mapaAtual.obstaculos[i].y+inicioCenarioY,
                           TAM_OBSTACULO, TAM_OBSTACULO, 0);
        }
    }

    if(tipoSelecionado == OBSTACULO)
    {
        DesenharSprite(spriteObstaculo,
                       X+mouseX+inicioCenarioX,
                       Y+mouseY+inicioCenarioY,
                       TAM_OBSTACULO, TAM_OBSTACULO, 0);
    }
}

void desenharMoedas(double X, double Y)
{
    DefinirColoracao(spriteObstaculo, AMARELO);

    for(int i=0; i<QTD_MAX_MOEDAS; i++)
    {
        if(mapaAtual.moedas[i].existe == 1)
        {
            DesenharSprite(spriteObstaculo,
                           X+mapaAtual.moedas[i].X+inicioCenarioX,
                           Y+mapaAtual.moedas[i].Y+inicioCenarioY,
                           TAM_OBSTACULO, TAM_OBSTACULO, 0);
        }
    }

    if(tipoSelecionado == MOEDA)
    {
        DesenharSprite(spriteObstaculo,
                       X+mouseX+inicioCenarioX,
                       Y+mouseY+inicioCenarioY,
                       TAM_OBSTACULO, TAM_OBSTACULO, 0);
    }
}

void desenharPlacas(double X, double Y)
{
    if(tipoSelecionado == INICIO_PONTO)
    {
        DesenharSprite(spriteX,
                       X+mouseX+inicioCenarioX,
                       Y+mouseY+inicioCenarioY,
                       20, 17, 0);
        DesenharSprite(spriteInicio,
                       X+mouseX-5+inicioCenarioX,
                       Y+mouseY+43+inicioCenarioY,
                       50, 87, 0);
    }

    if(tipoSelecionado == FINAL_PONTO)
    {
        DesenharSprite(spriteX,
                       X+mouseX+inicioCenarioX,
                       Y+mouseY+inicioCenarioY,
                       20, 17, 0);
        DesenharSprite(spriteFinal,
                       X+mouseX-5+inicioCenarioX,
                       Y+mouseY+43+inicioCenarioY,
                       50, 87, 0);
    }

    if(mapaAtual.inicioX != -1 && mapaAtual.inicioY != -1)
    {
        DesenharSprite(spriteX,
                       X+mapaAtual.inicioX+inicioCenarioX,
                       Y+mapaAtual.inicioY+inicioCenarioY,
                       20, 17, 0);
        DesenharSprite(spriteInicio,
                       X+mapaAtual.inicioX-5+inicioCenarioX,
                       Y+mapaAtual.inicioY+43+inicioCenarioY,
                       50, 87, 0);
    }

    if(mapaAtual.finalX != -1 && mapaAtual.finalY != -1)
    {
        DesenharSprite(spriteX,
                       X+mapaAtual.finalX+inicioCenarioX,
                       Y+mapaAtual.finalY+inicioCenarioY,
                       20, 17, 0);
        DesenharSprite(spriteFinal,
                       X+mapaAtual.finalX-5+inicioCenarioX,
                       Y+mapaAtual.finalY+43+inicioCenarioY,
                       50, 87, 0);
    }
}


void desenharLuz(double X, double Y)
{
    X = X + inicioCenarioX;
    Y = Y + inicioCenarioY;
    if(tipoSelecionado == CAMINHO)
    {
        if(inimigoSelecionado == -1)
        {
            DesenharSprite(spriteLuz, X+mouseX, Y+mouseY, 50, 50, 0);
        }
        else
        {
            DesenharSprite(spriteLuz, X+mapaAtual.obstaculos[inimigoSelecionado].xInicial,
                                      Y+mapaAtual.obstaculos[inimigoSelecionado].yInicial, 50, 50, 0);
        }
    }
}

void desenharCaminho(double X, double Y)
{
    X = X + inicioCenarioX;
    Y = Y + inicioCenarioY;

    if(tipoSelecionado == CAMINHO)
    {
        if(inimigoSelecionado != -1)
        {
            for(int i=0; i<mapaAtual.obstaculos[inimigoSelecionado].quantidadeCaminhos; i++)
            {
                double origemX, origemY;
                double destinoX, destinoY;

                if(i == 0)
                {
                    origemX = mapaAtual.obstaculos[inimigoSelecionado].xInicial;
                    origemY = mapaAtual.obstaculos[inimigoSelecionado].yInicial;
                }
                else
                {
                    origemX = mapaAtual.obstaculos[inimigoSelecionado].caminho[i-1].destinoX;
                    origemY = mapaAtual.obstaculos[inimigoSelecionado].caminho[i-1].destinoY;
                }

                destinoX = mapaAtual.obstaculos[inimigoSelecionado].caminho[i].destinoX;
                destinoY = mapaAtual.obstaculos[inimigoSelecionado].caminho[i].destinoY;

                DesenharLinhaSimples(X+origemX,  Y+origemY,
                                     X+destinoX, Y+destinoY,
                                     VERMELHO);
            }

            double origemX, origemY;
            int indice = mapaAtual.obstaculos[inimigoSelecionado].quantidadeCaminhos;
            if(indice == 0)
            {
                origemX = mapaAtual.obstaculos[inimigoSelecionado].xInicial;
                origemY = mapaAtual.obstaculos[inimigoSelecionado].yInicial;
            }
            else
            {
                origemX = mapaAtual.obstaculos[inimigoSelecionado].caminho[indice-1].destinoX;
                origemY = mapaAtual.obstaculos[inimigoSelecionado].caminho[indice-1].destinoY;
            }

            DesenharLinhaSimples(X+origemX,Y+origemY,
                                 X+mouseX, Y+mouseY,
                                 VERMELHO);

        }
    }
}

void desenharInformacoes(double X, double Y)
{
    char String[1000];
    char modo[1000];

    switch(tipoSelecionado)
    {
        case VAZIO:
        {
            sprintf(modo, "Inserir vazio");
        }   break;
        case INICIO:
        {
            sprintf(modo, "Inserir Area inicial");
        }   break;
        case FINAL:
        {
            sprintf(modo, "Inserir Area final");
        }   break;
        case ANDAVEL:
        {
            sprintf(modo, "Inserir Area andavel");
        }   break;
        case OBSTACULO:
        {
            sprintf(modo, "Inserir/Remover obstaculos");
        }   break;
        case MOEDA:
        {
            sprintf(modo, "Inserir/Remover moedas");
        }   break;
        case INICIO_PONTO:
        {
            sprintf(modo, "Definir ponto de partida");
        }   break;
        case FINAL_PONTO:
        {
            sprintf(modo, "Definir ponto de chegada");
        }   break;
        case CAMINHO:
        {
            sprintf(modo, "Inserir caminhos");
        }   break;
        case PIVO:
        {
            sprintf(modo, "Inserir pivo");
        }   break;

    }

    sprintf(String, "Modo Selecionado (numeros):");
    EscreverEsquerda(String, 15,700, FontePreta);
    EscreverEsquerda(modo, 25,675, FonteBranca);

    sprintf(String, "Tamanho do cenario:");
    EscreverEsquerda(String, 15,600, FontePreta);
    sprintf(String, "%dx%d",QTD_BLOCOS,QTD_BLOCOS);
    EscreverEsquerda(String, 25,575, FonteBranca);

    sprintf(String, "Alinhamento do mouse: (espaco)");
    EscreverEsquerda(String, 15,500, FontePreta);

    switch(alinharMouse)
    {
        case 0:
        {
            sprintf(String, "desativado");
            EscreverEsquerda(String, 25,475, FonteBranca);
        }   break;
        case 1:
        {
            sprintf(String, "alinhado pelo centro");
            EscreverEsquerda(String, 25,475, FonteVermelha);
        }   break;
        case 2:
        {
            sprintf(String, "alinhado pelo cruzamento");
            EscreverEsquerda(String, 25,475, FonteVermelha);
        }   break;
        case 3:
        {
            sprintf(String, "alinhado na horizontal");
            EscreverEsquerda(String, 25,475, FonteVermelha);
        }   break;
        case 4:
        {
            sprintf(String, "alinhado na vertical");
            EscreverEsquerda(String, 25,475, FonteVermelha);
        }   break;
        case 5:
        {
            sprintf(String, "bordas verticais");
            EscreverEsquerda(String, 25,475, FonteVermelha);
        }   break;
        case 6:
        {
            sprintf(String, "bordas horizontais");
            EscreverEsquerda(String, 25,475, FonteVermelha);
        }   break;
    }


    sprintf(String, "Estado do cenario: (enter)");
    EscreverEsquerda(String, 15,400, FontePreta);

    if(mapaIniciado == 1)
    {
        sprintf(String, "em movimento");
        EscreverEsquerda(String, 25,375, FonteVermelha);
    }
    else
    {
        sprintf(String, "parado");
        EscreverEsquerda(String, 25,375, FonteBranca);
    }

    sprintf(String, "Tempo total do caminho: (c/v)");
    EscreverEsquerda(String, 15,300, FontePreta);
    sprintf(String, "%.1f",tempoCaminho);
    EscreverEsquerda(String, 25,275, FonteVermelha);

    sprintf(String, "Caminho angular: (a)");
    EscreverEsquerda(String, 15,200, FontePreta);
    if(angularAtivado == 1)
    {
        sprintf(String, "ativado");
        EscreverEsquerda(String, 25,175, FonteVermelha);
    }
    else
    {
        sprintf(String, "desativado");
        EscreverEsquerda(String, 25,175, FonteBranca);
    }

    sprintf(String, "Direcao angular: (s)");
    EscreverEsquerda(String, 15,100, FontePreta);
    if(direcaoAngular == 1)
    {
        sprintf(String, "positiva");
        EscreverEsquerda(String, 25,75, FonteVermelha);
    }
    else
    {
        sprintf(String, "negativa");
        EscreverEsquerda(String, 25,75, FonteBranca);
    }

    sprintf(String, "Angulo de troca: (d/f)");
    EscreverEsquerda(String, 1075,700, FontePreta);
    sprintf(String, "%.0f",anguloSwap);
    EscreverEsquerda(String, 1085,675, FonteBranca);

    sprintf(String, "Tamanho grade: (cima/baixo)");
    EscreverEsquerda(String, 1075,600, FontePreta);
    sprintf(String, "%d", tamanhoGrade);
    EscreverEsquerda(String, 1085,575, FonteBranca);

    sprintf(String, "Tempo parado: (j/k)");
    EscreverEsquerda(String, 1075,500, FontePreta);
    sprintf(String, "%.1f", tempoParado);
    EscreverEsquerda(String, 1085,475, FonteBranca);

    sprintf(String, "Angulo parada: (g/h)");
    EscreverEsquerda(String, 1075,400, FontePreta);
    sprintf(String, "%.0f", anguloParado);
    EscreverEsquerda(String, 1085,375, FonteBranca);

    sprintf(String, "Salvar posicao mouse (i)");
    EscreverEsquerda(String, 1075, 300, FontePreta);

    sprintf(String, "Carregar posicao salva (u)");
    EscreverEsquerda(String, 1075, 250, FontePreta);

    sprintf(String, "Salvar mapa (F1)");
    EscreverEsquerda(String, 1075, 200, FontePreta);

    sprintf(String, "Carregar mapa (F2)");
    EscreverEsquerda(String, 1075, 150, FontePreta);


}

void desenharPivo()
{
    if(tipoSelecionado == PIVO)
    {
        DesenharRetangulo(mouseX + inicioCenarioX -5,
                          mouseY + inicioCenarioY -5, 10, 10, VERMELHO);
    }

    for(int i=0; i<QTD_MAX_PIVO; i++)
    {
        if(mapaAtual.pivo[i].existe == 1)
        {
            DesenharRetangulo(mapaAtual.pivo[i].x + inicioCenarioX -5,
                              mapaAtual.pivo[i].y + inicioCenarioY -5, 10, 10, VERMELHO);
        }
    }
}

void ExibirAviso(char* String)
{
    strcpy(StringAviso, String);
    ReiniciarTimer(TimerAviso);
}

void desenharAviso()
{
    if(TempoDecorrido(TimerAviso) < 2)
    {
        EscreverEsquerda(StringAviso, 370, 700, FontePretaGrande);
    }
}

void desenhar()
{
    IniciarDesenho();

    DesenharRetangulo(0, 0, ALT_TELA, LARG_TELA, AZUL_FORA);

    desenharCenario(0,0);
    desenharBordas(0,0);
    desenharLimites(0,0);
    desenharMoedas(0,0);
    desenharLuz(0,0);
    desenharObstaculos(0,0);
    desenharPlacas(0,0);
    desenharCaminho(0,0);
    desenharInformacoes(0,0);
    desenharAviso();

    EncerrarDesenho();
}


int buscarObstaculoVazio()
{
    for(int i=0; i<QTD_MAX_OBSTACULOS; i++)
    {
        if(mapaAtual.obstaculos[i].existe == 0)
        {
            return i;
        }
    }
    return -1;
}

void adicionarObstaculo(double X, double Y)
{
    int i = buscarObstaculoVazio();

    if(i == -1)
    {
        return;
    }

    mapaAtual.obstaculos[i].xInicial = X;
    mapaAtual.obstaculos[i].yInicial = Y;
    mapaAtual.obstaculos[i].x = X;
    mapaAtual.obstaculos[i].y = Y;
    mapaAtual.obstaculos[i].caminhoAtual = 0;
    mapaAtual.obstaculos[i].quantidadeCaminhos = 0;
    mapaAtual.obstaculos[i].existe = 1;
}

int buscarMoedaVazia()
{
    for(int i=0; i<QTD_MAX_MOEDAS; i++)
    {
        if(mapaAtual.moedas[i].existe == 0)
        {
            return i;
        }
    }
    return -1;
}

void adicionarMoeda(double X, double Y)
{
    int i = buscarMoedaVazia();

    if(i == -1)
    {
        return;
    }

    mapaAtual.moedas[i].X = X;
    mapaAtual.moedas[i].Y = Y;
    mapaAtual.moedas[i].existe = 1;
}

int buscarObstaculoClicado()
{
    int indice = -1;
    double distancia = 9999999;

    for(int i=0; i<QTD_MAX_OBSTACULOS; i++)
    {
        if(mapaAtual.obstaculos[i].existe == 1)
        {
            double dist = DistanciaEntrePontos(mouseX, mouseY, mapaAtual.obstaculos[i].xInicial, mapaAtual.obstaculos[i].yInicial);
            if(dist < distancia)
            {
                distancia = dist;
                indice = i;
            }
        }
    }
    return indice;
}

void removerObstaculo(int indice)
{
    mapaAtual.obstaculos[indice].existe = 0;
    mapaAtual.obstaculos[indice].quantidadeCaminhos = 0;
}

int buscarMoedaClicada()
{
    int indice = -1;
    double distancia = 9999999;

    for(int i=0; i<QTD_MAX_MOEDAS; i++)
    {
        if(mapaAtual.moedas[i].existe == 1)
        {
            double dist = DistanciaEntrePontos(mouseX, mouseY, mapaAtual.moedas[i].X, mapaAtual.moedas[i].Y);
            if(dist < distancia)
            {
                distancia = dist;
                indice = i;
            }
        }
    }
    return indice;
}

void removerMoeda(int indice)
{
    mapaAtual.moedas[indice].existe = 0;
}

void adicionarCaminho(int indice)
{
    mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].destinoX = mouseX;
    mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].destinoY = mouseY;
    mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].angular = angularAtivado;
    mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].IteracoesParado = tempoParado/Periodo;
    mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].anguloParada = -1;

    mapaAtual.obstaculos[inimigoSelecionado].quantidadeCaminhos++;

    double distancia = 0;
    int quantidade = mapaAtual.obstaculos[inimigoSelecionado].quantidadeCaminhos;
    for(int i=0; i<quantidade; i++)
    {
        if(i == 0)
        {
            distancia = distancia + DistanciaEntrePontos(mapaAtual.obstaculos[inimigoSelecionado].caminho[i].destinoX,
                                                         mapaAtual.obstaculos[inimigoSelecionado].caminho[i].destinoY,
                                                         mapaAtual.obstaculos[inimigoSelecionado].xInicial,
                                                         mapaAtual.obstaculos[inimigoSelecionado].yInicial);
        }
        else
        {
            distancia = distancia + DistanciaEntrePontos(mapaAtual.obstaculos[inimigoSelecionado].caminho[i].destinoX,
                                                         mapaAtual.obstaculos[inimigoSelecionado].caminho[i].destinoY,
                                                         mapaAtual.obstaculos[inimigoSelecionado].caminho[i-1].destinoX,
                                                         mapaAtual.obstaculos[inimigoSelecionado].caminho[i-1].destinoY);
        }
    }

    for(int i=0; i<quantidade; i++)
    {
        mapaAtual.obstaculos[inimigoSelecionado].caminho[i].velocidade = distancia*Periodo/(tempoCaminho);
    }

    Caminho* caminho = &mapaAtual.obstaculos[inimigoSelecionado].caminho[indice];

    if(mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].angular == 1)
    {
        caminho->velocidade = (360.0*Periodo)/(tempoCaminho);
        caminho->direcao = direcaoAngular;
        caminho->direcaoAtual = direcaoAngular;
        caminho->anguloSwap = anguloSwap;
        caminho->anguloSwapAtual = anguloSwap;
    }

    if(mapaAtual.obstaculos[inimigoSelecionado].caminho[indice].IteracoesParado != 0)
    {
        caminho->anguloParada = anguloParado;
        caminho->anguloParadaAtual =  anguloParado;
        caminho->IteracoesParadoAtual = 0;
    }
}

int buscarPivoVazio()
{
    for(int i=0; i<QTD_MAX_PIVO; i++)
    {
        if(mapaAtual.pivo[i].existe == 0)
        {
            return i;
        }
    }
    return -1;
}

void adicionarPivo(int x, int y)
{
    int indice = buscarPivoVazio();
    if(indice == -1)
    {
        return;
    }
    mapaAtual.pivo[indice].x = x;
    mapaAtual.pivo[indice].y = y;
    mapaAtual.pivo[indice].existe = 1;
}

void processarMouse()
{
    static int cod = -1;
    static int pressionada = 0;

    switch(alinharMouse)
    {
        case 0:
        {
            mouseX = (PIG_evento.mouse.posX - inicioCenarioX)/tamanhoGrade;
            mouseY = (PIG_evento.mouse.posY - inicioCenarioY)/tamanhoGrade;

            mouseX = mouseX*tamanhoGrade + tamanhoGrade/2;
            mouseY = mouseY*tamanhoGrade + tamanhoGrade/2;

        }   break;
        case 1:
        {
            mouseX = ((double)PIG_evento.mouse.posX-inicioCenarioX)/TAM_BLOCOS;
            mouseY = ((double)PIG_evento.mouse.posY-inicioCenarioY)/TAM_BLOCOS;

            mouseX = mouseX*TAM_BLOCOS + TAM_BLOCOS/2;
            mouseY = mouseY*TAM_BLOCOS + TAM_BLOCOS/2;

        }   break;
        case 2:
        {
            mouseX = ((double)PIG_evento.mouse.posX-inicioCenarioX)/TAM_BLOCOS;
            mouseY = ((double)PIG_evento.mouse.posY-inicioCenarioY)/TAM_BLOCOS;

            mouseX = mouseX*TAM_BLOCOS;
            mouseY = mouseY*TAM_BLOCOS;

        }   break;
        case 3:
        {
            mouseX = PIG_evento.mouse.posX - inicioCenarioX;
        }   break;
        case 4:
        {
            mouseY = PIG_evento.mouse.posY - inicioCenarioY;
        }   break;
        case 5:
        {
            mouseX = ((double)PIG_evento.mouse.posX-inicioCenarioX)/TAM_BLOCOS;
            mouseY = ((double)PIG_evento.mouse.posY-inicioCenarioY)/TAM_BLOCOS;

            mouseX = mouseX*TAM_BLOCOS + TAM_BLOCOS;
            mouseY = mouseY*TAM_BLOCOS + TAM_BLOCOS/2;
        }   break;
        case 6:
        {
            mouseX = ((double)PIG_evento.mouse.posX-inicioCenarioX)/TAM_BLOCOS;
            mouseY = ((double)PIG_evento.mouse.posY-inicioCenarioY)/TAM_BLOCOS;

            mouseX = mouseX*TAM_BLOCOS + TAM_BLOCOS/2;
            mouseY = mouseY*TAM_BLOCOS + TAM_BLOCOS;
        }   break;
    }

    if(PIG_meuTeclado[TECLA_u])
    {
        mouseX = mouseXSalvo;
        mouseY = mouseYSalvo;
    }

    if(PIG_evento.mouse.acao == 1025)
    {
        pressionada = 1;
    }
    if(PIG_evento.mouse.acao == 1026)
    {
        pressionada = 0;
    }

    if(pressionada == 1 && PIG_evento.mouse.botao == 1)
    {
        if(tipoSelecionado != OBSTACULO && tipoSelecionado != MOEDA &&
           tipoSelecionado != INICIO_PONTO && tipoSelecionado != FINAL_PONTO &&
           tipoSelecionado != CAMINHO && tipoSelecionado != PIVO)
        {
            mapaAtual.cenario[mouseX/TAM_BLOCOS][mouseY/TAM_BLOCOS] = tipoSelecionado;
        }
    }

    if(PIG_Botao == 1)
    {
        if(tipoSelecionado == OBSTACULO)
        {
            adicionarObstaculo(mouseX,mouseY);
        }
        if(tipoSelecionado == MOEDA)
        {
            adicionarMoeda(mouseX,mouseY);
        }
        if(tipoSelecionado == INICIO_PONTO)
        {
            mapaAtual.inicioX = mouseX;
            mapaAtual.inicioY = mouseY;
        }
        if(tipoSelecionado == FINAL_PONTO)
        {
            mapaAtual.finalX = mouseX;
            mapaAtual.finalY = mouseY;
        }
        if(tipoSelecionado == CAMINHO)
        {
            inimigoSelecionado = buscarObstaculoClicado();
        }
        if(tipoSelecionado == PIVO)
        {
            adicionarPivo(mouseX, mouseY);
        }
    }

    if(PIG_Botao == 3)
    {
        if(tipoSelecionado == OBSTACULO)
        {
            int indice = buscarObstaculoClicado();
            removerObstaculo(indice);
        }
        if(tipoSelecionado == MOEDA)
        {
            int indice = buscarMoedaClicada();
            removerMoeda(indice);
        }
        if(tipoSelecionado == CAMINHO)
        {
            int indice = mapaAtual.obstaculos[inimigoSelecionado].quantidadeCaminhos;
            adicionarCaminho(indice);
        }
        if(tipoSelecionado == PIVO)
        {
            for(int i=0; i<QTD_MAX_PIVO; i++)
            {
                mapaAtual.pivo[i].existe = 0;
            }
        }
    }
}


void inicializarMatrizColisao()
{
    for(int i=0; i<ALT_TELA; i++)
    {
        for(int j=0; j<ALT_TELA; j++)
        {
            matrizColisao[i][j] = 1;
        }
    }
}

void adicionarColisao(double X, double Y, double Altura, double Largura)
{
    for(int i=X; i<X+Largura; i++)
    {
        for(int j=Y; j<Y+Altura; j++)
        {
            matrizColisao[i][j] = 0;
        }
    }
}

void incluirColisaoParedes()
{
    for(int i=0; i<QTD_BLOCOS; i++)
    {
        for(int j=0; j<QTD_BLOCOS; j++)
        {
            if(mapaAtual.cenario[i][j] == VAZIO)
            {
                if(i+1 < QTD_BLOCOS && mapaAtual.cenario[i+1][j] != VAZIO)
                {
                    adicionarColisao(    (i+1)*TAM_BLOCOS - LARGURA_BORDA,
                                             j*TAM_BLOCOS,
                                               TAM_BLOCOS, LARGURA_BORDA);

                    if(mapaAtual.cenario[i+1][j+1] == VAZIO)
                    {
                        adicionarColisao(  (i+1)*TAM_BLOCOS - LARGURA_BORDA,
                                            (j+1)*TAM_BLOCOS,
                                                  LARGURA_BORDA, LARGURA_BORDA);
                    }

                    if(mapaAtual.cenario[i+1][j-1] == VAZIO)
                    {
                        adicionarColisao(  (i+1)*TAM_BLOCOS - LARGURA_BORDA,
                                              (j)*TAM_BLOCOS - LARGURA_BORDA,
                                                  LARGURA_BORDA, LARGURA_BORDA);
                    }

                }
                if(i-1 >= 0 && mapaAtual.cenario[i-1][j] != VAZIO)
                {
                    adicionarColisao((i)*TAM_BLOCOS,
                                        j*TAM_BLOCOS,
                                          TAM_BLOCOS, LARGURA_BORDA);

                    if(mapaAtual.cenario[i-1][j+1] == VAZIO)
                    {
                        adicionarColisao((i)*TAM_BLOCOS,
                                        (j+1)*TAM_BLOCOS,
                                        LARGURA_BORDA, LARGURA_BORDA);
                    }

                    if(mapaAtual.cenario[i-1][j-1] == VAZIO)
                    {
                        adicionarColisao((i)*TAM_BLOCOS,
                                          (j)*TAM_BLOCOS - LARGURA_BORDA,
                                        LARGURA_BORDA, LARGURA_BORDA);
                    }
                }
//
//
                if(j+1 < QTD_BLOCOS && mapaAtual.cenario[i][j+1] != VAZIO)
                {
                    adicionarColisao(i*TAM_BLOCOS,
                                     (j+1)*TAM_BLOCOS - LARGURA_BORDA,
                                      LARGURA_BORDA, TAM_BLOCOS);
                }
                if(j-1 >= 0 && mapaAtual.cenario[i][j-1] != VAZIO)
                {
                    adicionarColisao(i*TAM_BLOCOS,
                                     (j)*TAM_BLOCOS,
                                     LARGURA_BORDA, TAM_BLOCOS);
                }
            }
        }
    }
}

    double espacoReservado[QTD_MAX_OBSTACULOS];

void movimentarObstaculos()
{
    for(int i=0; i<QTD_MAX_OBSTACULOS; i++)
    {
        if(mapaAtual.obstaculos[i].existe == 1 && mapaAtual.obstaculos[i].quantidadeCaminhos != 0)
        {
            double vx, vy;
            Obstaculo* obs = &mapaAtual.obstaculos[i];
            int caminho = obs->caminhoAtual;

            double dist = DistanciaEntrePontos(obs->x, obs->y, obs->caminho[caminho].destinoX, obs->caminho[caminho].destinoY);
            if(obs->caminho[caminho].angular == 1)
            {
                double ang = AnguloEntrePontos    (obs->caminho[caminho].destinoX, obs->caminho[caminho].destinoY, obs->x, obs->y);
                double raio = DistanciaEntrePontos(obs->x, obs->y, obs->caminho[caminho].destinoX, obs->caminho[caminho].destinoY);
                double direcao = obs->caminho[caminho].direcaoAtual;

                ang = ang + direcao*obs->caminho[caminho].velocidade;

                /// Swap
                obs->caminho[caminho].anguloSwapAtual = obs->caminho[caminho].anguloSwapAtual - fabs(obs->caminho[caminho].velocidade);
                if(obs->caminho[caminho].anguloSwapAtual <= 0 && obs->caminho[caminho].anguloSwap != -1)
                {
                    obs->caminho[caminho].anguloSwapAtual = obs->caminho[caminho].anguloSwap;
                    obs->caminho[caminho].direcaoAtual = -obs->caminho[caminho].direcaoAtual;
                }

                /// Parada
                if(obs->caminho[caminho].anguloParada != -1)
                {
                    if(obs->caminho[caminho].anguloParadaAtual <= 0)
                    {
                        obs->caminho[caminho].IteracoesParadoAtual++;
                        if(obs->caminho[caminho].IteracoesParadoAtual == obs->caminho[caminho].IteracoesParado)
                        {
                            obs->caminho[caminho].IteracoesParadoAtual = 0;
                            obs->caminho[caminho].anguloParadaAtual = obs->caminho[caminho].anguloParada;
                        }
                        ang = ang - direcao*obs->caminho[caminho].velocidade;
                        obs->caminho[caminho].anguloSwapAtual = obs->caminho[caminho].anguloSwapAtual + fabs(obs->caminho[caminho].velocidade);
                    }
                    else
                    {
                        obs->caminho[caminho].anguloParadaAtual = obs->caminho[caminho].anguloParadaAtual - fabs(obs->caminho[caminho].velocidade);
                        if(obs->caminho[caminho].anguloParadaAtual <= 0)
                        {
                            if(obs->caminho[caminho].IteracoesParadoAtual == 0)
                            {
                                ang = ang + obs->caminho[caminho].anguloParadaAtual;
                            }
                        }
                    }
                }

                obs->x = obs->caminho[caminho].destinoX + raio*cos(DEGTORAD*ang);
                obs->y = obs->caminho[caminho].destinoY + raio*sin(DEGTORAD*ang);
            }
            else
            {
                double distAnterior = DistanciaEntrePontos(obs->x, obs->y, obs->caminho[caminho].destinoX, obs->caminho[caminho].destinoY);
                double velocidade = obs->caminho[caminho].velocidade;
                double xAnterior = obs->x;
                double yAnterior = obs->y;

                if(fabs(espacoReservado[i]) >= velocidade)
                {
                    if(espacoReservado[i] > 0)
                    {
                        espacoReservado[i] = espacoReservado[i] - velocidade;
                        velocidade = 0;
                    }
                    if(espacoReservado[i] < 0)
                    {
                        espacoReservado[i] = espacoReservado[i] + velocidade;
                        velocidade = 2.0*velocidade;
                    }
                }

                vx = velocidade * ((obs->caminho[caminho].destinoX - obs->x)/(distAnterior));
                vy = velocidade * ((obs->caminho[caminho].destinoY - obs->y)/(distAnterior));

                obs->x = obs->x + vx;
                obs->y = obs->y + vy;

                double distPosterior = DistanciaEntrePontos(obs->x, obs->y, obs->caminho[caminho].destinoX, obs->caminho[caminho].destinoY);
                double distAnteriorPosterior = DistanciaEntrePontos(obs->x, obs->y, xAnterior, yAnterior);

                if(distPosterior < obs->caminho[caminho].velocidade)
                {
                    obs->x = obs->caminho[caminho].destinoX;
                    obs->y = obs->caminho[caminho].destinoY;

                    if(distAnteriorPosterior < distAnterior)
                    {
                        espacoReservado[i] = espacoReservado[i] + distPosterior;
                    }
                    if(distAnteriorPosterior > distAnterior)
                    {
                        espacoReservado[i] = espacoReservado[i] - distPosterior;
                    }

                    obs->caminhoAtual++;
                    if(obs->caminhoAtual == obs->quantidadeCaminhos)
                    {
                        obs->caminhoAtual = 0;
                    }
                }
            }
        }
    }
}

void reiniciarObstaculos()
{
    for(int i=0; i<QTD_MAX_OBSTACULOS; i++)
    {
        if(mapaAtual.obstaculos[i].existe == 1)
        {
            mapaAtual.obstaculos[i].x = mapaAtual.obstaculos[i].xInicial;
            mapaAtual.obstaculos[i].y = mapaAtual.obstaculos[i].yInicial;
            mapaAtual.obstaculos[i].caminhoAtual = 0;
            espacoReservado[i] = 0;

            for(int j=0; j<mapaAtual.obstaculos[i].quantidadeCaminhos; j++)
            {
                mapaAtual.obstaculos[i].caminho[j].anguloSwapAtual      = mapaAtual.obstaculos[i].caminho[j].anguloSwap;
                mapaAtual.obstaculos[i].caminho[j].anguloParadaAtual    = mapaAtual.obstaculos[i].caminho[j].anguloParada;
                mapaAtual.obstaculos[i].caminho[j].direcaoAtual         = mapaAtual.obstaculos[i].caminho[j].direcao;
                mapaAtual.obstaculos[i].caminho[j].IteracoesParadoAtual = 0;
            }
        }
    }
}

void salvarMapa(int id)
{
    char String[1000];
    sprintf(String,"mapas/mapa%d",id);
    FILE* f = fopen(String,"wb");
    fwrite(&mapaAtual, 1, sizeof(Mapa), f);
    fclose(f);
    printf("%s salvo.\n",String);
}

void definirQuantidadeBlocos(int quantidade)
{
    QTD_BLOCOS = quantidade;
    TAM_BLOCOS = ALT_TELA/QTD_BLOCOS;
    TAM_PERSONAGEM = (TAM_BLOCOS*(24.0/32.0));
    TAM_OBSTACULO = (TAM_BLOCOS*(17.0/32.0));

    inicioCenarioX = (LARG_TELA-(QTD_BLOCOS*TAM_BLOCOS))/2;
    inicioCenarioY = (ALT_TELA-(QTD_BLOCOS*TAM_BLOCOS))/2;
}

int carregarMapa(int id)
{
    char String[1000];
    sprintf(String,"mapas/mapa%d",id);

    FILE* f = fopen(String,"rb");
    if(f == NULL)
    {
        return 1;
    }
    else
    {
        fread(&mapaAtual, 1, sizeof(Mapa), f);
        fclose(f);

        definirQuantidadeBlocos(mapaAtual.quantidadeBlocos);

        reiniciarObstaculos();
        return 0;
    }
}


int buscarIdVazio()
{
    char String[1000];
    int id = 0;

    while(1)
    {
        sprintf(String,"mapas/mapa%d",id);
        FILE* f = fopen(String,"rb");
        if(f == NULL)
        {
            return id;
        }
        else
        {
            id++;
            fclose(f);
        }
    }
}

void processarTeclado()
{
    if(PIG_Tecla == TECLA_ENTER)
    {
        mapaIniciado = -mapaIniciado;

        if(mapaIniciado == -1)
        {
            reiniciarObstaculos();
        }
    }
    if(PIG_Tecla == TECLA_BARRAESPACO)
    {
        alinharMouse = (alinharMouse + 1)%7;

        if(alinharMouse == 3 || alinharMouse == 4)
        {
            mouseX = PIG_evento.mouse.posX - inicioCenarioX;
            mouseY = PIG_evento.mouse.posY - inicioCenarioY;
        }
    }
    if(PIG_Tecla == TECLA_i)
    {
        mouseXSalvo = mouseX;
        mouseYSalvo = mouseY;
    }


    if(PIG_Tecla == TECLA_CIMA)
    {
        tamanhoGrade++;
    }
    if(PIG_Tecla == TECLA_BAIXO)
    {
        tamanhoGrade--;
        if(tamanhoGrade == 0)
        {
            tamanhoGrade = 1;
        }
    }


    if(PIG_Tecla == TECLA_a)
    {
        angularAtivado = -angularAtivado;
    }
    if(PIG_Tecla == TECLA_s)
    {
        direcaoAngular = -direcaoAngular;
    }


    if(PIG_Tecla == TECLA_d)
    {
        anguloSwap = anguloSwap - 10;
        if(anguloSwap <= 0)
        {
            anguloSwap = -1;
        }
    }
    if(PIG_Tecla == TECLA_f)
    {
        if(anguloSwap == -1)
        {
            anguloSwap = 0;
        }
        anguloSwap = anguloSwap + 10;
    }


    if(PIG_Tecla == TECLA_g)
    {
        anguloParado = anguloParado - 10;
        if(anguloParado <= 0)
        {
            anguloParado = -1;
        }
    }
    if(PIG_Tecla == TECLA_h)
    {
        if(anguloParado == -1)
        {
            anguloParado = 0;
        }
        anguloParado = anguloParado + 10;
    }


    if(PIG_Tecla == TECLA_j)
    {
        tempoParado = tempoParado - 0.1;
        if(tempoParado <= 0)
        {
            tempoParado = 0;
        }
    }
    if(PIG_Tecla == TECLA_k)
    {
        tempoParado = tempoParado + 0.1;
    }


    if(PIG_Tecla == TECLA_1)
    {
        tipoSelecionado = VAZIO;
    }
    if(PIG_Tecla == TECLA_2)
    {
        tipoSelecionado = INICIO;
    }
    if(PIG_Tecla == TECLA_3)
    {
        tipoSelecionado = FINAL;
    }
    if(PIG_Tecla == TECLA_4)
    {
        tipoSelecionado = ANDAVEL;
    }
    if(PIG_Tecla == TECLA_5)
    {
        tipoSelecionado = OBSTACULO;
    }
    if(PIG_Tecla == TECLA_6)
    {
        tipoSelecionado = MOEDA;
    }
    if(PIG_Tecla == TECLA_7)
    {
        tipoSelecionado = INICIO_PONTO;
    }
    if(PIG_Tecla == TECLA_8)
    {
        tipoSelecionado = FINAL_PONTO;
    }
    if(PIG_Tecla == TECLA_9)
    {
        tipoSelecionado = CAMINHO;
        inimigoSelecionado = -1;
    }

    if(PIG_Tecla == TECLA_z)
    {
        velocidadeInimigo = velocidadeInimigo - 0.1;
    }
    if(PIG_Tecla == TECLA_x)
    {
        velocidadeInimigo = velocidadeInimigo + 0.1;
    }

    if(PIG_Tecla == TECLA_c)
    {
        tempoCaminho = tempoCaminho - 0.1;
    }
    if(PIG_Tecla == TECLA_v)
    {
        tempoCaminho = tempoCaminho + 0.1;
    }



    if(PIG_Tecla == TECLA_F1)
    {
        int id = buscarIdVazio();
        salvarMapa(id);


        char String[1000];
        sprintf(String,"mapa%d salvo com sucesso!",id);
        ExibirAviso(String);
    }

    if(PIG_Tecla == TECLA_F2)
    {
        static int id = 0;
        int erro = carregarMapa(id);
        if(erro == 1)
        {
            id = 0;
            carregarMapa(id);
        }
        id++;

        char String[1000];
        sprintf(String,"mapa%d carregado com sucesso!",id-1);
        ExibirAviso(String);
    }
}

void inicializarMapaAtual()
{
    for(int i=0; i<QTD_BLOCOS; i++)
    {
        for(int j=0; j<QTD_BLOCOS; j++)
        {
            mapaAtual.cenario[i][j] = VAZIO;
        }
    }

    for(int i=0; i<QTD_MAX_OBSTACULOS; i++)
    {
        mapaAtual.obstaculos[i].existe = 0;
    }

    for(int i=0; i<QTD_MAX_MOEDAS; i++)
    {
        mapaAtual.moedas[i].existe = 0;
    }

    for(int i=0; i<QTD_MAX_PIVO; i++)
    {
        mapaAtual.pivo[i].existe = 0;
    }

    mapaAtual.finalX = -1;
    mapaAtual.finalY = -1;
    mapaAtual.inicioX = -1;
    mapaAtual.inicioY = -1;

    mapaAtual.quantidadeBlocos = quantidadeBlocos;
}

void configuracoesIniciais()
{
    printf("Digite o tamanho do mapa: (minimo: 10, maximo: 100, recomendado: 22)\n\n");
    scanf("%d", &quantidadeBlocos);

    if(quantidadeBlocos < 10)
    {
        quantidadeBlocos = 10;
    }
    if(quantidadeBlocos > 100)
    {
        quantidadeBlocos = 100;
    }

    CriarJanela("Hardest Game", 0);

    Periodo = 0.005;
    tipoSelecionado = 0;
    inimigoSelecionado = -1;
    mapaIniciado = -1;
    alinharMouse = 0;
    velocidadeInimigo = 2;
    tempoCaminho = 2;
    angularAtivado = -1;
    direcaoAngular = 1;
    anguloSwap = -1;
    tamanhoGrade = 1;
    tempoParado = 0;
    anguloParado = -1;

    definirQuantidadeBlocos(quantidadeBlocos);

    spriteObstaculo = CriarSprite("imagens/obstaculo.bmp");
    spriteMoeda = CriarSprite("imagens/moeda.bmp");
    spriteInicio = CriarSprite("imagens/inicio.png");
    spriteFinal = CriarSprite("imagens/final.png");
    spriteX = CriarSprite("imagens/x1.png");
    spriteLuz = CriarSprite("imagens/luzBranca.png",0);
    DefinirColoracao(spriteLuz, VERMELHO);

    FontePreta = CriarFonteNormal("fontes/arial.ttf", 16, PRETO, 0, PRETO);
    FonteBranca = CriarFonteNormal("fontes/arial.ttf", 16, BRANCO, 0, BRANCO);
    FonteVermelha = CriarFonteNormal("fontes/arial.ttf", 16, VERMELHO, 0, VERMELHO);
    FontePretaGrande = CriarFonteNormal("fontes/padrao.ttf", 25, PRETO, 0, PRETO);

    TimerGeral = CriarTimer();
    TimerAviso = CriarTimer();
    StringAviso[0] = '\0';

    inicializarMapaAtual();
    inicializarMatrizColisao();
}

int main(int argc, char* args[])
{
    configuracoesIniciais();

    while(PIG_JogoRodando == 1)
    {
        AtualizarJanela();

        processarTeclado();
        processarMouse();

        if(TempoDecorrido(TimerGeral) >= Periodo)
        {
            if(mapaIniciado == 1)
            {
                movimentarObstaculos();
            }
            desenhar();

            ReiniciarTimer(TimerGeral);
        }
    }
    FinalizarJanela();

    return 0;
}
