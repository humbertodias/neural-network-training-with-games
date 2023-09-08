/********************************
Seção de fontes
********************************/

/********************************
A função criarFonte() é responsável por disponibilizar uma nova fonte com preenchimento sólido.
Parâmetros:
nome (entrada, passagem por referência): nome do arquivo que contém a fonte (normalmente com extensão ttf).
tamanho (entrada, passagem por valor): tamanho da fonte, que normalmente representa a altura média (em pixels) dos caracteres da fonte.
corLetra (entrada, passagem por valor): representa a cor de preenchimento da fonte.
contorno (entrada, passagem por valor): representa a espessura do contorno que fonte terá. Caso não seja desejado um contorno, basta utilizar um valor 0.
corContorno (entrada, passagem por valor): representa a cor do contorno da fonte.
estilo (entrada, passagem por valor): representa o estilo da fonte. Pode ser uma combinação binária de: ESTILO_NEGRITO, para negrito; ESTILO_SUBLINHADO, para sublinhado; ESTILO_ITALICO, para itálico;
ESTILO_CORTADO, para uma linha horizontal à meia-altura. Caso nenhum estilo seja desejado, pode ser omitido ou usado ESTILO_NORMAL.
retono:
inteiro que representa a ideintificação única da fonte. Futuras referência a esta fonte devem idenitificá-las pelo número.
********************************/
int PIG_criarFonte(char *nome, int tamanho, PIG_Cor corLetra, int contorno, PIG_Cor corContorno, PIG_Estilo estilo=ESTILO_NORMAL)
{
    return jogo->CriaFonteNormal(nome,tamanho,estilo,corLetra,contorno,corContorno);
}

/********************************
A função CalculaLarguraPixels() por realizar a soma das larguras de cada letra da string informada.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
retorno:
inteiro que representa o total de pixels (no eixo x) necessários para escrever a string.
********************************/
int PIG_calcularLarguraPixels(char *str, int numFonte=0)
{
    return jogo->GetLarguraPixels(str);
}

/********************************
A função EscreverDireita() é responsável por exibir uma string na tela de jogo, com alinhamento à direita do valor de X.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja começar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja começar a escrever a string.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void PIG_escreverDireita(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverDireita(str,posicaoX,posicaoY,numFonte);
}

/********************************
A função EscreverEsquerda() é responsável por exibir uma string na tela de jogo, com alinhamento à esquerda do valor de X.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja começar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja começar a escrever a string.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void PIG_escreverEsquerda(char *str,int posicaoX,int posicaoY,int numFonte=0)
{
    jogo->EscreverEsquerda(str,posicaoX,posicaoY,numFonte);
}

/********************************
A função EscreverCentralizada() é responsável por exibir uma string na tela de jogo, com alinhamento em relação ao valor de X.
Parâmetros:
str (entrada, passagem por referência): string a ser escrita na tela.
posicaoX (entrada, passagem por valor): Valor da coordenada X da tela onde o usuário deseja começar a escrever a string.
posicaoY (entrada, passagem por valor): Valor da coordenada Y da tela onde o usuário deseja começar a escrever a string.
numFonte (entrada, passagem por valor): número da fonte a ser utilizada. Caso o usuário não deseje uma fonte especial, será utilizada a fonte padrão (numeroFonte=0, tipo=Arial, tamanho=36, cor = Branco).
********************************/
void PIG_escreverCentralizada(char *str, double X, double Y, int numFonte)
{
    jogo->EscreverCentralizada(str,X,Y,numFonte);
}
