



double DistanciaHorizonalProximoObstaculo(double X)
{
    int indice = ProcurarProximoObstaculo(X);

    return (canoSuperior[indice].X + (SpriteCano.Largura/2.0)) - X;
}

double DistanciaVerticalProximoObstaculo(double X, double Y)
{
    int indice = ProcurarProximoObstaculo(X);

    return (((canoInferior[indice].Y + SpriteCano.Altura) + canoSuperior[indice].Y)/2.0) - Y;
}

double VelocidadeProximoObstaculo(double X)
{
    int indice = ProcurarProximoObstaculo(X);

    return canoSuperior[indice].Vy;
}

double AlturaProximoObstaculo(double X)
{
    int indice = ProcurarProximoObstaculo(X);

    return ((canoInferior[indice].Y + SpriteCano.Altura) + canoSuperior[indice].Y)/2.0;
}

double AberturaProximoObstaculo(double X)
{
    int indice = ProcurarProximoObstaculo(X);

    return canoSuperior[indice].Y - (canoInferior[indice].Y + SpriteCano.Altura);
}



//double LarguraProximoObstaculo(double X)
//{
//    int indice = ProcurarProximoObstaculo(X);
//    double Largura = obstaculo[indice].sprite[obstaculo[indice].FrameAtual]->Largura;
//
//    return Largura;
//}

//double ComprimentoProximoObstaculo(double X)
//{
//    int indice = ProcurarProximoObstaculo(X);
//    double Altura = obstaculo[indice].sprite[obstaculo[indice].FrameAtual]->Altura;
//
//    return Altura;
//}


//double AlturaComComprimentoProximoObstaculo(double X)
//{
//    int indice = ProcurarProximoObstaculo(X);
//    double Comprimento = obstaculo[indice].sprite[obstaculo[indice].FrameAtual]->Altura;
//
//    return (obstaculo[indice].Y + Comprimento);
//}
