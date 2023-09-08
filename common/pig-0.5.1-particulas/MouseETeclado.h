
void VerificarBotaoClicado()
{
    static int Controle = 0;
    static int Controle2 = 0;

    if(PIG_evento.mouse.botao == 1 && PIG_evento.mouse.acao == 1025)
    {
        AplicarForca(1);
        Controle = 1;
    }
    if(PIG_evento.mouse.botao == 1 && PIG_evento.mouse.acao == 1024 && Controle == 1)
    {
        AplicarForca(1);
    }
    if(PIG_evento.mouse.botao == 1 && PIG_evento.mouse.acao == 1026)
    {
        Controle = 0;
    }

    if(PIG_evento.mouse.botao == 3 && PIG_evento.mouse.acao == 1025)
    {
        AplicarForca(2);
        Controle2 = 1;
    }
    if(PIG_evento.mouse.botao == 3 && PIG_evento.mouse.acao == 1024 && Controle2 == 1)
    {
        AplicarForca(2);
    }
    if(PIG_evento.mouse.botao == 3 && PIG_evento.mouse.acao == 1026)
    {
        Controle2 = 0;
    }
}

void VerificarTeclaApertada()
{
    switch(PegarTecla())
    {
        case 1:
        {
            Periodo = Periodo/2.0;
            ReiniciarTimer(TimerAvisos);
            sprintf(StringAvisos,"Intervalo entre iterações: %.5f",Periodo);
        }   break;
        case 2:
        {
            Periodo = Periodo*2.0;
            ReiniciarTimer(TimerAvisos);
            sprintf(StringAvisos,"Intervalo entre iterações: %.5f",Periodo);
        }   break;

        case 3:
        {
            Distribuicao = Distribuicao - 1;
        }   break;
        case 4:
        {
            Distribuicao = Distribuicao + 1;
        }   break;

        case 5:
        {

        }   break;

        case 6:
        {
            QuantidadeDeAtomos = 0;

            int i,j,k;

            for(i=0;i<Distribuicao;i++)
            {
                for(j=0;j<Distribuicao;j++)
                {
                    for(k=0;k<Distribuicao;k++)
                    {
                        InserirParticula(MASSA_PARTICULA, rand()%LARG_TELA, rand()%ALT_TELA, rand()%800, 0, 0, 0);
                        //InserirParticula(MASSA_PARTICULA, i*(1200/Distribuicao), j*(600/Distribuicao), k*(800/Distribuicao), 0, 0, 0);
                    }
                }
            }

            ReiniciarTimer(TimerAvisos);
            sprintf(StringAvisos,"%d partículas adicionadas.",Distribuicao*Distribuicao*Distribuicao);

        }   break;

        case 7:
        {
            GravidadeAtivada = GravidadeAtivada*(-1);
        }   break;

        case 8:
        {
            MovimentoEsferas = MovimentoEsferas*(-1);
        }   break;

        case 14:
        {
            Giro = -1;
            MouseX = 600;
            MouseY = 300;
            MouseZ = 400;
        }   break;
        case 15:
        {
            Giro = 1;
        }   break;
        case 16:
        {
            MouseX = 0;
            Giro = 2;
        }   break;
        case 17:
        {

        }   break;
        case 18:
        {

        }   break;
    }

    if(PIG_meuTeclado[TECLA_F6])
    {
        MouseX = MouseX + 1;
    }
    if(PIG_meuTeclado[TECLA_6])
    {
        MouseX = MouseX - 1;
    }
    if(PIG_meuTeclado[TECLA_F7])
    {
        MouseY = MouseY + 1;
    }
    if(PIG_meuTeclado[TECLA_7])
    {
        MouseY = MouseY - 1;
    }
    if(PIG_meuTeclado[TECLA_F8])
    {
        MouseZ = MouseZ + 1;
    }
    if(PIG_meuTeclado[TECLA_8])
    {
        MouseZ = MouseZ - 1;
    }
}
