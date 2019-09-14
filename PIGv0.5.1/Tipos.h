
typedef struct atomo
{
    int ControleDeColisao;
    float Raio;
    float Massa;

    float PosicaoX;
    float PosicaoY;
    float PosicaoZ;

    float VelocidadeX;
    float VelocidadeY;
    float VelocidadeZ;

    float AceleracaoX;
    float AceleracaoY;
    float AceleracaoZ;

    float ForcaX;
    float ForcaY;
    float ForcaZ;

}   Atomo;

typedef struct ponto
{
    float X;
    float Y;
    float Z;
    PIG_Cor Cor;

}   Ponto;

typedef struct vetor
{
    Ponto Origem;
    Ponto Destino;
    PIG_Cor Cor;

    float Carga;

}   Vetor;
