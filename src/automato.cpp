#include "../inc/automato.h"
#include <iostream>

/*
    Inicializa um autômato com uma quantidade de estados passada como parâmetro.
*/
Automato::Automato(int qtdEstados)
{
    this->qtdEstados = qtdEstados;
    for (int i = 0; i < this->qtdEstados; i++)
    {
        Estado *estado = new Estado(i, false);
        this->estados.push_back(estado);
    }
}

Automato::Automato(const Automato &automato)
{
    this->qtdEstados = automato.qtdEstados;
    this->estados = automato.estados;
}

Automato::~Automato()
{
    for (int i = 0; i < this->estados.size(); i++)
    {
        if (this->estados[i] != nullptr)
        {
            delete this->estados[i];
        }
    }
}

int Automato::getQtdEstados()
{
    return this->qtdEstados;
}

/*
    Adiciona uma transição entre 2 estados dado um simbolo.
*/
void Automato::criarTransicao(int estadoInicial, int estadoFinal, char simbolo)
{
    if (estadoInicial < 0 || estadoInicial >= this->qtdEstados || estadoFinal < 0 || estadoFinal >= this->qtdEstados)
    {
        return;
    }
    Transicao *transicao = new Transicao(this->estados[estadoFinal], simbolo);
    this->estados[estadoInicial]->getTransicoes().push_back(transicao);
}

/*
    Define um ou mais estados do autômato como final.
*/
void Automato::definirEstadoFinal(int estado)
{
    if (estado < 0 || estado >= this->qtdEstados)
    {
        return;
    }
    this->estados[estado]->setEstadoFinal(true);
}

/*
    Realiza a leitura de uma palavra passada como parâmetro.
    Retorna true se a palavra fizer parte da linguagem do autômato,
    false caso contrário.
*/
bool Automato::lerPalavra(const char *palavra)
{
    Estado *estadoAtual = this->estados[0];
    char simboloAtual;
    for (int i = 0; i < strlen(palavra); i++)
    {
        simboloAtual = palavra[i];
        for (int j = 0; j < estadoAtual->getTransicoes().size(); j++)
        {
            if (estadoAtual->getTransicoes()[j]->getSimbolo() == simboloAtual)
            {
                estadoAtual = estadoAtual->getTransicoes()[j]->getProximoEstado();
                break;
            }
            else if (j == estadoAtual->getTransicoes().size() - 1)
            {
                return false;
            }
        }
    }
    return estadoAtual->getEstadoFinal();
}