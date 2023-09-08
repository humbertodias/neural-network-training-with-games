/********************************
Seção dos temporizadores
********************************/

/********************************
A função CriaTimer() é responsável por criar um timer (temporizador). Após a criação o tempo decorrido
poderá ser obtido a partir da função Tempo_Decorrido(), informando o identificador que é passado na resposta.
Retorno:
inteiro que identifica o timer criado.
********************************/
int PIG_criarTimer()
{
    int timer;

    timer = CGerenciadorTimers::CriaTimer();
    return timer;
}

/********************************
A função TempoDecorrido() é responsável por informar o tempo decorrido desde a criação do timer
até a hora em que a função for chamada.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
Retorno:
número real indicando o tempo (em segundos) desde a criação do timer.
********************************/
double PIG_tempoDecorrido(int id_timer)
{
    return CGerenciadorTimers::GetTempoDecorrido(id_timer);

}

/********************************
A função PausaTimer() é responsável por realizar uma pausa na contagem do tempo de um timer. Após a despausa,
o timer continuará a contar o tempo normalmente.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_pausarTimer(int id_timer)
{
   CGerenciadorTimers::PausaTimer(id_timer);
}

/********************************
A função DespausaTimer() é responsável por retomar a contagem do tempo de um timer após uma pausa.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_despausarTimer(int id_timer)
{
    CGerenciadorTimers::DespausaTimer(id_timer);
}

/********************************
A função ReiniciaTimer() é responsável por zerar a contagem do tempo de um timer, idependente do tempo já decorrido.
Na prática, é equivalente a encerrer um temporizador e recriá-lo em seguida.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_reiniciarTimer(int id_timer)
{
    CGerenciadorTimers::ReiniciaTimer(id_timer);
}

/********************************
A função DestroiTimer() é responsável por encerrar a utilização de timer.
Seu identificador não poderá ser utilizado após a função ser executada.
Parâmetros:
id_timer (entrada, passagem por valor): identificador do timer.
********************************/
void PIG_destruirTimer(int id_timer)
{
    CGerenciadorTimers::DestroiTimer(id_timer);
}

