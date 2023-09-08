
/********************************
A função AnguloEquivalente recebe um angulo qualquer e te retorna o equivalente positivo (de 0 a 360)
Exemplo: AnguloEquivalente(720) retorna 0 pois 720 graus é equivalente a 0 graus no circulo trigonometrico;
********************************/

double anguloEquivalente(double angulo)
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

double anguloEntrePontos(double X1, double Y1, double X2, double Y2)
{
    double Angulo;

    if(X1 == X2 && Y1 == Y2)
    {
        return 0.0;
    }
    Angulo = (((180.0*atan(((double)(Y2 - Y1)/(double)(X2 - X1))))/M_PI));

    if(X2 < X1)
    {
        Angulo = Angulo + 180.0;
    }
    return anguloEquivalente(Angulo);
}

/********************************
A função DistanciaEntrePontos retorna a distancia 2D entre 2 pontos
********************************/

double distanciaEntrePontos(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

/********************************
A função NumeroAleatorio retorna um numero aleatorio com os intervalos incluidos,
ou seja, os valores "Minimo" e "Maximo" também são possíveis de se obter.
********************************/

int numeroAleatorio(int minimo, int maximo)
{
    maximo = maximo + 1;
    return (rand() % (maximo-minimo)) + minimo;
}

/// Detectando colisões

int retangulosColidiram(double xCentro1, double yCentro1, double largura1, double altura1,
                        double xCentro2, double yCentro2, double largura2, double altura2)
{
    double x1 = xCentro1 - largura1/2.0;
    double y1 = yCentro1 - altura1/2.0;

    double x2 = xCentro2 - largura2/2.0;
    double y2 = yCentro2 - altura2/2.0;

    if(x1 + largura1 <= x2)
    {
        return 0;
    }
    if(x1 >= x2 + largura2)
    {
        return 0;
    }
    if(y1 + altura1 <= y2)
    {
        return 0;
    }
    if(y1 >= y2 + altura2)
    {
        return 0;
    }
    return 1;
}

int circulosColidiram(double xCentro1, double yCentro1, double raio1,
                      double xCentro2, double yCentro2, double raio2)
{
    if(distanciaEntrePontos(xCentro1,yCentro1,xCentro2,yCentro2) < raio1+raio2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/// Camera

    double cameraPosX = 0;
    double cameraPosY = 0;
    double cameraZoom = 1;

void movimentarCamera(double incrementoX, double incrementoY, double incrementoZoom)
{
    cameraPosX = cameraPosX - (incrementoX/(cameraZoom));
    cameraPosY = cameraPosY - (incrementoY/(cameraZoom));

    cameraZoom = cameraZoom + incrementoZoom*(cameraZoom);
    if(cameraZoom <= 0)
    {
        cameraZoom = 0.0001;
    }
    if(cameraZoom > 75)
    {
        cameraZoom = 75;
    }
}

void atualizarCamera()
{
    double velocidadeTranslado = 10;
    double velocidadeZoom = 0.01;

    if(PIG_teclado[TECLA_w])     /// Cima
    {
        movimentarCamera(0, velocidadeTranslado, 0);
    }
    if(PIG_teclado[TECLA_s])     /// Baixo
    {
        movimentarCamera(0, -velocidadeTranslado, 0);
    }
    if(PIG_teclado[TECLA_a])     /// Esquerda
    {
        movimentarCamera(-velocidadeTranslado, 0, 0);
    }
    if(PIG_teclado[TECLA_d])     /// Direita
    {
        movimentarCamera(velocidadeTranslado, 0, 0);
    }
    if(PIG_teclado[TECLA_q])     /// Aumentar zoom
    {
        movimentarCamera(0, 0, velocidadeZoom);
    }
    if(PIG_teclado[TECLA_e])     /// Diminuir zoom
    {
        movimentarCamera(0, 0, -velocidadeZoom);
    }
}

/// Funções que convertem coordenadas e comprimentos do terreno VIRTUAL para a tela REAL

double XVirtualParaReal(double x)
{
    return ((x+cameraPosX)+((x+cameraPosX)-(LARG_TELA/2.0))*(cameraZoom-1));
}

double YVirtualParaReal(double y)
{
    return ((y+cameraPosY)+((y+cameraPosY)-(ALT_TELA/2.0))*(cameraZoom-1));
}

double tamanhoVirtualParaReal(double tamanho)
{
    return tamanho*(cameraZoom);
}

/// Funções que convertem coordenadas e comprimentos da tela REAL para o terreno virtual.

double XRealParaVirtual(double x)
{
    return (x+(LARG_TELA/2.0)*(cameraZoom-1)-(cameraPosX*cameraZoom))/(cameraZoom);
}

double YRealParaVirtual(double y)
{
    return (y+(ALT_TELA/2.0)*(cameraZoom-1)-(cameraPosY*cameraZoom))/(cameraZoom);
}

double tamanhoRealParaVirtual(double tamanho)
{
    return tamanho/(cameraZoom);
}




