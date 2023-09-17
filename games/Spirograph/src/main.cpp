#include "PIG.h"

#define MAX_TRAJETORIA 1000
#define MAX_PONTOS 10
#define MIN_TAMANHO_RETA 5

typedef struct ponto
{
    float XFinal, YFinal;
    float Angulo, Velocidade;
    int Direcao, Tamanho;

    int IndiceTrajetoria;
    int TotalTrajetoria;
    SDL_Point Trajetoria[MAX_TRAJETORIA];
    PIG_Cor Cor;

}   Ponto;

    Ponto Pontos[MAX_PONTOS+1];
    int QuantidadePontos = 0;

    int Fonte, SetaTextura, ApagarTela = 1, TimerGeral;
    int ExibirRetas = -1, ExibirTrajetorias = 1, ExibirUltimaTrajetoria = 1;
    int Gerador = -1, TimerGerador, ContadorGerador;

    float Periodo = 0.005;

void SalvaTela(char *String){
    // TODO
}

void CriarPonto(float X, float Y, float Angulo, float Velocidade, int Tamanho, int Direcao)
{
    Pontos[QuantidadePontos].Angulo = Angulo;
    Pontos[QuantidadePontos].Tamanho = Tamanho;
    Pontos[QuantidadePontos].XFinal = X;
    Pontos[QuantidadePontos].YFinal = Y;
    Pontos[QuantidadePontos].Direcao = Direcao;
    Pontos[QuantidadePontos].Velocidade = Velocidade;

    Pontos[QuantidadePontos].IndiceTrajetoria = 0;
    Pontos[QuantidadePontos].TotalTrajetoria = 0;
    Pontos[QuantidadePontos].Cor = ((PIG_Cor){(uint8_t)(rand()%255),(uint8_t)(rand()%255),(uint8_t)(rand()%255),255});

    QuantidadePontos = QuantidadePontos + 1;
}

void CriarPontos(int Quantidade)
{
    int i;

    int TamanhoDisponivel = 290;

    QuantidadePontos = 1;
    for(i=0; i<Quantidade; i++)
    {
        int Tamanho = rand() % TamanhoDisponivel + MIN_TAMANHO_RETA;

        CriarPonto(700,300, 0, rand()%20+1, Tamanho, rand()%2);
        TamanhoDisponivel = TamanhoDisponivel - Tamanho;

        if(TamanhoDisponivel < 5)
        {
            return;
        }
    }
}

void PreencherTrajetoria(Ponto* Lista, float X, float Y)
{
    Lista->Trajetoria[Lista->IndiceTrajetoria].x = X;
    Lista->Trajetoria[Lista->IndiceTrajetoria].y = ALT_TELA - Y;

    if(Lista->TotalTrajetoria < MAX_TRAJETORIA)
    {
        Lista->TotalTrajetoria = Lista->TotalTrajetoria + 1;
    }

    Lista->IndiceTrajetoria = Lista->IndiceTrajetoria + 1;
    if(Lista->IndiceTrajetoria == MAX_TRAJETORIA)
    {
        Lista->IndiceTrajetoria = 0;
    }
}

void VerificarTeclaApertada()
{
    switch(PegarTecla())
    {
        case 1:
        {
            Periodo = Periodo/2.0;
        }   break;
        case 2:
        {
            Periodo = Periodo*2.0;
        }   break;
        case 5:
        {
            ApagarTela = -ApagarTela;
        }   break;
        case 6:
        {
            CriarPontos((rand() % MAX_PONTOS)+1);
            DesenharRetangulo(1,1,600,400,PRETO);
        }   break;
        case 7:
        {
            ExibirRetas = -ExibirRetas;
        }   break;
        case 8:
        {
            ExibirTrajetorias = -ExibirTrajetorias;
        }   break;
        case 9:
        {
            ExibirUltimaTrajetoria = -ExibirUltimaTrajetoria;
        }   break;
        case 12:
        {
            Gerador = -Gerador;
            ContadorGerador = 0;
            if(Gerador == 1)
            {
                Periodo = 0.0;
                TimerGerador = CriarTimer();
            }
            else
            {
                DestruirTimer(TimerGerador);
                Periodo = 0.005;
            }
        }   break;
        case 13:
        {
            char String[200];
            int i;

            sprintf(String,"prints/%d_%s.bmp", rand()%1000+1, __TIME__);
            for(i=0; String[i] != '\0'; i++)
            {
                if(String[i] == ' ' || String[i] == ':')
                {
                    String[i] = '_';
                }
            }
            SalvaTela(String);
        }   break;
    }
}


