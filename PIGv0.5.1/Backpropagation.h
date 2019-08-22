

void InserirAmostra(double* Entrada, double* Saida)
{
    for(int i=0; i<DINO_BRAIN_QTD_INPUT; i++)
    {
        amostras[QuantidadeAmostras].INPUT[i] = Entrada[i];
    }
    for(int i=0; i<DINO_BRAIN_QTD_OUTPUT; i++)
    {
        amostras[QuantidadeAmostras].OUTPUT[i] = Saida[i];
    }
    QuantidadeAmostras++;
}

void SalvarArquivoAmostras()
{
    char String[1000], i;
    FILE* f;

    for(i=0; i<10000; i++)
    {
        sprintf(String,"amostras\\%d",i);
        f = fopen(String,"rb");
        if(f != NULL)
        {
            fclose(f);
        }
        else
        {
            break;
        }
    }

    sprintf(String,"amostras\\%d", i);
    f = fopen(String,"wb");
    fwrite(amostras, QuantidadeAmostras, sizeof(Amostra),f);
    fclose(f);

    sprintf(String,"amostras\\%d.txt", i);
    FILE* f2 = fopen(String, "w");
    for(int i=0; i<QuantidadeAmostras; i++)
    {
        for(int j=0; j<DINO_BRAIN_QTD_INPUT; j++)
        {
            fprintf(f2, "%f ", amostras[i].INPUT[j]);
        }
        fprintf(f2, "\t");
        for(int j=0; j<DINO_BRAIN_QTD_OUTPUT; j++)
        {
            fprintf(f2, "%f ", amostras[i].OUTPUT[j]);
        }
        fprintf(f2, "\n");
    }
    fclose(f2);
}

int fsize(FILE *fp)
{
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp, prev, SEEK_SET); //go back to where we were
    return sz;
}

int CompararOutput(double* Entrada, double* output, double* outputEsperado)
{
    int Erro = 0;

    //printf("Comparando: \n");

    //printf("\t Input: \t  ");
    for(int i=0; i<DINO_BRAIN_QTD_INPUT; i++)
    {
        //printf("%f ", Entrada[i]);
    }
    //printf("\n");

    //printf("\t Output: \t  ");
    for(int i=0; i<DINO_BRAIN_QTD_OUTPUT; i++)
    {
        //printf("%f ", output[i]);

        if(fabs(output[i] - outputEsperado[i]) > 0.5)
        {
            Erro = 1;
        }
    }
    //printf("\n");

    //printf("\t Output esperado: ");
    for(int i=0; i<DINO_BRAIN_QTD_OUTPUT; i++)
    {
        //printf("%f ", outputEsperado[i]);
    }
    if(Erro == 1)
    {
        //printf("Erro!");
    }
    //printf("\n\n");



    return Erro;
}

void ImprimirPesos(RedeNeural* Rede)
{
    for(int i=0; i<Rede->QuantidadeEscondidas; i++)
    {
        printf("Camada Escondida %d:\n",i);
        for(int j=0; j<Rede->CamadaEscondida[i].QuantidadeNeuronios; j++)
        {
            printf("\tNeuronio %d:\n",j);
            for(int k=0; k<Rede->CamadaEscondida[i].Neuronios[j].QuantidadeLigacoes; k++)
            {
                printf("\t\tPeso %d = %f\n",k, Rede->CamadaEscondida[i].Neuronios[j].Peso[k]);
            }
        }
    }
    printf("Camada Saida:\n");
    for(int j=0; j<Rede->CamadaSaida.QuantidadeNeuronios; j++)
    {
        printf("\tNeuronio %d:\n",j);
        for(int k=0; k<Rede->CamadaSaida.Neuronios[j].QuantidadeLigacoes; k++)
        {
            printf("\t\tPeso %d = %f\n",k, Rede->CamadaSaida.Neuronios[j].Peso[k]);
        }
    }
}

void TreinarRede()
{
    char String[1000], i;
    FILE* f;

    for(i=0; i<10000; i++)
    {
        sprintf(String,"amostras\\%d", i);
        f = fopen(String,"rb");
        if(f != NULL)
        {
            int quantidadeErros;
            int quantidade = fsize(f)/sizeof(Amostra);
            fread(amostras, 1, fsize(f), f);
            fclose(f);

            for(int i=0; i<quantidade; i++)
            {
                amostras[i].INPUT[0] = amostras[i].INPUT[0]/1000.0;
                amostras[i].INPUT[1] = amostras[i].INPUT[1]/1500.0;
                amostras[i].INPUT[2] = amostras[i].INPUT[2]/150.0;
                amostras[i].INPUT[3] = amostras[i].INPUT[3]/10.0;
                amostras[i].INPUT[4] = amostras[i].INPUT[4]/100.0;
            }

//            for(int i=0; i<quantidade; i++)
//            {
//                for(int j=0; j<DINO_BRAIN_QTD_INPUT; j++)
//                {
//                    if(amostras[i].INPUT[j] == 0)
//                    {
//                        amostras[i].INPUT[j] = 0.01;
//                    }
//                }
//            }

            printf("Quantidade de amostras: %d\n", quantidade);

            //ImprimirPesos(Dinossauros[0].Cerebro);
            //system("pause");

            do
            {
                quantidadeErros = 0;
                for(int i=0; i<quantidade; i++)     /// ciclo completo de amostras
                {
                    int erro = 0;//RNA_BackPropagation(Dinossauros[0].Cerebro, amostras[i].INPUT, amostras[i].OUTPUT);
                    if(erro == 1)
                    {
                        quantidadeErros++;

//                        printf("%f %f %f - %f %f %f",
//                               Dinossauros[0].Cerebro->CamadaSaida.Neuronios[0].Saida,
//                               Dinossauros[0].Cerebro->CamadaSaida.Neuronios[1].Saida,
//                               Dinossauros[0].Cerebro->CamadaSaida.Neuronios[2].Saida,
//                               amostras[i].OUTPUT[0],
//                               amostras[i].OUTPUT[1],
//                               amostras[i].OUTPUT[2]);
//
//
//                        system("pause");
                    }

//                    if(i%2000 == 0)
//                    {
//                        printf("\tAmostra %d - Erros: %d\n", i, quantidadeErros);
//                    }
                }
                printf("Quantidade de erros: %d\n", quantidadeErros);

            }   while(quantidadeErros != 0);    /// enquanto houver erros no ciclo
            printf("Quantidade de erros: %d\n", quantidadeErros);

            for(int i=0; i<Dinossauros[0].TamanhoDNA; i++)
            {
                DNADaVez[0][i] = Dinossauros[0].DNA[i];
            }
        }
        else
        {
            break;
        }
    }
}

