/********************************
Seeeo de objetos
********************************/
/********************************
A funcao SetAnguloObjetoo() e responsevel pela angulaeeo de determinado objeto. A angulaeeo e calculada em sentido
horerio a partir do eixo X (0 graus). O objeto sere desenhado com a angulaeeo informada no preximo comando
DesenhaObjeto(). A deteceeo de coliseo neo funciona com objetos fora da angulaeeo padreo (0 graus).
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
angulo (entrada, passagem por valor): valor para indicar a angulaeeo do objeto em graus.
********************************/
void DefinirAngulo(int id_objeto, float angulo)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetAngulo(id_objeto,AnguloEquivalente(angulo));
    }
}

/********************************
A funcao PegarAngulo() e responsevel por recuperar o engulo de rotaeeo de determinado objeto. A angulaeeo e calculada em sentido
horerio a partir do eixo X (0 graus). O objeto sere desenhado com a angulaeeo informada no preximo comando
DesenhaObjeto(). A deteceeo de coliseo neo funciona com objetos fora da angulaeeo padreo (0 graus).
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
Retorno:
Retorna o valor do engulo em graus.
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
A funcao SetPivoObjeto() define um ponto (X,Y) em relaeeo ao ponto (0,0) do objeto, sobre o qual o objeto sere
rotacionado quando a funcao SetAnguloObjeto() for executada.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (entrada, passagem por valor): Valor da coordenada X do pive em relaeeo ao ponto (0,0) do objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y do pive em relaeeo ao ponto (0,0) do objeto.
********************************/
void DefinirPivo(int id_objeto,int posicaoX,int posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetPivo(id_objeto,posicaoX,posicaoY);
    }
}

/********************************
A funcao GetPivoObjeto() define um ponto (X,Y) em relaeeo ao ponto (0,0) do objeto, sobre o qual o objeto sere
rotacionado quando a funcao SetAnguloObjeto() for executada.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (saeda, passagem por referencia): Valor da coordenada X do pive em relaeeo ao ponto (0,0) do objeto.
posicaoY (saeda, passagem por referencia): Valor da coordenada Y do pive em relaeeo ao ponto (0,0) do objeto.
********************************/
void PegarPivo(int id_objeto,int *posicaoX,int *posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetPivo(id_objeto,posicaoX,posicaoY);
    }
}

/********************************
A funcao SetFlipObjeto() e responsevel por virar o objeto, invertendo-o em alguma direeeo. O objeto somente sere
desenhado na nova orientaeeo no preximo comando DesenhaObjeto().
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
valor (entrada, passagem por valor): valor do tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de inverseo),
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
A funcao GetFlipObjeto() e responsevel por recuperar o valor da manipulaeeo causada pela funcao SetFlipObjeto().
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser virado.
Retorno:
inteiro que indica o tipo de Flip. Pode ser FLIP_NENHUM (nenhum tipo de inverseo),
FLIP_HORIZONTAL (inverte da esquerda para a direita), FLIP_VERTICAL (inverte de cima para baixo),
ou FLIP_HORIZ_VERT (inverte da esquerda para direita e de cima para baixo).
********************************/
PIG_Flip PegarFlip(int id_objeto)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        return CGerenciadorObjetos::GetFlip(id_objeto);
    }
    return FLIP_NENHUM;
}

/********************************
A funcao SetDimensoesObjeto() e responsevel por delimitar a altura e a largura do objeto que sere desenhado na tela,
independentemente do tamanho original do arquivo de imagem.
Paremetros:
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
A funcao GetDimensoesObjeto() e responsevel por recuperar a altura e a largura da erea a ser usada
para desenhar o objeto na tela. Em outras palavras, representa o tamanho atual do objeto.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
altura (saeda, passagem por referencia): altura atual em pixels do objeto.
largura (saeda, passagem por referencia): largura atual em pixels do objeto.
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
A funcao GetDimensoesOriginaisObjeto() e responsevel por recuperar a altura e a largura originais da imagem
que foi usada para criar o objeto. Qualquer utilizaeeo da funcao SetDimensoesObjeto e ignorada para
o celculo desta funcao.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
altura (saeda, passagem por referencia): altura original em pixels do objeto.
largura (saeda, passagem por referencia): largura original em pixels do objeto.
********************************/
void PegarDimensoesOriginais(int id_objeto, int *altura, int *largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetDimensoesOriginais(id_objeto,altura,largura);
    }
}

/********************************
A funcao GetXYObjeto() e responsevel recuperar o valor da posieeo (X,Y) do objeto de acordo com o sistema de coordenadas do jogo.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
posicaoX (saeda, passagem por referencia): indica a posicao no eixo X do objeto.
posicaoY (saeda, passagem por referencia): indica a posicao no eixo Y do objeto.
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
A funcao DefineFrameObjeto() e responsevel por delimitar o posicionamento dos pixels do arquivo de imagem que sereo
utilizados para representar o objeto na tela. Desta forma, nem toda a imagem sere automaticamente utilizada para
representar o objeto. O sistema de coordenadas deve ser o padreo dos arquivos de imagem, com o eixo Y aumentando para baixo.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser desenhado.
xBitmap (entrada, passagem por valor): indica a posieeo de eixo X onde comeea o frame.
yBitmap (entrada, passagem por valor): indica a posieeo de eixo Y onde comeea o frame. Neste caso, o eixo Y aumenta para baixo.
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
A funcao SetColoracaoObjeto() e responsevel por mesclar uma determinada cor com os pixels do arquivo de imagem.
Apes a modificaeeo, todos os desenhos deste objeto sereo mostrados je com a mesclagem definida.
Para voltar ao padreo original de pixels, deve-se chamar a funcao, passando a cor branca (255,255,255).
Paremetros:
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
A funcao SetOpacidadeObjeto() e responsevel por modificar o nevel de opacidade do objeto.
O nevel de opacidade varia de 0-255, sendo 0 totalmente transparente e 255 totalmente opaco.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto.
valor (entrada,passagem por valor): nevel de opacidade do objeto na faixa 0-255.
********************************/
void DefinirOpacidade(int id_objeto,int valor)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetOpacidade(id_objeto,valor);
    }
}