void Desenhar()
{
    int i,j,k,Y;
    char String[200];

    if(ApagarTela == 1)
    {
        IniciarDesenho();
    }

    sprintf(String,"Points amount:");
    EscreverEsquerda(String, 40, 550, 1);
    sprintf(String,"%d", QuantidadePontos-1);
    EscreverEsquerda(String, 180, 550, 2);

    EscreverEsquerda("| Speed | Lenght | Direction |", 150, 480, 1);

    DesenharSprite(SetaTextura,195,450,19,30,0);
    DesenharSprite(SetaTextura,270,450,19,30,0);
    DesenharSprite(SetaTextura,355,450,19,30,0);

    Y = 400;
    for(i=1; i<QuantidadePontos; i++)
    {
        sprintf(String,"Point %d        |            |            |              |", i);
        EscreverEsquerda(String, 40, Y, 1);

        sprintf(String,"%.0f",Pontos[i].Velocidade);
        EscreverCentralizada(String,190,Y,2);

        sprintf(String,"%d",Pontos[i].Tamanho);
        EscreverCentralizada(String,270,Y,2);

        if(Pontos[i].Direcao == 1)
        {
            sprintf(String,"Positive");
        }
        else
        {
            sprintf(String,"Negative");
        }
        EscreverCentralizada(String,355,Y,2);

        Y = Y - 30;
    }


    for(i=1; i<QuantidadePontos; i++)
    {
        SDL_Point P[MAX_TRAJETORIA];
        for(j=0; j<Pontos[i].TotalTrajetoria; j++)
        {
            k = ((j+Pontos[i].IndiceTrajetoria)%Pontos[i].TotalTrajetoria);
            P[j].x = Pontos[i].Trajetoria[k].x;
            P[j].y = Pontos[i].Trajetoria[k].y;
        }

        if(ExibirTrajetorias == 1)
        {
            if(ExibirUltimaTrajetoria == 1)
            {
                if(i == QuantidadePontos-1)
                {
                    DesenharLinhas(P,Pontos[i].TotalTrajetoria,Pontos[i].Cor);
                }
            }
            else
            {
                DesenharLinhas(P,Pontos[i].TotalTrajetoria,Pontos[i].Cor);
            }
        }

        if(ExibirRetas == 1)
        {
            DesenharLinhaSimples(Pontos[i].XFinal, Pontos[i].YFinal, Pontos[i-1].XFinal, Pontos[i-1].YFinal, Pontos[i].Cor);
        }
    }

    EncerrarDesenho();
}

void Mover()
{
    int i;

    for(i=1; i<QuantidadePontos; i++)
    {
        float Angulo = Pontos[i].Angulo;
        float Tamanho = Pontos[i].Tamanho;
        float Adjacente = (cos(Angulo*M_Radi)*Tamanho);
        float Oposto = (sin(Angulo*M_Radi)*Tamanho);

        Pontos[i].XFinal = Pontos[i-1].XFinal + Adjacente;
        Pontos[i].YFinal = Pontos[i-1].YFinal + Oposto;

        if(Pontos[i].Direcao == 1)
        {
            Pontos[i].Angulo = Pontos[i].Angulo + Pontos[i].Velocidade;
        }
        else
        {
            Pontos[i].Angulo = Pontos[i].Angulo - Pontos[i].Velocidade;
        }

        PreencherTrajetoria(&Pontos[i], Pontos[i].XFinal, Pontos[i].YFinal);
    }
}

void ConfiguracoesIniciais()
{
//    CriarJogo("Spirograph",0);
    CriarJanela("Spirograph",0);

    TimerGeral = CriarTimer();
    SetaTextura = CriarSprite("imagens/Vetor.bmp");
    Fonte = CriarFonteNormal("fontes/arial.ttf",20,BRANCO,0,BRANCO,0);
    Fonte = CriarFonteNormal("fontes/arial.ttf",20,VERDE,0,BRANCO,0);

    CriarPonto(700,300,0,0,0,0);
    CriarPontos((rand() % MAX_PONTOS)+1);
}

void ControlarGerador()
{
    if(TempoDecorrido(TimerGerador) > 1.0)
    {
        char String[100];

        ReiniciarTimer(TimerGerador);
        sprintf(String,"prints/%d.bmp",ContadorGerador);
        SalvaTela(String);
        ContadorGerador = ContadorGerador + 1;
        CriarPontos((rand() % MAX_PONTOS)+1);
        DesenharRetangulo(1,1,600,400,PRETO);
    }
}

int main(int argc, char* args[])
{
    ConfiguracoesIniciais();

    while(PIG_JogoRodando == 1)
    {
        //AtualizarEstadoJogo();
        AtualizarJanela();
        if(TempoDecorrido(TimerGeral) >= Periodo)
        {
            Mover();
            ReiniciarTimer(TimerGeral);
        }
        if(Gerador == 1)
        {
            ControlarGerador();
        }
        VerificarTeclaApertada();
        Desenhar();
    }
//    FinalizarJogo();
    FinalizarJanela();
    return 0;
}
