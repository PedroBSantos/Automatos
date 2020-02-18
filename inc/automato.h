#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string.h>
#include <vector>
#include "transicao.h"
#include "estado.h"

class Automato
{
private:
    std::vector<Estado *> estados;
    int qtdEstados;

public:
    Automato(int qtdEstados);
    Automato(const Automato &automato);
    ~Automato();
    int getQtdEstados();
    bool lerPalavra(const char *palavra);
    void criarTransicao(int estadoInicial, int estadoFinal, char simbolo);
    void definirEstadoFinal(int estado);
};

#endif