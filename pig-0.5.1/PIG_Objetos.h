/********************************
Seï¿½ï¿½o de objetos
********************************/
/********************************
A funï¿½ï¿½o SetAnguloObjetoo() ï¿½ responsï¿½vel pela angulaï¿½ï¿½o de determinado objeto. A angulaï¿½ï¿½o ï¿½ calculada em sentido
horï¿½rio a partir do eixo X (0 graus). O objeto serï¿½ desenhado com a angulaï¿½ï¿½o informada no prï¿½ximo comando
DesenhaObjeto(). A detecï¿½ï¿½o de colisï¿½o nï¿½o funciona com objetos fora da angulaï¿½ï¿½o padrï¿½o (0 graus).
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
angulo (entrada, passagem por valor): valor para indicar a angulaï¿½ï¿½o do objeto em graus.
********************************/
void DefinirAngulo(int id_objeto, float angulo)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetAngulo(id_objeto,AnguloEquivalente(angulo));
    }
}

/********************************
A funï¿½ï¿½o PegarAngulo() ï¿½ responsï¿½vel por recuperar o ï¿½ngulo de rotaï¿½ï¿½o de determinado objeto. A angulaï¿½ï¿½o ï¿½ calculada em sentido
horï¿½rio a partir do eixo X (0 graus). O objeto serï¿½ desenhado com a angulaï¿½ï¿½o informada no prï¿½ximo comando
DesenhaObjeto(). A detecï¿½ï¿½o de colisï¿½o nï¿½o funciona com objetos fora da angulaï¿½ï¿½o padrï¿½o (0 graus).
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
Retorno:
Retorna o valor do ï¿½ngulo em graus.
********************************/
float PegarAngulo(int id_objeto)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        return CGerenciadorObjetos::GetAngulo(id_objeto);
    }
    return 0;
}

/********************************
A funï¿½ï¿½o SetPivoObjeto() define um ponto (X,Y) em relaï¿½ï¿½o ao ponto (0,0) do objeto, sobre o qual o objeto serï¿½
rotacionado quando a funï¿½ï¿½o SetAnguloObjeto() for executada.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (entrada, passagem por valor): Valor da coordenada X do pivï¿½ em relaï¿½ï¿½o ao ponto (0,0) do objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y do pivï¿½ em relaï¿½ï¿½o ao ponto (0,0) do objeto.
********************************/
void DefinirPivo(int id_objeto,int posicaoX,int posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetPivo(id_objeto,posicaoX,posicaoY);
    }
}

/********************************
A funï¿½ï¿½o GetPivoObjeto() define um ponto (X,Y) em relaï¿½ï¿½o ao ponto (0,0) do objeto, sobre o qual o objeto serï¿½
rotacionado quando a funï¿½ï¿½o SetAnguloObjeto() for executada.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (saï¿½da, passagem por referï¿½ncia): Valor da coordenada X do pivï¿½ em relaï¿½ï¿½o ao ponto (0,0) do objeto.
posicaoY (saï¿½da, passagem por referï¿½ncia): Valor da coordenada Y do pivï¿½ em relaï¿½ï¿½o ao ponto (0,0) do objeto.
********************************/
void PegarPivo(int id_objeto,int *posicaoX,int *posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetPivo(id_objeto,posicaoX,posicaoY);
    }
}

/********************************
A funï¿½ï¿½o SetFlipObjeto() ï¿½ responsï¿½vel por virar o objeto, invertendo-o em alguma direï¿½ï¿½o. O objeto somente serï¿½
desenhado na nova orientaï¿½ï¿½o no prï¿½ximo comando DesenhaObjeto().
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
valor (entrada, passagem por valor): valor do tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de inversï¿½o),
FLIP_HORIZONTAL (inverte da esquerda para a direita), FLIP_VERTICAL (inverte de cima para baixo),
ou FLIP_HORIZ_VERT (inverte da esquerda para direita e de cima para baixo).
********************************/
void DefinirFlip(int id_objeto,PIG_Flip valor)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetFlip(id_objeto,valor);
    }
}

/********************************
A funï¿½ï¿½o GetFlipObjeto() ï¿½ responsï¿½vel por recuperar o valor da manipulaï¿½ï¿½o causada pela funï¿½ï¿½o SetFlipObjeto().
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
Retorno:
inteiro que indica o tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de inversï¿½o),
FLIP_HORIZONTAL (inverte da esquerda para a direita), FLIP_VERTICAL (inverte de cima para baixo),
ou FLIP_HORIZ_VERT (inverte da esquerda para direita e de cima para baixo).
********************************/
PIG_Flip PegarFlip(int id_objeto)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        return CGerenciadorObjetos::GetFlip(id_objeto);
    }
}

