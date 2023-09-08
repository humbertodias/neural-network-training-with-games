
#include "PIG.h"
#include "PIG_Extras.h"

#define     QTD_MAX_PROJETEIS   100000
#define     QTD_MAX_RASTRO      100000

typedef struct vetor
{
    double x, y;
}   Vetor;

typedef struct corpo
{
    double massa;
    double raio;
    vetor posicao;
    vetor velocidade;
    vetor aceleracao;

}   Corpo;

    Corpo planeta;

    Corpo projeteis[QTD_MAX_PROJETEIS];
    int qtdProjeteisAtuais;

    int spritePlaneta, spriteProjetil, spriteCanhao, spriteTorre, spriteCeu;
    int timerGeral;

    Vetor rastro[QTD_MAX_RASTRO];
    int qtdRastro;


void adicionarProjetil(Vetor posicao, Vetor velocidade, Vetor aceleracao, double massa, double raio)
{
    int i = qtdProjeteisAtuais;

    projeteis[i].posicao = posicao;
    projeteis[i].velocidade = velocidade;
    projeteis[i].aceleracao = aceleracao;
    projeteis[i].massa = massa;
    projeteis[i].raio = raio;

    qtdProjeteisAtuais = qtdProjeteisAtuais + 1;
    qtdRastro = 0;
}

void configuracoesIniciais()
{
    // CriarJanela("Canhão de Newton", 2560, 1080);
    CriarJanela("Canhão de Newton", 0);

    qtdProjeteisAtuais = 0;
    qtdRastro = 0;

    spritePlaneta   = CriarSprite("imagens/terraDia.png", 0);
    spriteProjetil  = CriarSprite("imagens/projetil.png", 0);
    spriteCanhao    = CriarSprite("imagens/canhao.png", 0);
    spriteTorre     = CriarSprite("imagens/torre.png", 0);
    spriteCeu       = CriarSprite("imagens/ceu.png", 0);

    planeta.massa = 1000000.0;
    planeta.raio = 350.0;
    planeta.aceleracao.x = 0;
    planeta.aceleracao.y = 0;
    planeta.velocidade.x = 0;
    planeta.velocidade.y = 0;
    planeta.posicao.x = LARG_TELA/2.0;
    planeta.posicao.y = ALT_TELA/2.0;

    timerGeral = CriarTimer();
}

void desenharProjeteis()
{
    for(int i=0; i<qtdProjeteisAtuais; i++)
    {
        // DesenharSprite(spriteProjetil,
        //                    XVirtualParaReal(projeteis[i].posicao.x, projeteis[i].posicao.y),
        //                    YVirtualParaReal(projeteis[i].posicao.x, projeteis[i].posicao.y),
        //                    tamanhoVirtualParaReal(2.0*projeteis[i].raio),
        //                    tamanhoVirtualParaReal(2.0*projeteis[i].raio),
        //                    0, 1, BRANCO);
        DesenharSprite(spriteProjetil,
                           XVirtualParaReal(projeteis[i].posicao.x, projeteis[i].posicao.y),
                           YVirtualParaReal(projeteis[i].posicao.x, projeteis[i].posicao.y),
                           tamanhoVirtualParaReal(2.0*projeteis[i].raio),
                           tamanhoVirtualParaReal(2.0*projeteis[i].raio),
                           0);

    }
}

void desenharRastro()
{
    for(int i=0; i<qtdRastro-1; i++)
    {
        double xAtual = rastro[i].x;
        double yAtual = rastro[i].y;

        double xProximo = rastro[i+1].x;
        double yProximo = rastro[i+1].y;

        DesenharLinhaSimples(XVirtualParaReal(xAtual),
                          YVirtualParaReal(yAtual),
                          XVirtualParaReal(xProximo),
                          YVirtualParaReal(yProximo),VERMELHO);
    }
}

