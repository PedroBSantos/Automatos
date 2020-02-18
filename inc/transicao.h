#ifndef TRANSICAO_H
#define TRANSICAO_H

#include "estado.h"

class Transicao
{
private:
    Estado *proximoEstado;
    char simbolo;

public:
    Transicao(Estado *proximoEstado, char simbolo);
    Transicao(const Transicao &transicao);
    ~Transicao();
    Estado *getProximoEstado();
    char getSimbolo();
};

#endif