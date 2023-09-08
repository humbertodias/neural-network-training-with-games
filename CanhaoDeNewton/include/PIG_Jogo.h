
/********************************
A função CriaJogo() é responsável pela criação da janela do jogo e pelos componentes audio-visuais.
Ela deve ser chamada antes de qualquer outra função da biblioetac PIG.h. Não é possível criar dois
jogos no mesmo progama. Logo, somente a primeira chamada terá efeito.
Parâmetros:
nome_Janela (entrada, passagem por referência*): indica o nome que a janela do jogo mostrará no seu título.
É utilizado o operador * apenas por se tratar de um parâmetro string. O valor do parâmetro não é alterado dentro da função.
cursor_Proprio (entrada, passagem por valor): indica se o jogo utilizará cursores (ponteiros) próprios para o mouse ou utilizará o cursor padrão.
********************************/
void PIG_criarJanela(char *nome_Janela, int largura, int altura)
{
    if(jogo == NULL)
    {
        LARG_TELA = largura;
        ALT_TELA = altura;
        jogo = new CJogo(nome_Janela, 0);
        CAssetLoader::Inicia();
        CGerenciadorTimers::Inicia();
        CGerenciadorObjetos::Inicia(jogo->renderer);
        CGerenciadorParticulas::Inicia(jogo->renderer);
        CGerenciadorAnimacoes::Inicia(jogo->renderer);
        PIG_teclado = jogo->PegaTeclado();
        PIG_mouse = jogo->PegaMouse();

        srand(time(NULL));
    }
}

/********************************
A função FinalizaJogo() é responsável por encerrar com a PIG. Após tudo o jogo ser executado
a função deve ser chamada e ela irá realizar a liberação de memória dos elementos criados pela PIG.
********************************/
void PIG_finalizarJanela()
{
    CGerenciadorAnimacoes::Encerra();
    CGerenciadorParticulas::Encerra();
    CGerenciadorObjetos::Encerra();
    CGerenciadorTimers::Encerra();
    CAssetLoader::Encerra();
    delete jogo;
}

void PIG_exibirCursor(int cursorExibido)
{
    SDL_ShowCursor(cursorExibido);
}

/********************************
A função pegarEvento() indica se houve algum tipo de evento desde a última vez que a função foi chamada.
Um evento pode ser uma tecla pressionada, um clique do mouse ou outra coisa relacionada à tela do jogo.
Maiores informaçõe podem ser vistas no arquivo Tipo_PIG.h
Retorno:
O valor de retorno é um struct contendo o tipo de evento ocorrido e vários outros structs com informações específicas.
********************************/
PIG_Evento PIG_pegarEvento()
{
    return jogo->PegaEvento();
}

/********************************
A função PegarTecla reconhece o apertar ou soltar de uma tecla e retorna um codigo.

Se o valor retornado for positivo isso significa que a tecla foi apertada
Se o valor retornado for negativo isso significa que a tecla foi "soltada"

********************************/
int PIG_pegarTecla()
{
    if(PIG_evento.tipoEvento == EVENTO_TECLADO)
    {
        if(PIG_evento.teclado.acao == TECLA_PRESSIONADA)
        {
            return PIG_evento.teclado.tecla;
        }
        if(PIG_evento.teclado.acao == TECLA_LIBERADA)
        {
            return -PIG_evento.teclado.tecla;
        }
    }
    return 0;
}

/********************************
A função PegarBotao reconhece qual botao do mouse foi clicado.

0 = botão esquerdo
1 = botão central (a rodinha)
2 = botão direito

Se o valor retornado for positivo isso significa que a tecla foi apertada
Se o valor retornado for negativo isso significa que a tecla foi "soltada"

********************************/
int PIG_pegarBotao()
{
    if(PIG_evento.tipoEvento == EVENTO_MOUSE)
    {
        if(PIG_evento.mouse.acao == MOUSE_PRESSIONADO)
        {
            return PIG_evento.mouse.botao;
        }
        if(PIG_evento.mouse.acao == MOUSE_LIBERADO)
        {
            return -(PIG_evento.mouse.botao);
        }
    }
    return 0;
}

/********************************
A função atualizarJanela() é reponsável por detectar todos os eventos e atualizar as variaveis internas da biblioteca.
********************************/
int PIG_atualizarJanela()
{
    PIG_evento  = PIG_pegarEvento();
    PIG_botao   = PIG_pegarBotao();
    PIG_tecla   = PIG_pegarTecla();
}

/********************************
A função IniciaDesenho() é responsável por preparar a janela do jogo para que os objetos gráficos
possam ser mostrados, além de desenhar a imagem de fundo do jogo, caso tenha sido definida.
Deve ser chamada repetidamente a cada novo quadro (frame) a ser desenhado.
********************************/
void PIG_iniciarDesenho()
{
    jogo->IniciaDesenho();
}

/********************************
A função EncerraDesenho() é responsável por encerrar o desenho que foi criado, mostrando na tela do jogo.
Deve ser chamado sempre ao final do loop principal do jogo.
********************************/
void PIG_encerrarDesenho()
{
    jogo->EncerraDesenho();
}

/********************************
A função getJogoRodando é reponsável por retornar se o jogo ainda está ativo ou não.
O jogo será encerrado se a janela do jogo for fechada, por exemplo.
Retorno:
inteiro que indica se o jogo ainda está sendo executado (valor diferente de zero) ou não (valor igual a 0, zero).
********************************/
int PIG_jogoRodando()
{
    return jogo->GetRodando();
}

/********************************
A função Espera() "congela" a tela do jogo por alguns milisegundos, impedindo que qualquer outro comando seja executado enquanto isso.
Parâmetros:
tempo (entrada, passagem por valor): indica a quantidade de milisegundos durante a qual o jogo será pausado.
********************************/
void PIG_esperar(int tempo)
{
    SDL_Delay(tempo);
}

/********************************
A função GetFPS() é responsável por calcular o valor do Frames Per Seconds (FPS), que representa a quantidade de
frames (quadros) desenhados por segundo pela PIG.
Retorno:
double que indica a média de quadros desenhados por segundo.
********************************/
double PIG_pegarFPS()
{
    return jogo->GetFPS();
}
