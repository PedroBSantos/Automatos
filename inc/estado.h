#ifndef ESTADO_H
#define ESTADO_H

#include <vector>

class Estado
{
private:
    int numero;
    bool estadoFinal;
    std::vector<class Transicao *> transicoes;

public:
    Estado(int numero, bool estadoFinal);
    Estado(const Estado &estado);
    ~Estado();
    int getNumero();
    bool getEstadoFinal();
    void setEstadoFinal(bool estadoFinal);
    std::vector<class Transicao *> &getTransicoes();
};

#endif