void desenhar()
{
    IniciarDesenho();
    // void DesenharSprite(int id_sprite, int X, int Y, int Largura, int Altura, float Angulo, int referencialVirtual = 1)

    // DesenharSprite(spriteCeu,0,0,LARG_TELA,ALT_TELA,0,0,BRANCO);
    DesenharSprite(spriteCeu,0,0,LARG_TELA,ALT_TELA,0,0);

    // DesenharSprite(spritePlaneta,
    //                    XVirtualParaReal(planeta.posicao.x),
    //                    YVirtualParaReal(planeta.posicao.y),
    //                    tamanhoVirtualParaReal(2.0*planeta.raio),
    //                    tamanhoVirtualParaReal(2.0*planeta.raio),
    //                    0, 1, BRANCO);
    DesenharSprite(spritePlaneta,
                       XVirtualParaReal(planeta.posicao.x),
                       YVirtualParaReal(planeta.posicao.y),
                       tamanhoVirtualParaReal(2.0*planeta.raio),
                       tamanhoVirtualParaReal(2.0*planeta.raio),
                       0, 1);

    // DesenharSprite(spriteCanhao,
    //                    XVirtualParaReal(planeta.posicao.x - 10),
    //                    YVirtualParaReal(planeta.posicao.y + planeta.raio + 15),
    //                    tamanhoVirtualParaReal(25),
    //                    tamanhoVirtualParaReal(25), 0, 1, BRANCO);
    DesenharSprite(spriteCanhao,
                       XVirtualParaReal(planeta.posicao.x - 10),
                       YVirtualParaReal(planeta.posicao.y + planeta.raio + 15),
                       tamanhoVirtualParaReal(25),
                       tamanhoVirtualParaReal(25), 0, 1);


    // DesenharSprite(spriteTorre,
    //                    XVirtualParaReal(planeta.posicao.x),
    //                    YVirtualParaReal(planeta.posicao.y + planeta.raio),
    //                    tamanhoVirtualParaReal(1920/10),
    //                    tamanhoVirtualParaReal(1080/10), 0, 1, BRANCO);
    DesenharSprite(spriteTorre,
                       XVirtualParaReal(planeta.posicao.x),
                       YVirtualParaReal(planeta.posicao.y + planeta.raio),
                       tamanhoVirtualParaReal(1920/10),
                       tamanhoVirtualParaReal(1080/10), 0, 1);

    desenharRastro();
    desenharProjeteis();

    EncerrarDesenho();
}

void verificarTeclado()
{
    if(PIG_Tecla == TECLA_ENTER)
    {
        double x = planeta.posicao.x;
        double y = planeta.posicao.y + planeta.raio + 20;
        Vetor posicao;
        posicao.x = x;
        posicao.y = y;
        Vetor velocidade;
        velocidade.x = 4;
        velocidade.y = 0;
        Vetor aceleracao;
        aceleracao.x = 0;
        aceleracao.y = 0.01;
        adicionarProjetil(posicao,
                          velocidade,  /// 4 entra em orbita
                          aceleracao,
                          1.0, 2.0);
    }
}

void aplicarColisao(Corpo* p1, Corpo* p2)
{
    ///////////////////////////////////////////////////////////////////////////

    double m1 = p1->massa;
    double m2 = p2->massa;

    double u1x = p1->velocidade.x;
    double u1y = p1->velocidade.y;
    double u2x = p2->velocidade.x;
    double u2y = p2->velocidade.y;
                                        //Carregando valores para as variaveis da equa�ao
    double x1 = p1->posicao.x;
    double y1 = p1->posicao.y;
    double x2 = p2->posicao.x;
    double y2 = p2->posicao.y;

    double u1 = sqrt(u1x*u1x + u1y*u1y);
    double u2 = sqrt(u2x*u2x + u2y*u2y);

    //////////////////////////////////////////////////////////////////

    double a1 = atan2(y2-y1, x2-x1);
    double b1 = atan2(u1y, u1x);
    double c1 = b1-a1;

    double a2 = atan2(y1-y2, x1-x2);
    double b2 = atan2(u2y, u2x);
    double c2 = b2-a2;

    double u12 = u1*cos(c1);
    double u11 = u1*sin(c1);

    double u21 = u2*cos(c2);
    double u22 = u2*sin(c2);

    double v12 = (((m1-m2)*u12) - (2*m2*u21))/(m1+m2);
    double v21 = (((m1-m2)*u21) + (2*m1*u12))/(m1+m2);

    double v1x = u11*(-sin(a1)) + v12*(cos(a1));
    double v1y = u11*(cos(a1)) + v12*(sin(a1));

    double v2x = u22*(-sin(a2)) - v21*(cos(a2));
    double v2y = u22*(cos(a2)) - v21*(sin(a2));

    /////////////////////////////////////////////////////////////////////////

    p1->velocidade.x = v1x;
    p1->velocidade.y = v1y;        //Retornando o resultado final para as variaveis das esfera

    p2->velocidade.x = v2x;
    p2->velocidade.y = v2y;
}

