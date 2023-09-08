
/********************************
A função AnguloEquivalente recebe um angulo qualquer e te retorna o equivalente positivo (de 0 a 360)
Exemplo: AnguloEquivalente(720) retorna 0 pois 720 graus é equivalente a 0 graus no circulo trigonometrico;
********************************/

float AnguloEquivalente(float angulo)
{
    int a = angulo/360;

    angulo = angulo - (360*a);
    if(angulo < 0)
    {
        angulo = angulo + 360.0;
    }
    return angulo;
}

/********************************
A função AnguloEntrePontos retorna o angulo entre dois pontos.
Exemplo: Se o segmento de reta que une os 2 pontos for paralelo ao eixo X
o valor retornado será 0 ou 180, dependendo da ordem dos pontos na passagem dos parametros.
********************************/

float AnguloEntrePontos(float X1, float Y1, float X2, float Y2)
{
    float Angulo;

    if(X1 == X2 && Y1 == Y2)
    {
        return 0.0;
    }
    Angulo = (((180.0*atan(((float)(Y2 - Y1)/(float)(X2 - X1))))/M_PI));

    if(X2 < X1)
    {
        Angulo = Angulo + 180.0;
    }
    return AnguloEquivalente(Angulo);
}

/********************************
A função DistanciaEntrePontos retorna a distancia entre 2 pontos
********************************/

float DistanciaEntrePontos(float X1, float Y1, float X2, float Y2)
{
    return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
}

float DistanciaEntrePontos3D(float X1, float Y1, float Z1, float X2, float Y2, float Z2)
{
    return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2) + (Z1-Z2)*(Z1-Z2));
}

/********************************
A função NumeroAleatorio retorna um numero aleatorio com os intervalos incluidos,
ou seja, os valores "Minimo" e "Maximo" também são possíveis de se obter.
********************************/

int NumeroAleatorio(int Minimo, int Maximo)
{
    Maximo = Maximo + 1;
    return (rand() % (Maximo-Minimo)) + Minimo;
}

void RodarXY(float *X, float* Y)
{
    float CamX = LARG_TELA/2.0;
    float CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(*X,*Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,*X,*Y);

    *X = CamX + D*cos(M_Radi*(A+CameraRotationXY));
    *Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));
}



float XVirtualParaReal(float X, float Y)
{
    float CamX = LARG_TELA/2.0;
    float CamY = ALT_TELA/2.0;

    float a = (CamY)*sin(M_Radi*CameraRotationZ);
    float b = sin(M_Radi*CameraRotationZ)-1;
    if(b == 0)
    {
        b = 0.0001;
    }

    Y = (-Y + a)/b;

    float D = DistanciaEntrePontos(X,Y,CamX,CamY);
    float A = AnguloEntrePontos(CamX,CamY,X,Y);

    X = CamX + D*cos(M_Radi*(A-CameraRotationXY));

    return (X-CameraPosX+(CameraZoom*((LARG_TELA/2.0)-CameraPosX)))/(CameraZoom+1);
}

float YVirtualParaReal(float X, float Y)
{
    float CamX = LARG_TELA/2.0;
    float CamY = ALT_TELA/2.0;

    float a = (CamY)*sin(M_Radi*CameraRotationZ);
    float b = sin(M_Radi*CameraRotationZ)-1;

    if(b == 0)
    {
        b = 0.0001;
    }

    Y = (-Y + a)/b;

    float D = DistanciaEntrePontos(X,Y,CamX,CamY);
    float A = AnguloEntrePontos(CamX,CamY,X,Y);

    Y = CamY + D*sin(M_Radi*(A-CameraRotationXY));

    return (Y-CameraPosY+(CameraZoom*((ALT_TELA/2.0)-CameraPosY)))/(CameraZoom+1);
}



float XRealParaVirtual(float X, float Y)
{
    X = ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
    Y = ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);

    if(CameraRotationXY == 0.0)
    {
        return X;
    }

    float CamX = LARG_TELA/2.0;
    float CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(X,Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,X,Y);

    X = CamX + D*cos(M_Radi*(A+CameraRotationXY));

    return X;

    //return ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
}

float YRealParaVirtual(float X, float Y, float Z = 0)
{
    X = ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
    Y = ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);

    if(CameraRotationXY == 0.0 && CameraRotationZ == 0.0)
    {
        return Y;
    }

    float CamX = LARG_TELA/2.0;
    float CamY = ALT_TELA/2.0;

    float D = DistanciaEntrePontos(X,Y,CamX,CamY);
    float A = AnguloEntrePontos(CamX,CamY,X,Y);

    Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));

    Y = Y - (Y-CamY-Z)*sin(M_Radi*CameraRotationZ);

    return Y;

    //return ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);
}




void XeYRealParaVirtual(float* X, float* Y)
{
    *X = XRealParaVirtual(*X,*Y);
    *Y = YRealParaVirtual(*X,*Y);

    float CamX = LARG_TELA/2.0;
    float CamY = ALT_TELA/2.0;

    float D = DistanciaEntrePontos(*X,*Y,CamX,CamY);
    float A = AnguloEntrePontos(CamX,CamY,*X,*Y);

    *X = CamX + D*cos(M_Radi*(A+CameraRotationXY));
    *Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));
}
