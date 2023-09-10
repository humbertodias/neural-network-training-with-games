
void DesenharEixosXY(float Z, PIG_Cor Cor)
{
    Z = Z*(CameraZoom+1);

    DesenharLinhaSimples(XRealParaVirtual(0,0),
                         YRealParaVirtual(0,0,Z),
                         XRealParaVirtual(LARG_TELA,0),
                         YRealParaVirtual(LARG_TELA,0,Z),
                         Cor);

    DesenharLinhaSimples(XRealParaVirtual(0,ALT_TELA),
                         YRealParaVirtual(0,ALT_TELA,Z),
                         XRealParaVirtual(LARG_TELA,ALT_TELA),
                         YRealParaVirtual(LARG_TELA,ALT_TELA,Z),
                         Cor);

    DesenharLinhaSimples(XRealParaVirtual(0,0),
                         YRealParaVirtual(0,0,Z),
                         XRealParaVirtual(0,ALT_TELA),
                         YRealParaVirtual(0,ALT_TELA,Z),
                         Cor);

    DesenharLinhaSimples(XRealParaVirtual(LARG_TELA,0),
                         YRealParaVirtual(LARG_TELA,0,Z),
                         XRealParaVirtual(LARG_TELA,ALT_TELA),
                         YRealParaVirtual(LARG_TELA,ALT_TELA,Z),
                         Cor);
}

void DesenharEixoZ(float X, float Y, PIG_Cor Cor)
{
     DesenharLinhaSimples(XRealParaVirtual(X,Y),
                         YRealParaVirtual(X,Y,0),
                         XRealParaVirtual(X,Y),
                         YRealParaVirtual(X,Y,800*(CameraZoom+1)),
                         Cor);
}

void DesenharEixoY(float X, float Z, PIG_Cor Cor)
{
    DesenharLinhaSimples(XRealParaVirtual(X,0),
                         YRealParaVirtual(X,0,Z),
                         XRealParaVirtual(X,ALT_TELA),
                         YRealParaVirtual(X,ALT_TELA,Z),
                         Cor);
}

void DesenharEixoX(float Y, float Z, PIG_Cor Cor)
{
    DesenharLinhaSimples(XRealParaVirtual(0,Y),
                         YRealParaVirtual(0,Y,Z),
                         XRealParaVirtual(LARG_TELA,Y),
                         YRealParaVirtual(LARG_TELA,Y,Z),
                         Cor);
}


void DesenharMousePos()
{
//    DesenharEixosXY(Z,VERMELHO);
//
//    DesenharEixoZ(X,0,VERMELHO);
//    DesenharEixoZ(X,ALT_TELA,VERMELHO);
//    DesenharEixoY(X,0,VERMELHO);
//    DesenharEixoY(X,800*(CameraZoom+1),VERMELHO);
//
//    DesenharEixoZ(0,Y,VERMELHO);
//    DesenharEixoZ(LARG_TELA,Y,VERMELHO);
//
//    DesenharEixoX(Y,0,VERMELHO);
//    DesenharEixoX(Y,800*(CameraZoom+1),VERMELHO);

    DesenharLinhaSimples(XRealParaVirtual(-600,Y),
                         YRealParaVirtual(-600,Y,Z*(CameraZoom+1)),
                         XRealParaVirtual(LARG_TELA+600,Y),
                         YRealParaVirtual(LARG_TELA+600,Y,Z*(CameraZoom+1)),
                         CIANO);

    DesenharLinhaSimples(XRealParaVirtual(X,-500),
                         YRealParaVirtual(X,-500,Z*(CameraZoom+1)),
                         XRealParaVirtual(X,ALT_TELA+500),
                         YRealParaVirtual(X,ALT_TELA+500,Z*(CameraZoom+1)),
                         CIANO);

    DesenharLinhaSimples(XRealParaVirtual(X,Y),
                         YRealParaVirtual(X,Y,0*(CameraZoom+1)),
                         XRealParaVirtual(X,Y),
                         YRealParaVirtual(X,Y,(800)*(CameraZoom+1)),
                         CIANO);
}

void DesenharAtomos()
{
    int i;
    double X, Y, Z;
    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;
    double D, A, Temp;

    for(i=0; i<QuantidadeDeAtomos; i++)
    {
        X = Atomos[i].PosicaoX;
        Y = Atomos[i].PosicaoY;
        Z = Atomos[i].PosicaoZ*(CameraZoom+1);

        X = ((X+CameraPosX)+((X+CameraPosX)-CamX)*CameraZoom);
        Y = ((Y+CameraPosY)+((Y+CameraPosY)-CamY)*CameraZoom);

        D = sqrt((X-CamX)*(X-CamX) + (Y-CamY)*(Y-CamY));

            double Angulo;

            Angulo = (((180.0*atan(((double)(Y - CamY)/(double)(X - CamX))))/M_PI));
            if(X < CamX)
            {
                Angulo = Angulo + 180.0;
            }
            int a = Angulo/360;
            Angulo = Angulo - (360*a);
            if(Angulo < 0)
            {
                Angulo = Angulo + 360.0;
            }
            A = Angulo;

        Temp = M_Radi*(A+CameraRotationXY);
        X = CamX + D*cos(Temp);
        Y = CamY + D*sin(Temp);
        Y = Y - (Y-CamY-Z)*sin(M_Radi*CameraRotationZ);

        AtomosSDL[i].x = X;
        AtomosSDL[i].y = ALT_TELA - Y;
    }
    DesenharPontos(AtomosSDL,QuantidadeDeAtomos,BRANCO);

    DesenharEixosXY(0,VERDE);
    DesenharEixosXY(800,VERDE);
    DesenharEixoZ(0,0,VERDE);
    DesenharEixoZ(LARG_TELA,0,VERDE);
    DesenharEixoZ(0,ALT_TELA,VERDE);
    DesenharEixoZ(LARG_TELA,ALT_TELA,VERDE);

    DesenharMousePos();
}

void Desenhar()
{
    int i,j;

    DesenharAtomos();

    if(TempoDecorrido(TimerAvisos) <= 1.5)
    {
        EscreverEsquerda(StringAvisos,50,525,0);
    }
}