void atualizarProjeteis()
{
    Vetor forca;
    double CONSTANTE_GRAVITACIONAL = 0.005;
    double CONSTANTE_RESTITUICAO = 0.9;

    for(int i=0; i<qtdProjeteisAtuais; i++)
    {
        double xProjetil = projeteis[i].posicao.x;
        double yProjetil = projeteis[i].posicao.y;
        double massaProjetil = projeteis[i].massa;
        double raioProjetil = projeteis[i].raio;

        double xPlaneta = planeta.posicao.x;
        double yPlaneta = planeta.posicao.y;
        double massaPlaneta = planeta.massa;
        double raioPlaneta = planeta.raio;

        double distancia = DistanciaEntrePontos(xProjetil, yProjetil, xPlaneta, yPlaneta);
        if(distancia < 1)
        {
            distancia = 1;
        }

        double produtoMassas = massaProjetil*massaPlaneta;
        double produtoDistancia = (distancia*distancia);

        double forcaGravitacional = CONSTANTE_GRAVITACIONAL*produtoMassas/produtoDistancia;

        double cos = (xPlaneta-xProjetil)/distancia;
        double sen = (yPlaneta-yProjetil)/distancia;

        forca.x = forcaGravitacional*cos;
        forca.y = forcaGravitacional*sen;

        projeteis[i].aceleracao.x = forca.x/massaProjetil;
        projeteis[i].aceleracao.y = forca.y/massaProjetil;

        projeteis[i].velocidade.x = projeteis[i].velocidade.x + projeteis[i].aceleracao.x;
        projeteis[i].velocidade.y = projeteis[i].velocidade.y + projeteis[i].aceleracao.y;

        projeteis[i].posicao.x = projeteis[i].posicao.x + projeteis[i].velocidade.x;
        projeteis[i].posicao.y = projeteis[i].posicao.y + projeteis[i].velocidade.y;

        if(DistanciaEntrePontos(projeteis[i].posicao.x,
                                projeteis[i].posicao.y,
                                xPlaneta, yPlaneta) < raioProjetil + raioPlaneta*0.982)
        {
            projeteis[i].posicao.x = xProjetil;
            projeteis[i].posicao.y = yProjetil;

            projeteis[i].velocidade.x = projeteis[i].velocidade.x*CONSTANTE_RESTITUICAO;
            projeteis[i].velocidade.y = projeteis[i].velocidade.y*CONSTANTE_RESTITUICAO;

            aplicarColisao(&planeta, &projeteis[i]);
        }
    }
}

void atualizarRastro()
{
    int indiceProjetil = qtdProjeteisAtuais-1;

    rastro[qtdRastro].x = projeteis[indiceProjetil].posicao.x;
    rastro[qtdRastro].y = projeteis[indiceProjetil].posicao.y;

    if(qtdRastro < QTD_MAX_RASTRO-1)
    {
        qtdRastro = qtdRastro + 1;
    }
}

int main(int argc, char* args[])
{
    configuracoesIniciais();

    while(PIG_JogoRodando == 1)
    {
        if(TempoDecorrido(timerGeral) >= 0.01)
        {
            ReiniciarTimer(timerGeral);

            AtualizarJanela();
            verificarTeclado();
            atualizarProjeteis();
            atualizarRastro();
            atualizarCamera();

            desenhar();
        }
    }

    FinalizarJanela();

    return 0;
}



