#include "PIG.h"

#define ConstanteUniversal 100
#define RAIO_PARTICULA 3
#define MASSA_PARTICULA 5

#define RAIO_GIRO           700
#define VELOCIDADE_GIRO     (0.1)
#define DISTRIBUICAO        37
#define FORCA_GIRO          100

#include "Tipos.h"
#include "Variaveis.h"
#include "Desenhar.h"
#include "AjustesEAtualizacoes.h"

void InserirParticula(float Massa, float Px, float Py, float Pz, float Vx, float Vy, float Vz)
{
    Atomos[QuantidadeDeAtomos].Massa = Massa;
    Atomos[QuantidadeDeAtomos].ControleDeColisao = 0;
    Atomos[QuantidadeDeAtomos].Raio = RAIO_PARTICULA;

    Atomos[QuantidadeDeAtomos].ForcaX = 0;
    Atomos[QuantidadeDeAtomos].ForcaY = 0;
    Atomos[QuantidadeDeAtomos].ForcaZ = 0;

    Atomos[QuantidadeDeAtomos].AceleracaoX = 0;
    Atomos[QuantidadeDeAtomos].AceleracaoY = 0;
    Atomos[QuantidadeDeAtomos].AceleracaoZ = 0;

    Atomos[QuantidadeDeAtomos].VelocidadeX = Vx;
    Atomos[QuantidadeDeAtomos].VelocidadeY = Vy;
    Atomos[QuantidadeDeAtomos].VelocidadeZ = Vz;

    Atomos[QuantidadeDeAtomos].PosicaoX = Px;
    Atomos[QuantidadeDeAtomos].PosicaoY = Py;
    Atomos[QuantidadeDeAtomos].PosicaoZ = Pz;

    QuantidadeDeAtomos = QuantidadeDeAtomos + 1;
}

void AplicarForca(int Tipo)
{
    int i, j;

    float Distancia, F;
    float cos, sen, zin;

    for(i=0; i<QuantidadeDeAtomos; i++)
    {
        //Distancia = DistanciaEntrePontos3D(Atomos[i].PosicaoX, Atomos[i].PosicaoY, Atomos[i].PosicaoZ, X, Y, Z);
        Distancia = sqrt((Atomos[i].PosicaoX-X)*(Atomos[i].PosicaoX-X) +
                         (Atomos[i].PosicaoY-Y)*(Atomos[i].PosicaoY-Y) +
                         (Atomos[i].PosicaoZ-Z)*(Atomos[i].PosicaoZ-Z));

        if(Distancia < 50)
        {
            Distancia = 50;
        }

        if(Tipo == 1)
        {
            F = ConstanteUniversal*((Atomos[i].Massa*Atomos[i].Massa)/(Distancia));
        }
        else
        {
            F = FORCA_GIRO;//ConstanteUniversal*((Atomos[i].Massa)/(Distancia*Distancia));
        }

        cos = ((X - Atomos[i].PosicaoX)/(Distancia));
        sen = ((Y - Atomos[i].PosicaoY)/(Distancia));
        zin = ((Z - Atomos[i].PosicaoZ)/(Distancia));

        Atomos[i].ForcaX = Atomos[i].ForcaX + F*cos;
        Atomos[i].ForcaY = Atomos[i].ForcaY + F*sen;
        Atomos[i].ForcaZ = Atomos[i].ForcaZ + F*zin;
    }
}

#include "MouseETeclado.h"

