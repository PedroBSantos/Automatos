#include "../inc/transicao.h"

Transicao::Transicao(Estado *proximoEstado, char simbolo)
{
    this->proximoEstado = proximoEstado;
    this->simbolo = simbolo;
}

Transicao::Transicao(const Transicao &transicao)
{
    this->proximoEstado = transicao.proximoEstado;
    this->simbolo = transicao.simbolo;
}

Transicao::~Transicao() {}

Estado *Transicao::getProximoEstado()
{
    return this->proximoEstado;
}

char Transicao::getSimbolo()
{
    return this->simbolo;
}