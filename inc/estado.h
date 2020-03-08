#ifndef ESTADO_H
#define ESTADO_H

#include <vector>
#include <string>
#include <map>
#include <memory>

class Estado
{
private:
    int numero;
    bool estadoFinal;
    std::multimap<char, std::shared_ptr<class Transicao>> transicoes;

public:
    Estado();
    Estado(int numero, bool estadoFinal);
    Estado(const Estado &estado);
    ~Estado();
    int getNumero();
    bool getEstadoFinal();
    void setEstadoFinal(bool estadoFinal);
    std::multimap<char, std::shared_ptr<class Transicao>> &getTransicoes();
    friend bool operator>(std::shared_ptr<Estado> estado1, std::shared_ptr<Estado> estado2)
    {
        return estado1->numero > estado2->numero;
    }
    friend bool operator==(std::shared_ptr<Estado> estado1, std::shared_ptr<Estado> estado2)
    {
        return estado1->numero == estado2->numero;
    }
};
#endif