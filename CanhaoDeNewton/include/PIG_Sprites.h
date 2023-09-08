

/********************************
A função criarSprite() é responsável por alocar uma imagem na memória
********************************/

int PIG_criarSprite(char* nomeArquivo, int retiraFundo = 1)
{
    return CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
}

/********************************
A função destruirSprite() é responsável por desalocar uma imagem da memória
********************************/

void PIG_destruirSprite(int id_objeto)
{
    CGerenciadorObjetos::DestroiObjeto(id_objeto);
}