/********************************
A funï¿½ï¿½o SetDimensoesObjeto() ï¿½ responsï¿½vel por delimitar a altura e a largura do objeto que serï¿½ desenhado na tela,
independentemente do tamanho original do arquivo de imagem.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
altura (entrada, passagem por valor): altura em pixels.
largura (entrada, passagem por valor): largura em pixels.
********************************/
void DefinirDimensoes(int id_objeto, int altura, int largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetDimensoes(id_objeto,altura,largura);
    }
}

/********************************
A funï¿½ï¿½o GetDimensoesObjeto() ï¿½ responsï¿½vel por recuperar a altura e a largura da ï¿½rea a ser usada
para desenhar o objeto na tela. Em outras palavras, representa o tamanho atual do objeto.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
altura (saï¿½da, passagem por referï¿½ncia): altura atual em pixels do objeto.
largura (saï¿½da, passagem por referï¿½ncia): largura atual em pixels do objeto.
********************************/
void PegarDimensoes(int id_objeto, int *altura, int *largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetDimensoes(id_objeto,altura,largura);
    }
}

int PegarLargura(int id_objeto)
{
    int a,l;

    PegarDimensoes(id_objeto,&a,&l);
    return l;

}
int PegarAltura(int id_objeto)
{
    int a,l;

    PegarDimensoes(id_objeto,&a,&l);
    return a;

}
/********************************
A funï¿½ï¿½o GetDimensoesOriginaisObjeto() ï¿½ responsï¿½vel por recuperar a altura e a largura originais da imagem
que foi usada para criar o objeto. Qualquer utilizaï¿½ï¿½o da funï¿½ï¿½o SetDimensoesObjeto ï¿½ ignorada para
o cï¿½lculo desta funï¿½ï¿½o.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
altura (saï¿½da, passagem por referï¿½ncia): altura original em pixels do objeto.
largura (saï¿½da, passagem por referï¿½ncia): largura original em pixels do objeto.
********************************/
void PegarDimensoesOriginais(int id_objeto, int *altura, int *largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetDimensoesOriginais(id_objeto,altura,largura);
    }
}

/********************************
A funï¿½ï¿½o GetXYObjeto() ï¿½ responsï¿½vel recuperar o valor da posiï¿½ï¿½o (X,Y) do objeto de acordo com o sistema de coordenadas do jogo.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (saï¿½da, passagem por referencia): indica a posicao no eixo X do objeto.
posicaoY (saï¿½da, passagem por referencia): indica a posicao no eixo Y do objeto.
********************************/
void PegarXY(int id_objeto,int *posicaoX,int *posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetPosicaoXY(id_objeto,posicaoX,posicaoY);
    }
}

int PegarX(int id_objeto)
{
    int x=0,y=0;

    PegarXY(id_objeto,&x,&y);

    return x;

}
int PegarY(int id_objeto)
{
    int x=0,y=0;

    PegarXY(id_objeto,&x,&y);

    return y;
}
int PegarCentroX(int id_objeto)
{
    int x=0,y=0,a,l;

    PegarXY(id_objeto,&x,&y);
    PegarDimensoes(id_objeto,&a,&l);
    x = x + (l/2);

    return x;

}
int PegarCentroY(int id_objeto)
{
    int x=0,y=0,a,l;

    PegarXY(id_objeto,&x,&y);
    PegarDimensoes(id_objeto,&a,&l);
    y = y + (a/2);

    return y;
}

/********************************
A funï¿½ï¿½o DefineFrameObjeto() ï¿½ responsï¿½vel por delimitar o posicionamento dos pixels do arquivo de imagem que serï¿½o
utilizados para representar o objeto na tela. Desta forma, nem toda a imagem serï¿½ automaticamente utilizada para
representar o objeto. O sistema de coordenadas deve ser o padrï¿½o dos arquivos de imagem, com o eixo Y aumentando para baixo.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
xBitmap (entrada, passagem por valor): indica a posiï¿½ï¿½o de eixo X onde comeï¿½a o frame.
yBitmap (entrada, passagem por valor): indica a posiï¿½ï¿½o de eixo Y onde comeï¿½a o frame. Neste caso, o eixo Y aumenta para baixo.
altura (entrada, passagem por valor): altura em pixels do frame.
largura (entrada, passagem por valor): largura em pixels do frame.
********************************/
void DefinirFrame(int id_objeto,int xBitmap, int yBitmap,int altura,int largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::CriaFrame(id_objeto,xBitmap,yBitmap,altura,largura);
    }
}

void MudarFrameObjeto(int id_objeto, char* nomeArquivo)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::MudarFrameObj(id_objeto,nomeArquivo);
    }
}

