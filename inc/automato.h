#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <memory>
#include "transicao.h"
#include "estado.h"
#include <limits>

class Automato
{
private:
    std::vector<std::shared_ptr<Estado>> estados;
    int qtdEstados;
    std::vector<char> alfabeto;
    bool afnd;
    void afndToAfd();
    std::shared_ptr<Estado> inicializarEstadoVazio();
    void printConjunto(std::vector<std::shared_ptr<Estado>> estados);

public:
    Automato(int qtdEstados, std::vector<char> alfabeto, bool afnd = false);
    Automato(const Automato &automato);
    ~Automato();
    bool lerPalavra(const char *palavra);
    void criarTransicao(int estadoInicial, int estadoFinal, char simbolo);
    void definirEstadoFinal(int estado);
};
#endif