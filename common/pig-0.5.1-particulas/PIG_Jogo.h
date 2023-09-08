/********************************
A fun��o DefineFundo() permite escolher um arquivo de imagem como fundo (background) do jogo que ser� automaticamente desenhado a cada nova etapa de desenho na tela.
Par�metros:
nome_ArquivoImagem (entrada, passagem por refer�ncia*): indica o caminho relativo ou absoluto do arquivo de imagem que ser� utilizado como fundo do jogo.
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void DefinirFundo(char *nome_ArquivoImagem)
{
    jogo->DefineFundo(nome_ArquivoImagem);
}

/********************************
A fun��o GetTeclado() faz um mapeamento entre o teclado f�sico a uma vari�vel do tipo PIG_Teclado que funciona como um vetor de vari�veis l�gicas,
sendo cada posi��o do vetor relativo a uma tecla f�sica.
Uma lista das poss�veis teclas e seus c�digo pode ser vista no arquivo Tipos_PIG.h.
Retorno:
O valor de retorno da fun��o � um vetor de n�meros inteiros que indicam se uma determinada tecla (�ndice do vetor) foi
pressionada (valor diferente de 0,zero) ou n�o (valor igual a zero).
********************************/
PIG_Teclado PegarTeclado()
{
    return jogo->PegaTeclado();
}

/********************************
A fun��o CriaJogo() � respons�vel pela cria��o da janela do jogo e pelos componentes audio-visuais.
Ela deve ser chamada antes de qualquer outra fun��o da biblioetac PIG.h. N�o � poss�vel criar dois
jogos no mesmo progama. Logo, somente a primeira chamada ter� efeito.
Par�metros:
nome_Janela (entrada, passagem por refer�ncia*): indica o nome que a janela do jogo mostrar� no seu t�tulo.
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
cursor_Proprio (entrada, passagem por valor): indica se o jogo utilizar� cursores (ponteiros) pr�prios para o mouse ou utilizar� o cursor padr�o.
********************************/
void CriarJogo(char *nome_Janela,int cursor_Proprio=0)
{
    if (jogo==NULL){
        jogo = new CJogo(nome_Janela,cursor_Proprio);
        CAssetLoader::Inicia();
        if (cursor_Proprio!=0)
            CMouse::Inicia(jogo->renderer);
        CGerenciadorTimers::Inicia();
        CGerenciadorObjetos::Inicia(jogo->renderer);
        CGerenciadorParticulas::Inicia(jogo->renderer);
        CGerenciadorAnimacoes::Inicia(jogo->renderer);
        PIG_meuTeclado = PegarTeclado();
        PIG_JogoRodando = 1;
        srand(time(NULL));
    }
}

void CriarJanela(char *nome_Janela,int cursor_Proprio=0){
    CriarJogo(nome_Janela,cursor_Proprio);
}


/********************************
A fun��o GetEvento() indica se houve algum tipo de evento desde a �ltima vez que a fun��o foi chamada.
Um evento pode ser uma tecla pressionada, um clique do mouse ou outra coisa relacionada � tela do jogo.
Maiores informa��e podem ser vistas no arquivo Tipo_PIG.h
Retorno:
O valor de retorno � um struct contendo o tipo de evento ocorrido e v�rios outros structs com informa��es espec�ficas.
********************************/
PIG_Evento PegarEvento()
{
    return jogo->PegaEvento();
}

/********************************
A fun��o IniciaDesenho() � respons�vel por preparar a janela do jogo para que os objetos gr�ficos
possam ser mostrados, al�m de desenhar a imagem de fundo do jogo, caso tenha sido definida.
Deve ser chamada repetidamente a cada novo quadro (frame) a ser desenhado.
********************************/
void IniciarDesenho()
{
    jogo->IniciaDesenho();
}

/********************************
A fun��o EncerraDesenho() � respons�vel por encerrar o desenho que foi criado, mostrando na tela do jogo.
Deve ser chamado sempre ao final do loop principal do jogo.
********************************/
void EncerrarDesenho()
{
    if (jogo->cursorPadrao!=0)
        CMouse::Desenha();
    jogo->EncerraDesenho();
}

/********************************
A fun��o AtualizarEstadoJogo() � repons�vel por retornar se o jogo ainda est� ativo ou n�o.
O jogo ser� encerrado se a janela do jogo for fechada, por exemplo.
Retorno:
inteiro que indica se o jogo ainda est� sendo executado (valor diferente de zero) ou n�o (valor igual a 0, zero).
********************************/

