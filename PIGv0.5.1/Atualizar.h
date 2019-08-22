
void AtualizarGraficoNeural()
{
///    maior distancia horizontal = 1110
///    menor distancia horizontal = -75

///    maior distanci vertical = 693
///    menor distancia vertical -693

    double* Pesos = (double*)malloc(RNA_QuantidadePesos(MelhorPassaro->Cerebro)*sizeof(double));
    RNA_CopiarCamadasParaVetor(MelhorPassaro->Cerebro, Pesos);

    RedeNeural* Temp = RNA_CriarRedeNeural(BIRD_BRAIN_QTD_LAYERS,
                                           BIRD_BRAIN_QTD_INPUT,
                                           BIRD_BRAIN_QTD_HIDE,
                                           BIRD_BRAIN_QTD_OUTPUT);

    RNA_CopiarVetorParaCamadas(Temp, Pesos);

    free(Pesos);

    //if(DesenharTela == 1)
    {
        double Entrada[2];
        double Saida;

        for(int i=-75; i<1110; i++)
        {
            for(int j=-693; j<693; j++)
            {
                int indice1 = (i+75)/TAXA_GRAFICO_NEURAL;
                int indice2 = (j+693)/TAXA_GRAFICO_NEURAL;
                EspacoTempo[indice1][indice2].X = i + LARG_TELA/2.0;
                EspacoTempo[indice1][indice2].Y = j + ALT_TELA/2.0;

                Entrada[0] = i;
                Entrada[1] = j;

                RNA_CopiarParaEntrada(Temp, Entrada);
                RNA_CalcularSaida(Temp);
                RNA_CopiarDaSaida(Temp, &Saida);

                if(Saida >= 0.5)
                {
                    Saida = 100;
                }
                else
                {
                    Saida = 0;
                }

                EspacoTempo[indice1][indice2].Z = Saida;
            }
        }
    }

    RNA_DestruirRedeNeural(Temp);
}


Passaros* getMelhorPassaro()
{
    double Maior = 0;
    int Indice = 0;

    for(int i=0; i<POPULACAO_TAMANHO; i++)
    {
        if(Passaro[i].Estado != 3 && Passaro[i].X > Maior)
        {
            Maior = Passaro[i].X;
            Indice = i;
        }
    }
    return &Passaro[Indice];
}


void AtualizarMelhorPassaro()
{
    if(MODO_JOGO == TESTE)
    {
        MelhorPassaro = &Passaro[0];
    }

    if(MODO_JOGO == DUELO)
    {
        MelhorPassaro = &Passaro[1];
    }

    if(MODO_JOGO == EVOLUCAO)
    {
        if(MelhorPassaro->Estado == 3)
        {
            MelhorPassaro = getMelhorPassaro();
            //AtualizarGraficoNeural();
        }
    }
}

void AtualizarAnguloPassaro()
{
//    se velocidade = 3.5, angulo = 45
//    se velocidade = 0, angulo = 0
//    se velocidade = -3,5 angulo = -45;
//
//
//    Y = 90x/7
//
//   Angulo = 90*Velocidade/7;
//
//
//    double Decremento = 0.8;

//    for(int i=0; i<QuantidadePassaros; i++)
//    {
//        if(Passaro[i].Angulo > -70.0)
//        {
//            Passaro[i].Angulo = Passaro[i].VelocidadeY*90.0/7.0;
//        }
//    }


    double Decremento = 0.8;

    for(int i=0; i<QuantidadePassaros; i++)
    {
        if(Passaro[i].Estado != 3 && Passaro[i].Estado != 2)
        {
            if(Passaro[i].Angulo - Decremento > -75.0)
            {
                Passaro[i].Angulo = Passaro[i].Angulo - Decremento;
            }
        }
    }
}

void AtualizarFramePassaro()
{
    for(int i=0; i<QuantidadePassaros; i++)
    {
        if(Passaro[i].Estado != 3)
        {
            if(TempoDecorrido(Passaro[i].TimerFrame) >= 0.1)
            {
                Passaro[i].SpriteAtual = (Passaro[i].SpriteAtual + 1)%3;

                ReiniciarTimer(Passaro[i].TimerFrame);
            }
            if(Passaro[i].Estado == 2)
            {
                Passaro[i].SpriteAtual = 1;
            }
        }
    }
}

