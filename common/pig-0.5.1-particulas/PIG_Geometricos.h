/********************************
Se��o de elementos geom�tricos
********************************/

/********************************
A fun��o Desenha_LinhasSimples() � respons�vel por desenhar uma �nica linha, cujo in�cio � o ponto (x1,y1) e o fim � o ponto (x2,y2).
Par�metros:
pontoX1 (entrada, passagem por valor): inteiro que indica o in�cio da linha no eixo X.
pontoY1 (entrada, passagem por valor): inteiro que indica o in�cio da linha no eixo Y.
pontoX2 (entrada, passagem por valor): inteiro que indica o fim da linha no eixo X.
pontoY2 (entrada, passagem por valor): inteiro que indica o fim da linha no eixo Y.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho da linha;
********************************/
void DesenharLinhaSimples(int pontoX1,int pontoY1,int pontoX2,int pontoY2, PIG_Cor cor)
{
    jogo->DesenhaLinhaSimples(pontoX1,pontoY1,pontoX2,pontoY2,cor);
}

void DesenharLinhas(SDL_Point* points, int n, PIG_Cor cor)
{
    jogo->DesenhaLinhas(points,n,cor);
}

void DesenharPonto(float x, float y, int tam, PIG_Cor cor)
{
    jogo->DesenharPonto(x,y,tam,cor);
}

void DesenharPontos(const SDL_Point *points, int count, PIG_Cor cor)
{
    jogo->DesenharPontos(points,count,cor);
}




/********************************
A fun��o DesenhaRetangulo() � respons�vel por desenhar um ret�ngulo com preenchimento s�lido na tela em uma posi��o desejada pelo usu�rio.
O mesmo pode ser colocado em qualquer lugar do campo de vis�o da tela.
Par�metros:
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usu�rio deseja colocar o ret�ngulo.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usu�rio deseja colocar o ret�ngulo.
altura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � altura desse ret�ngulo.
largura (entrada, passagem por valor): Valor onde o usu�rio ir� fornecer o n�mero correspondente em pixels � largura desse ret�ngulo.
cor (entrada, passagem por valor): indica a cor no sistema RGB para o desenho do ret�ngulo;
********************************/
void DesenharRetangulo(int posicaoX, int posicaoY, int altura, int largura, PIG_Cor cor)
{
    jogo->DesenhaRetangulo(posicaoX,posicaoY,altura,largura,cor);
}