int AtualizarEstadoJogo()
{
    PIG_evento = PegarEvento();
    if(PIG_JogoRodando != 0)
    {
        PIG_JogoRodando = jogo->GetRodando();
    }
}

void AtualizarJanela(){
    AtualizarEstadoJogo();
}

/********************************
A fun��o Espera() "congela" a tela do jogo por alguns milisegundos, impedindo que qualquer outro comando seja executado enquanto isso.
Par�metros:
tempo (entrada, passagem por valor): indica a quantidade de milisegundos durante a qual o jogo ser� pausado.
********************************/
void Esperar(int tempo)
{
    SDL_Delay(tempo);
}

/********************************
A fun��o FinalizaJogo() � respons�vel por encerrar com a PIG. Ap�s tudo o jogo ser executado
a fun��o deve ser chamada e ela ir� realizar a libera��o de mem�ria dos elementos criados pela PIG.
********************************/
void FinalizarJogo()
{
    CGerenciadorAnimacoes::Encerra();
    CGerenciadorParticulas::Encerra();
    CGerenciadorObjetos::Encerra();
    CGerenciadorTimers::Encerra();
    if (jogo->cursorPadrao==0)
        CMouse::Encerra();
    CAssetLoader::Encerra();
    delete jogo;
}

void FinalizarJanela(){
    FinalizarJogo();
}


/********************************
A fun��o GetFPS() � respons�vel por calcular o valor do Frames Per Seconds (FPS), que representa a quantidade de
frames (quadros) desenhados por segundo pela PIG.
Retorno:
float que indica a m�dia de quadros desenhados por segundo.
********************************/
float PegarFPS()
{
    return jogo->GetFPS();
}

/********************************
A fun��o CarregaCursor() � respons�vel por armazenar um novo cursor para o mouse, dado pelo arquivo de imagem indicado.
O arquivo deve ser uma imagem com 32 pixels de altura orbigatoriamente.
Par�metro:
indice (entrada, passagem por valor): informa um �ndice para este novo cursor. Se o �ndice j� estiver sendo utilizado,
o cursor antigo � removido. O valor deve estar entre 0..MAX_CURSORES-1.
nomeArquivoCursor (entrada, passagem por refer�ncia*): indica o nome do arquivo de imagem que ser� utilziado como cursor do mouse.
� utilizado o operador * apenas por se tratar de um par�metro string. O valor do par�metro n�o � alterado dentro da fun��o.
********************************/
void CarregarCursor(int indice,char *nomeArquivoCursor)
{
    CMouse::CarregaCursor(indice,nomeArquivoCursor);
}

/********************************
A fun��o MudaCursor() � respons�vel por alterar o cursor atual do mouse por outro j� carregado.
Par�metro:
indice (entrada, passagem por valor): informa um �ndice para este novo cursor que j� deve ter sido
carregado anteriormente e deve estar no intervalo 0..MAX_CURSORES-1.
********************************/
void MudarCursor(int indice)
{
    CMouse::MudaCursor(indice);
}

/********************************
A fun��o PegarTecla reconhece a tecla apertada ou soltada(cima,baixo,esquerda,direita,enter,esc,z,x) e retorna um codigo.

Apertar = Positivo
Soltar = Negativo

Baixo       = 1
Cima        = 2
Esquerda    = 3
Direita     = 4
ESC         = 5
Enter       = 6
Z           = 7
X           = 8
C           = 9
F           = 10
R           = 11
F1          = 12
F2          = 13
1           = 14
2           = 15
3           = 16
4           = 17
5           = 18
F3          = 19

********************************/