/********************************
A funï¿½ï¿½o SetColoracaoObjeto() ï¿½ responsï¿½vel por mesclar uma determinada cor com os pixels do arquivo de imagem.
Apï¿½s a modificaï¿½ï¿½o, todos os desenhos deste objeto serï¿½o mostrados jï¿½ com a mesclagem definida.
Para voltar ao padrï¿½o original de pixels, deve-se chamar a funï¿½ï¿½o, passando a cor branca (255,255,255).
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
cor (entrada,passagem por valor): cor do sistema RGB utilizada para mesclagem com o arquivo de imagem
********************************/
void DefinirColoracao(int id_objeto,PIG_Cor cor)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetColoracao(id_objeto,cor);
    }
}

/********************************
A funï¿½ï¿½o SetOpacidadeObjeto() ï¿½ responsï¿½vel por modificar o nï¿½vel de opacidade do objeto.
O nï¿½vel de opacidade varia de 0-255, sendo 0 totalmente transparente e 255 totalmente opaco.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto.
valor (entrada,passagem por valor): nï¿½vel de opacidade do objeto na faixa 0-255.
********************************/
void DefinirOpacidade(int id_objeto,int valor)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetOpacidade(id_objeto,valor);
    }
}

/********************************
A funï¿½ï¿½o DesenhaObjeto() ï¿½ responsï¿½vel por desenhar um objeto na tela ou no Renderizador Offscreen. O objeto serï¿½ desenhado de acordo com todas as definiï¿½ï¿½es
de posiï¿½ï¿½o e ï¿½ngulo informado atï¿½ o momento. Alï¿½m disso, se o objeto estiver virado (flipping), isso tambï¿½m serï¿½ levado em consideraï¿½ï¿½o.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
offScreen (entrada, passagem por valor): indica se o objeto deve ser desenhado no Renderizador Offscreen.
********************************/
void DesenharObjeto(int id_objeto, int offScreen=0)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        if (offScreen==0)
            CGerenciadorObjetos::Desenha(id_objeto,NULL);
        else CGerenciadorObjetos::Desenha(id_objeto,jogo->offRenderer);
    }
}

void DesenharSprite(int id_sprite, int X, int Y, int Largura, int Altura, float Angulo, int referencialVirtual = 1)
{
    if(PIG_ExistenciaObjeto[id_sprite] == 1)
    {
        if(referencialVirtual == 1)
        {
            CGerenciadorObjetos::DesenhaSprite(id_sprite,X,Y,Largura*(CameraZoom+1),Altura*(CameraZoom+1),Angulo);
        }
        else
        {
            CGerenciadorObjetos::DesenhaSprite(id_sprite,X,Y,Largura,Altura,Angulo);
        }
    }
}

/********************************
A funï¿½ï¿½o TestaColisaoObjetos() ï¿½ responsï¿½vel por testar se dois objetos se colidiram ou nï¿½o, ao passar
os identificadores dos objetos por parï¿½metro.
Parï¿½metros:
id_objeto1 (entrada, passagem por valor): identificador do primeiro objeto.
id_objeto2 (entrada, passagem por valor): identificador do segundo objeto.
Retorno:
Inteiro indicando se houve colisï¿½o (valor diferente de zero) ou nï¿½o (valor igual a 0, zero).
********************************/
int TestarColisaoObjetos(int id_objeto1,int id_objeto2)
{
    if(PIG_ExistenciaObjeto[id_objeto1] == 1 && PIG_ExistenciaObjeto[id_objeto2] == 1)
    {
        return CGerenciadorObjetos::TestaColisao(id_objeto1,id_objeto2);
    }
}

void GirarColisao(int IDUnit1, int XUnit1[4], int YUnit1[4])
{
    int AnguloUnit1 = (int)PegarAngulo(IDUnit1);

    if(AnguloUnit1 <= 45 || AnguloUnit1 > 315)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);
    }

    if(AnguloUnit1 <= 135 && AnguloUnit1 > 45)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);
    }

    if(AnguloUnit1 <= 225 && AnguloUnit1 > 135)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);
    }

    if(AnguloUnit1 <= 315 && AnguloUnit1 > 225)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);
    }
}

int ValidarColisao(int XUnit1[4], int YUnit1[4], int XUnit2[4], int YUnit2[4])
{
    if(XUnit1[0] >= XUnit2[2] && XUnit1[0] <= XUnit2[3])
    {
        if(YUnit1[0] >= YUnit2[2] && YUnit1[0] <= YUnit2[0])
        {
            return 1;
        }
    }

    if(XUnit1[1] >= XUnit2[2] && XUnit1[1] <= XUnit2[3])
    {
        if(YUnit1[1] >= YUnit2[2] && YUnit1[1] <= YUnit2[0])
        {
            return 1;
        }
    }

    if(XUnit1[2] >= XUnit2[2] && XUnit1[2] <= XUnit2[3])
    {
        if(YUnit1[2] >= YUnit2[2] && YUnit1[2] <= YUnit2[0])
        {
            return 1;
        }
    }

    if(XUnit1[3] >= XUnit2[2] && XUnit1[3] <= XUnit2[3])
    {
        if(YUnit1[3] >= YUnit2[2] && YUnit1[3] <= YUnit2[0])
        {
            return 1;

        }
    }
    return 0;
}