void CalcularGravidade()
{
    int i, j;

    float Distancia, F;
    float cos, sen, zin;

    for(i=0; i<QuantidadeDeAtomos; i++)
    {
        for(j=i; j<QuantidadeDeAtomos; j++)
        {
            Distancia = DistanciaEntrePontos3D(Atomos[i].PosicaoX, Atomos[i].PosicaoY, Atomos[i].PosicaoZ, Atomos[j].PosicaoX, Atomos[j].PosicaoY, Atomos[j].PosicaoZ);
            if(Distancia < 50)
            {
                Distancia = 50;
            }

            F = ConstanteUniversal*((Atomos[i].Massa*Atomos[j].Massa)/(Distancia*Distancia));

            cos = ((Atomos[j].PosicaoX - Atomos[i].PosicaoX)/(Distancia));
            sen = ((Atomos[j].PosicaoY - Atomos[i].PosicaoY)/(Distancia));
            zin = ((Atomos[j].PosicaoZ - Atomos[i].PosicaoZ)/(Distancia));

            Atomos[i].ForcaX = Atomos[i].ForcaX + F*cos;
            Atomos[i].ForcaY = Atomos[i].ForcaY + F*sen;
            Atomos[i].ForcaZ = Atomos[i].ForcaZ + F*zin;

            Atomos[j].ForcaX = Atomos[j].ForcaX + F*(-cos);
            Atomos[j].ForcaY = Atomos[j].ForcaY + F*(-sen);
            Atomos[j].ForcaZ = Atomos[j].ForcaZ + F*(-zin);
        }
    }

}

void MoverAtomos()
{
    int i, j;
    float X, Y, Z;

    for(i=0;i<QuantidadeDeAtomos;i++)
    {
        AtualizarAceleracao(&Atomos[i]);
        AtualizarVelocidade(&Atomos[i]);

        X = Atomos[i].PosicaoX + Atomos[i].VelocidadeX;
        Y = Atomos[i].PosicaoY + Atomos[i].VelocidadeY;
        Z = Atomos[i].PosicaoZ + Atomos[i].VelocidadeZ;

        if(X >= 1200 || X <= 0)
        {
            //Atomos[i].VelocidadeX = Atomos[i].VelocidadeX*(-1);
        }
        if(Y >= 600 || Y <= 0)
        {
            //Atomos[i].VelocidadeY = Atomos[i].VelocidadeY*(-1);
        }
        if(Z >= 800 || Z <= 0)
        {
            //Atomos[i].VelocidadeZ = Atomos[i].VelocidadeZ*(-1);
        }

        Atomos[i].PosicaoX = X;
        Atomos[i].PosicaoY = Y;
        Atomos[i].PosicaoZ = Z;
    }
}

void ConfiguracoesIniciais()
{
    CriarJanela("Particulas Gravitaçao 3D",0);
    MouseX = 600;
    MouseY = 300;

    TimerGeral = CriarTimer();
    TimerAvisos = CriarTimer();
}

