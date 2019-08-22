
#define PASSARO_CODIGO_TIPO     5
#define ESPINHO_CODIGO_TIPO     6

#define MODO_JOGO               0       /// 0 = TREINANDO   - OBS: Aumentar tamanho da populacao para 2000
                                        /// 1 = JOGAVEL     - OBS: Diminuir tamanho da populacao para 1

#define POPULACAO_TAMANHO       2000


#define DINO_BRAIN_QTD_LAYERS   1       /// Quantidade de camadas escondidas na rede neural
#define DINO_BRAIN_QTD_INPUT    6       /// Quantidade de neuronios na camada de entrada
#define DINO_BRAIN_QTD_HIDE     6       /// Quantidade de neuronios nas camadas escondidas
#define DINO_BRAIN_QTD_OUTPUT   3       /// Quantidade de neuronios na camada de saida

#include <cstdio>

#include "PIG.h"                        ///   Biblioteca Grafica
#include "Sprites.h"                    ///   Todos os códigos sobre sprite
#include "redeNeural.c"                 ///   Código da rede neural
#include "Tipos.h"                      ///   Definições de structs
#include "Variaveis.h"                  ///   Variaveis globais
#include "FuncoesAuxiliares.h"
#include "DNAs.h"
#include "Desenhar.h"
#include "GeradorObstaculos.h"
#include "Inicializar.h"
#include "Alocacoes.h"
#include "Colisao.h"
#include "Movimentar.h"
#include "Atualizar.h"
#include "InputsRedeNeural.h"   /// Funções que captam a informação para entregar para a rede neural


#include <thread>
#include <chrono>

///////////////////////////////////////////////////

int main(int argc, char* args[])
{
    GerarListaObstaculosTreinoSemEspinho();

    return 0;
}