int VerificarColisao(int IDUnit1, int IDUnit2)
{
    int XUnit1[4], YUnit1[4], XUnit2[4], YUnit2[4], E, D;

    if(PIG_ExistenciaObjeto[IDUnit1] == 1 && PIG_ExistenciaObjeto[IDUnit2] == 1)
    {
        GirarColisao(IDUnit1,XUnit1,YUnit1);
        GirarColisao(IDUnit2,XUnit2,YUnit2);

        E = ValidarColisao(XUnit1, YUnit1, XUnit2, YUnit2);
        D = ValidarColisao(XUnit2, YUnit2, XUnit1, YUnit1);

        if(E == 1 || D == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}


/********************************
A funï¿½ï¿½o MoveObjeto() ï¿½ responsï¿½vel por movimentar um determinado obeto para uma nova posiï¿½ï¿½o informada.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser movido.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuï¿½rio deseja reposicionar o objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuï¿½rio deseja reposicionar o objeto.
********************************/

void MoverObjeto(int id_objeto,int posicaoX,int posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::Move(id_objeto,posicaoX,posicaoY);
    }
}

void MoverCentro(int id_objeto, float PosicaoX, float PosicaoY)
{
    int a,l;

    PegarDimensoes(id_objeto,&a,&l);
    PosicaoX = PosicaoX - l/2;
    PosicaoY = PosicaoY - a/2;
    MoverObjeto(id_objeto,PosicaoX,PosicaoY);
}

void MoverOffset(int id_objeto, float distancia, float angulo)
{
    float Adjacente,Oposto;
    float X,Y;

    Adjacente = (cos(angulo*M_PI/180)*distancia);
    Oposto = (sin(angulo*M_PI/180)*distancia);

    X = PegarCentroX(id_objeto) + Adjacente;
    Y = PegarCentroY(id_objeto) + Oposto;

    MoverCentro(id_objeto, X, Y);
}

/********************************
A funï¿½ï¿½o CriaObjeto() ï¿½ responsï¿½vel por criar um objeto. Qualquer objeto que for necessï¿½rio,
pode ser criado atravï¿½s dessa funï¿½ï¿½o. O objeto ainda nï¿½o serï¿½ desenhado, apenas criado dentro do jogo.
Parï¿½metros:
nomeArquivo (entrada, passagem por referï¿½ncia): string que informa o nome do arquivo da imagem do objeto a ser criado.
retiraFundo (entrada, passagem por valor): inteiro que indica se o fundo da imagem deve ser retirado ou nï¿½o ao ler o arquivo em questï¿½o. O valor padrï¿½o ï¿½ 1, indicando que o fundo deve ser retirado.
opacidade (entrada,passagem por valor): nï¿½vel de opacidade do objeto na faixa 0-255. O valor padrï¿½o ï¿½ 255, indicando nï¿½vel mï¿½ximo de opacidade.
Retorno:
inteiro que representa o identificador ï¿½nico do objeto. Todas as operaï¿½ï¿½es subsequentes com este objeto deverï¿½o receber este identificador como parï¿½metro.
********************************/
int CriarObjeto(char* nomeArquivo, int X, int Y, int Altura, int Largura)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,1,255);
    PIG_ExistenciaObjeto[Objt] = 1;
    DefinirDimensoes(Objt, Altura, Largura);
    DefinirPivo(Objt,Largura/2,Altura/2);
    DefinirAngulo(Objt,0);
    MoverCentro(Objt,X,Y);
    return Objt;
}

int CriarSprite(char* nomeArquivo, int retiraFundo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
    PIG_ExistenciaObjeto[Objt] = 1;

    return Objt;
}

int PIG_CriarVetor(char* nomeArquivo, int X, int Y, int Tamanho)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,1,255);
    PIG_ExistenciaObjeto[Objt] = 1;
    DefinirDimensoes(Objt, Tamanho/4.0, Tamanho);
    DefinirPivo(Objt,0,Tamanho/8.0);
    DefinirAngulo(Objt,0);
    MoverObjeto(Objt,X,Y-Tamanho/8.0);
    return Objt;
}


/********************************
A funï¿½ï¿½o DestroiObjeto() ï¿½ responsï¿½vel por eliminar o objeto em questï¿½o do jogo.
Parï¿½metros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser excluï¿½do.
********************************/
void DestruirObjeto(int id_objeto)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        PIG_ExistenciaObjeto[id_objeto] = 0;
        CGerenciadorObjetos::DestroiObjeto(id_objeto);
    }
}
