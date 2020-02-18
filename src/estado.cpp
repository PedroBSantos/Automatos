#include "../inc/estado.h"
#include "../inc/transicao.h"

Estado::Estado(int numero, bool estadoFinal)
{
    this->numero = numero;
    this->estadoFinal = estadoFinal;
}

Estado::Estado(const Estado &estado)
{
    this->numero = estado.numero;
    this->estadoFinal = estado.estadoFinal;
    this->transicoes = estado.transicoes;
}

Estado::~Estado()
{
    for (int i = 0; i < this->transicoes.size(); i++)
    {
        if (this->transicoes[i] != nullptr)
        {
            delete this->transicoes[i];
        }
    }
}

int Estado::getNumero()
{
    return this->numero;
}

bool Estado::getEstadoFinal()
{
    return this->estadoFinal;
}

void Estado::setEstadoFinal(bool estadoFinal)
{
    this->estadoFinal = estadoFinal;
}

std::vector<Transicao *> &Estado::getTransicoes()
{
    return this->transicoes;
}