/********************************
A funcao DesenhaObjeto() e responsevel por desenhar um objeto na tela ou no Renderizador Offscreen. O objeto sere desenhado de acordo com todas as definieees
de posieeo e engulo informado ate o momento. Alem disso, se o objeto estiver virado (flipping), isso tambem sere levado em consideraeeo.
Paremetros:
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
A funcao TestaColisaoObjetos() e responsevel por testar se dois objetos se colidiram ou neo, ao passar
os identificadores dos objetos por paremetro.
Paremetros:
id_objeto1 (entrada, passagem por valor): identificador do primeiro objeto.
id_objeto2 (entrada, passagem por valor): identificador do segundo objeto.
Retorno:
Inteiro indicando se houve coliseo (valor diferente de zero) ou neo (valor igual a 0, zero).
********************************/
int TestarColisaoObjetos(int id_objeto1,int id_objeto2)
{
    if(PIG_ExistenciaObjeto[id_objeto1] == 1 && PIG_ExistenciaObjeto[id_objeto2] == 1)
    {
        return CGerenciadorObjetos::TestaColisao(id_objeto1,id_objeto2);
    }
    return 0;
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
    return 0;
}


/********************************
A funcao MoveObjeto() e responsevel por movimentar um determinado obeto para uma nova posieeo informada.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser movido.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuerio deseja reposicionar o objeto.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuerio deseja reposicionar o objeto.
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
A funcao CriaObjeto() e responsevel por criar um objeto. Qualquer objeto que for necesserio,
pode ser criado atraves dessa funcao. O objeto ainda neo sere desenhado, apenas criado dentro do jogo.
Paremetros:
nomeArquivo (entrada, passagem por referencia): string que informa o nome do arquivo da imagem do objeto a ser criado.
retiraFundo (entrada, passagem por valor): inteiro que indica se o fundo da imagem deve ser retirado ou neo ao ler o arquivo em questeo. O valor padreo e 1, indicando que o fundo deve ser retirado.
opacidade (entrada,passagem por valor): nevel de opacidade do objeto na faixa 0-255. O valor padreo e 255, indicando nevel meximo de opacidade.
Retorno:
inteiro que representa o identificador enico do objeto. Todas as operaeees subsequentes com este objeto devereo receber este identificador como paremetro.
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

/********************************
A função CriaObjeto() é responsável por criar um objeto. Qualquer objeto que for necessário,
pode ser criado através dessa função. O objeto ainda não será desenhado, apenas criado dentro do jogo.
Parâmetros:
nomeArquivo (entrada, passagem por referência): string que informa o nome do arquivo da imagem do objeto a ser criado.
retiraFundo (entrada, passagem por valor): inteiro que indica se o fundo da imagem deve ser retirado ou não ao ler o arquivo em questão. O valor padrão é 1, indicando que o fundo deve ser retirado.
opacidade (entrada,passagem por valor): nível de opacidade do objeto na faixa 0-255. O valor padrão é 255, indicando nível máximo de opacidade.
Retorno:
inteiro que representa o identificador único do objeto. Todas as operações subsequentes com este objeto deverão receber este identificador como parâmetro.
********************************/
int criarObjeto(const char* nomeArquivo, int X, int Y, int Altura, int Largura, int retiraFundo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
    PIG_ExistenciaObjeto[Objt] = 1;
    DefinirDimensoes(Objt, Altura, Largura);
    DefinirPivo(Objt,Largura/2,Altura/2);
    DefinirAngulo(Objt,0);
    MoverCentro(Objt,X,Y);
    return Objt;
}


int criarObjetoTamanhoOriginal(char* nomeArquivo, int X, int Y, int retiraFundo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
    PIG_ExistenciaObjeto[Objt] = 1;

    int Altura = PegarAltura(Objt);
    int Largura = PegarLargura(Objt);
    DefinirPivo(Objt,Largura/2,Altura/2);
    DefinirAngulo(Objt,0);
    MoverCentro(Objt,X,Y);
    return Objt;
}


int CriarSprite(const char* nomeArquivo, int retiraFundo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
    PIG_ExistenciaObjeto[Objt] = 1;

    return Objt;
}

int CriarSprite(const char* nomeArquivo){
    return CriarSprite(nomeArquivo, 1);
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
A funcao DestroiObjeto() e responsevel por eliminar o objeto em questeo do jogo.
Paremetros:
id_objeto (entrada, passagem por valor): identificador do objeto a ser excluedo.
********************************/
void DestruirObjeto(int id_objeto)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        PIG_ExistenciaObjeto[id_objeto] = 0;
        CGerenciadorObjetos::DestroiObjeto(id_objeto);
    }
}
