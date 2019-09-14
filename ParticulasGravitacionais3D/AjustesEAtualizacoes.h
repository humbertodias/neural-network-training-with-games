
void AtualizarAceleracao(Atomo* Objeto)
{
    Objeto->AceleracaoX = Objeto->ForcaX/Objeto->Massa;
    Objeto->AceleracaoY = Objeto->ForcaY/Objeto->Massa;
    Objeto->AceleracaoZ = Objeto->ForcaZ/Objeto->Massa;

    Objeto->ForcaX = 0;
    Objeto->ForcaY = 0;
    Objeto->ForcaZ = 0;
}

void AtualizarVelocidade(Atomo* Objeto)
{
    Objeto->VelocidadeX = Objeto->VelocidadeX + Objeto->AceleracaoX;
    Objeto->VelocidadeY = Objeto->VelocidadeY + Objeto->AceleracaoY;
    Objeto->VelocidadeZ = Objeto->VelocidadeZ + Objeto->AceleracaoZ;
}
