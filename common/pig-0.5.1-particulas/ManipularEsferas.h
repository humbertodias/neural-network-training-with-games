
void InserirParticula(float Massa, float Px, float Py, float Vx, float Vy)
{
    Atomos[QuantidadeDeAtomos].Massa = Massa;
    Atomos[QuantidadeDeAtomos].ControleDeColisao = 0;
    Atomos[QuantidadeDeAtomos].Raio = RAIO_PARTICULA;

    Atomos[QuantidadeDeAtomos].ForcaX = 0;
    Atomos[QuantidadeDeAtomos].ForcaY = 0;
    Atomos[QuantidadeDeAtomos].AceleracaoX = 0;
    Atomos[QuantidadeDeAtomos].AceleracaoY = 0;
    Atomos[QuantidadeDeAtomos].VelocidadeX = Vx;
    Atomos[QuantidadeDeAtomos].VelocidadeY = Vy;
    Atomos[QuantidadeDeAtomos].PosicaoX = Px;
    Atomos[QuantidadeDeAtomos].PosicaoY = Py;

    QuantidadeDeAtomos = QuantidadeDeAtomos + 1;
}