int PegarTecla()
{
    if(PIGTeclasControle == 0)
    {
        if(PIG_evento.teclado.acao == 768)
        {
            if(PIG_meuTeclado[TECLA_BAIXO])
            {
                PIGTeclasReturn = 1;
                PIGTeclasControle = 1;
                return 1;
            }
            else
            {
                if(PIG_meuTeclado[TECLA_CIMA])
                {
                    PIGTeclasReturn = 2;
                    PIGTeclasControle = 1;
                    return 2;
                }
                else
                {
                    if(PIG_meuTeclado[TECLA_ESQUERDA])
                    {
                        PIGTeclasReturn = 3;
                        PIGTeclasControle = 1;
                        return 3;
                    }
                    else
                    {
                        if(PIG_meuTeclado[TECLA_DIREITA])
                        {
                            PIGTeclasReturn = 4;
                            PIGTeclasControle = 1;
                            return 4;
                        }
                        else
                        {
                            if(PIG_meuTeclado[TECLA_ESC])
                            {
                                PIGTeclasReturn = 5;
                                PIGTeclasControle = 1;
                                return 5;
                            }
                            else
                            {
                                if(PIG_meuTeclado[TECLA_ENTER])
                                {
                                    PIGTeclasReturn = 6;
                                    PIGTeclasControle = 1;
                                    return 6;
                                }
                                else
                                {
                                    if(PIG_meuTeclado[TECLA_z])
                                    {
                                        PIGTeclasReturn = 7;
                                        PIGTeclasControle = 1;
                                        return 7;
                                    }
                                    else
                                    {
                                        if(PIG_meuTeclado[TECLA_x])
                                        {
                                            PIGTeclasReturn = 8;
                                            PIGTeclasControle = 1;
                                            return 8;
                                        }
                                        else
                                        {
                                            if(PIG_meuTeclado[TECLA_c])
                                            {
                                                PIGTeclasReturn = 9;
                                                PIGTeclasControle = 1;
                                                return 9;
                                            }
                                            else
                                            {
                                                if(PIG_meuTeclado[TECLA_f])
                                                {
                                                    PIGTeclasReturn = 10;
                                                    PIGTeclasControle = 1;
                                                    return 10;
                                                }
                                                else
                                                {
                                                    if(PIG_meuTeclado[TECLA_r])
                                                    {
                                                        PIGTeclasReturn = 11;
                                                        PIGTeclasControle = 1;
                                                        return 11;
                                                    }
                                                    else
                                                    {
                                                        if(PIG_meuTeclado[TECLA_F1])
                                                        {
                                                            PIGTeclasReturn = 12;
                                                            PIGTeclasControle = 1;
                                                            return 12;
                                                        }
                                                        else
                                                        {
                                                            if(PIG_meuTeclado[TECLA_F2])
                                                            {
                                                                PIGTeclasReturn = 13;
                                                                PIGTeclasControle = 1;
                                                                return 13;
                                                            }
                                                            else
                                                            {
                                                                if(PIG_meuTeclado[TECLA_1])
                                                                {
                                                                    PIGTeclasReturn = 14;
                                                                    PIGTeclasControle = 1;
                                                                    return 14;
                                                                }
                                                                else
                                                                {
                                                                    if(PIG_meuTeclado[TECLA_2])
                                                                    {
                                                                        PIGTeclasReturn = 15;
                                                                        PIGTeclasControle = 1;
                                                                        return 15;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(PIG_meuTeclado[TECLA_3])
                                                                        {
                                                                            PIGTeclasReturn = 16;
                                                                            PIGTeclasControle = 1;
                                                                            return 16;
                                                                        }
                                                                        else
                                                                        {
                                                                            if(PIG_meuTeclado[TECLA_4])
                                                                            {
                                                                                PIGTeclasReturn = 17;
                                                                                PIGTeclasControle = 1;
                                                                                return 17;
                                                                            }
                                                                            else
                                                                            {
                                                                                if(PIG_meuTeclado[TECLA_5])
                                                                                {
                                                                                    PIGTeclasReturn = 18;
                                                                                    PIGTeclasControle = 1;
                                                                                    return 18;
                                                                                }
                                                                                else
                                                                                {
                                                                                    if(PIG_meuTeclado[TECLA_F3])
                                                                                    {
                                                                                        PIGTeclasReturn = 19;
                                                                                        PIGTeclasControle = 1;
                                                                                        return 19;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        return 0;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(PIG_evento.teclado.acao == 769)
        {
            if(PIGTeclasReturn == 5 && PIG_meuTeclado[TECLA_ESC] == 0)
            {
                PIGTeclasControle = 0;
                return -5;
            }
            else
            {
                if(PIGTeclasReturn == 6 && PIG_meuTeclado[TECLA_ENTER] == 0)
                {
                    PIGTeclasControle = 0;
                    return -6;
                }
                else
                {
                    if(PIGTeclasReturn == 7 && PIG_meuTeclado[TECLA_z] == 0)
                    {
                        PIGTeclasControle = 0;
                        return -7;
                    }
                    else
                    {
                        if(PIGTeclasReturn == 8 && PIG_meuTeclado[TECLA_x] == 0)
                        {
                            PIGTeclasControle = 0;
                            return -8;
                        }
                        else
                        {
                            if(PIGTeclasReturn == 1 && PIG_meuTeclado[TECLA_BAIXO] == 0)
                            {
                                PIGTeclasControle = 0;
                                return -1;
                            }
                            else
                            {
                                if(PIGTeclasReturn == 2 && PIG_meuTeclado[TECLA_CIMA] == 0)
                                {
                                    PIGTeclasControle = 0;
                                    return -2;
                                }
                                else
                                {
                                    if(PIGTeclasReturn == 3 && PIG_meuTeclado[TECLA_ESQUERDA] == 0)
                                    {
                                        PIGTeclasControle = 0;
                                        return -3;
                                    }
                                    else
                                    {
                                        if(PIGTeclasReturn == 4 && PIG_meuTeclado[TECLA_DIREITA] == 0)
                                        {
                                            PIGTeclasControle = 0;
                                            return -4;
                                        }
                                        else
                                        {
                                            if(PIGTeclasReturn == 9 && PIG_meuTeclado[TECLA_c] == 0)
                                            {
                                                PIGTeclasControle = 0;
                                                return -9;
                                            }
                                            else
                                            {
                                                if(PIGTeclasReturn == 10 && PIG_meuTeclado[TECLA_f] == 0)
                                                {
                                                    PIGTeclasControle = 0;
                                                    return -10;
                                                }
                                                else
                                                {
                                                    if(PIGTeclasReturn == 11 && PIG_meuTeclado[TECLA_r] == 0)
                                                    {
                                                        PIGTeclasControle = 0;
                                                        return -11;
                                                    }
                                                    else
                                                    {
                                                        if(PIGTeclasReturn == 12 && PIG_meuTeclado[TECLA_F1] == 0)
                                                        {
                                                            PIGTeclasControle = 0;
                                                            return -12;
                                                        }
                                                        else
                                                        {
                                                            if(PIGTeclasReturn == 13 && PIG_meuTeclado[TECLA_F2] == 0)
                                                            {
                                                                PIGTeclasControle = 0;
                                                                return -13;
                                                            }
                                                            else
                                                            {
                                                                if(PIGTeclasReturn == 14 && PIG_meuTeclado[TECLA_1] == 0)
                                                                {
                                                                    PIGTeclasControle = 0;
                                                                    return -14;
                                                                }
                                                                else
                                                                {
                                                                    if(PIGTeclasReturn == 15 && PIG_meuTeclado[TECLA_2] == 0)
                                                                    {
                                                                        PIGTeclasControle = 0;
                                                                        return -15;
                                                                    }
                                                                    else
                                                                    {
                                                                        if(PIGTeclasReturn == 16 && PIG_meuTeclado[TECLA_3] == 0)
                                                                        {
                                                                            PIGTeclasControle = 0;
                                                                            return -16;
                                                                        }
                                                                        else
                                                                        {
                                                                            if(PIGTeclasReturn == 17 && PIG_meuTeclado[TECLA_4] == 0)
                                                                            {
                                                                                PIGTeclasControle = 0;
                                                                                return -17;
                                                                            }
                                                                            else
                                                                            {
                                                                                if(PIGTeclasReturn == 18 && PIG_meuTeclado[TECLA_5] == 0)
                                                                                {
                                                                                    PIGTeclasControle = 0;
                                                                                    return -18;
                                                                                }
                                                                                else
                                                                                {
                                                                                    if(PIGTeclasReturn == 19 && PIG_meuTeclado[TECLA_F3] == 0)
                                                                                    {
                                                                                        PIGTeclasControle = 0;
                                                                                        return -19;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        return 0;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            return 0;
        }
    }
}


int PegarBotao()
{
    static int Controle = 0;
    if(PIG_evento.mouse.acao == 1025)
    {
        Controle = 1;
    }
    else
    {
        if(PIG_evento.mouse.acao == 1026 && Controle == 1)
        {
            if(PIG_evento.mouse.botao==1)
            {
                Controle = 0;
                return 1;
            }
            else
            {
                if(PIG_evento.mouse.botao==2)
                {
                    Controle = 0;
                    return 2;
                }
                else
                {
                    Controle = 0;
                    return 3;
                }
            }
        }
    }
    return 0;
}
