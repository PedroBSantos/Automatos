#ifndef TRANSICAO_H
#define TRANSICAO_H

#include "estado.h"
#include <memory>

class Transicao
{
private:
    std::shared_ptr<Estado> proximoEstado;
    char simbolo;

public:
    Transicao();
    Transicao(std::shared_ptr<Estado> proximoEstado, char simbolo);
    Transicao(const Transicao &transicao);
    ~Transicao();
    std::shared_ptr<Estado> getProximoEstado();
    char getSimbolo();
};

#endif