void MovimentarCamera()
{
    static int CameraRotationControl = 0;
    static int CameraRotationIncrement = 0;
    float dx = CameraPosX, dy = CameraPosY, dz = CameraZoom, dw = CameraRotationXY, dt = CameraRotationZ;

    float A = 1.0/(CameraZoom+1);
    if(PIG_meuTeclado[TECLA_w] == 1)
    {
        CameraPosY = CameraPosY - cos(M_Radi*CameraRotationXY)*A;
        CameraPosX = CameraPosX - sin(M_Radi*CameraRotationXY)*A;
    }
    if(PIG_meuTeclado[TECLA_s] == 1)
    {
        CameraPosY = CameraPosY + cos(M_Radi*CameraRotationXY)*A;
        CameraPosX = CameraPosX + sin(M_Radi*CameraRotationXY)*A;
    }
    if(PIG_meuTeclado[TECLA_a] == 1)
    {
        CameraPosY = CameraPosY - sin(M_Radi*CameraRotationXY)*A;
        CameraPosX = CameraPosX + cos(M_Radi*CameraRotationXY)*A;
    }
    if(PIG_meuTeclado[TECLA_d] == 1)
    {
        CameraPosY = CameraPosY + sin(M_Radi*CameraRotationXY)*A;
        CameraPosX = CameraPosX - cos(M_Radi*CameraRotationXY)*A;
    }


    if(PIG_meuTeclado[TECLA_g] == 1)
    {
        if(CameraRotationXY == 0.0 ||
           CameraRotationXY == 90.0 || CameraRotationXY == -90.0 ||
           CameraRotationXY == 180.0 || CameraRotationXY == -180.0 ||
           CameraRotationXY == 270.0 || CameraRotationXY == -270.0
           )
        {
            if(CameraRotationControl <= 100)
            {
                CameraRotationControl = CameraRotationControl + 1;
            }
            else
            {
                CameraRotationControl = 0;
                CameraRotationIncrement = CameraRotationIncrement + 2;
            }
        }
        else
        {
            CameraRotationIncrement = CameraRotationIncrement + 2;
        }

        CameraRotationXY = CameraRotationIncrement/10.0;
    }
    if(PIG_meuTeclado[TECLA_j] == 1)
    {
        if(CameraRotationXY == 0.0 ||
           CameraRotationXY == 90.0 || CameraRotationXY == -90.0 ||
           CameraRotationXY == 180.0 || CameraRotationXY == -180.0 ||
           CameraRotationXY == 270.0 || CameraRotationXY == -270.0
           )
        {
            if(CameraRotationControl <= 100)
            {
                CameraRotationControl = CameraRotationControl + 1;
            }
            else
            {
                CameraRotationControl = 0;
                CameraRotationIncrement = CameraRotationIncrement - 2;
            }
        }
        else
        {
            CameraRotationIncrement = CameraRotationIncrement - 2;
        }

        CameraRotationXY = CameraRotationIncrement/10.0;
    }


    if(PIG_meuTeclado[TECLA_y] == 1 && CameraRotationZ > 0.1)
    {
        CameraRotationZ = CameraRotationZ - 0.2;
    }
    if(PIG_meuTeclado[TECLA_h] == 1 && CameraRotationZ < 89.9)
    {
        CameraRotationZ = CameraRotationZ + 0.2;
    }


    if(PIG_meuTeclado[TECLA_q] == 1)
    {
        if(CameraZoom >= 0)
        {
            CameraZoom = CameraZoom + 0.005;
        }
        else
        {
            CameraZoom = CameraZoom + (0.005/(1.0/(CameraZoom+1)));
        }

        if(CameraZoom >= 10)
        {
            CameraZoom = 10;
        }
    }
    if(PIG_meuTeclado[TECLA_e] == 1)
    {
        if(CameraZoom >= 0)
        {
            CameraZoom = CameraZoom - 0.005;
        }
        else
        {
            CameraZoom = CameraZoom - (0.005/(1.0/(CameraZoom+1)));
        }

        if(CameraZoom <= -0.9999)
        {
            CameraZoom = -0.9999;
        }
    }

    if(CameraPosX != dx || CameraPosY != dy || CameraZoom != dz || CameraRotationXY != dw || CameraRotationZ != dt)
    {
        CameraRotationXY = AnguloEquivalente(CameraRotationXY);
        if(CameraRotationIncrement >= 3600)
        {
            CameraRotationIncrement = CameraRotationIncrement - 3600;
        }
        if(CameraRotationIncrement <= -3600)
        {
            CameraRotationIncrement = CameraRotationIncrement + 3600;
        }
    }
}

void AplicarGiro()
{
    static double A = 0;
    static int Inc = 10;
    if(Giro == 1)
    {
        MouseX = 600.0 + RAIO_GIRO*cos(A);
        MouseY = 300.0 + RAIO_GIRO*sin(A);
        A = A + VELOCIDADE_GIRO;
    }

    if(Giro == 2)
    {
        MouseX = MouseX + Inc;
        MouseY = 300*sin(M_Radi*MouseX)+300;
        if(MouseX > 1200 || MouseX < 0)
        {
            Inc = -Inc;
        }
    }
}

int main(int argc, char* args[])
{
    ConfiguracoesIniciais();

    while(PIG_JogoRodando == 1)
    {
        AtualizarJanela();

        X = MouseX;
        Y = MouseY;
        Z = MouseZ;

        IniciarDesenho();
        {
            if(TempoDecorrido(TimerGeral) >= Periodo)
            {
                if(MovimentoEsferas == 1)
                {
                    if(GravidadeAtivada == 1)
                    {
                        CalcularGravidade();
                    }
                    MoverAtomos();
                }
                ReiniciarTimer(TimerGeral);
                AplicarGiro();
            }
            VerificarBotaoClicado();
            VerificarTeclaApertada();
            MovimentarCamera();
            Desenhar();

        }
        EncerrarDesenho();
    }

    FinalizarJanela();

    return 0;
}
