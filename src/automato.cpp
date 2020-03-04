#include "../inc/automato.h"

/*
    Inicializa um autômato com uma quantidade de estados passada como parâmetro, o alfabeto do autômato e se é um afnd.
    Por padrão, o parâmetro afnd é false.
*/
Automato::Automato(int qtdEstados, std::vector<char> alfabeto, bool afnd)
{
    this->qtdEstados = qtdEstados;
    for (int i = 0; i < this->qtdEstados; i++)
    {
        std::shared_ptr<Estado> estado(new Estado(i, false));
        this->estados.push_back(estado);
    }
    this->alfabeto = alfabeto;
    this->afnd = afnd;
}

Automato::Automato(const Automato &automato)
{
    this->qtdEstados = automato.qtdEstados;
    this->estados = automato.estados;
    this->alfabeto = alfabeto;
    this->afnd = afnd;
}

Automato::~Automato() {}

/*
    Adiciona uma transição entre 2 estados dado um simbolo.
*/
void Automato::criarTransicao(int estadoInicial, int estadoFinal, char simbolo)
{
    if (estadoInicial < 0 || estadoInicial >= this->qtdEstados || estadoFinal < 0 || estadoFinal >= this->qtdEstados)
    {
        return;
    }
    std::shared_ptr<Transicao> transicao(new Transicao(this->estados[estadoFinal], simbolo));
    this->estados[estadoInicial]->getTransicoes().insert(std::make_pair(simbolo, transicao));
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
    char simboloAtual;
    if (this->afnd)
    {
        this->afndToAfd();
    }
    std::shared_ptr<Estado> estadoAtual = this->estados[0];
    for (int i = 0; i < strlen(palavra); i++)
    {
        simboloAtual = palavra[i];
        if (estadoAtual->getTransicoes().count(simboloAtual) == 0)
        {
            return false;
        }
        std::shared_ptr<Transicao> transicao = estadoAtual->getTransicoes().find(simboloAtual)->second;
        estadoAtual = transicao->getProximoEstado();
    }
    return estadoAtual->getEstadoFinal();
}

std::shared_ptr<Estado> Automato::inicializarEstadoVazio()
{
    std::shared_ptr<Estado> estado(new Estado(std::numeric_limits<int>::max(), false));
    for (int i = 0; i < this->alfabeto.size(); i++)
    {
        std::shared_ptr<Transicao> transicao(new Transicao(estado, this->alfabeto[i]));
        estado->getTransicoes().insert(std::make_pair(this->alfabeto[i], transicao));
    }
    return estado;
}

void Automato::afndToAfd()
{
    std::queue<std::vector<std::shared_ptr<Estado>>> fila;
    std::vector<std::shared_ptr<Estado>> estados;
    std::vector<std::vector<std::shared_ptr<Estado>>> novosEstados;
    novosEstados.push_back(std::vector<std::shared_ptr<Estado>>{this->estados[0]});
    fila.push(std::vector<std::shared_ptr<Estado>>{this->estados[0]});
    //Instância do estadoVAzio
    std::shared_ptr<Estado> estadoVazio = this->inicializarEstadoVazio();
    /*Map para armazenar os estados que foram gerados no algoritmo para que estes não sejam processados novamente. 
    Chave vetor de estados, valor bool para indicar se é um estado final.*/
    std::map<std::vector<std::shared_ptr<Estado>>, bool> estadosGerados;
    //Cria uma associação entre estado e quais estados ele possui transições
    std::multimap<std::vector<std::shared_ptr<Estado>>, std::vector<std::shared_ptr<Estado>>> aux3;
    aux3.insert(std::make_pair(std::vector<std::shared_ptr<Estado>>{estadoVazio}, std::vector<std::shared_ptr<Estado>>{estadoVazio}));
    int valorVazio = std::numeric_limits<int>::max();
    while (!fila.empty())
    {
        estados = fila.front();
        fila.pop();
        if (estados.size() >= 1 && estados[0] != estadoVazio && !estadosGerados.count(estados))
        {
            bool possuiEstadoFinal = false;
            for (int i = 0; i < this->alfabeto.size(); i++)
            {
                std::vector<std::shared_ptr<Estado>> aux;
                std::map<int, std::shared_ptr<Estado>> estadosEncontrados;
                for (int j = 0; j < estados.size(); j++)
                {
                    if (!possuiEstadoFinal && estados[j]->getEstadoFinal() && !estadosGerados.count(estados))
                    {
                        possuiEstadoFinal = true;
                        estadosGerados.insert(std::make_pair(estados, true));
                    }
                    else if (j == estados.size() - 1 && !possuiEstadoFinal && !estadosGerados.count(estados))
                    {
                        estadosGerados.insert(std::make_pair(estados, false));
                    }
                    if (estados[j]->getTransicoes().count(this->alfabeto[i]) >= 1)
                    {
                        auto transicoes = estados[j]->getTransicoes().equal_range(this->alfabeto[i]);
                        for (auto iterador = transicoes.first; iterador != transicoes.second; iterador++)
                        {
                            std::shared_ptr<Transicao> transicao = iterador->second;
                            if (!estadosEncontrados.count(transicao->getProximoEstado()->getNumero()))
                            {
                                estadosEncontrados.insert(std::make_pair(transicao->getProximoEstado()->getNumero(), transicao->getProximoEstado()));
                                aux.push_back(transicao->getProximoEstado());
                            }
                        }
                    }
                    else if (!estadosEncontrados.count(valorVazio))
                    {
                        aux.push_back(estadoVazio);
                        estadosEncontrados.insert(std::make_pair(valorVazio, estadoVazio));
                    }
                }
                if (!estadosEncontrados.count(valorVazio) || aux.size() > 1)
                {
                    std::sort(aux.begin(), aux.end());
                    if (aux[0]->getNumero() == valorVazio)
                    {
                        std::shared_ptr<Estado> aux5 = aux[0];
                        aux[0] = aux[aux.size() - 1];
                        aux[aux.size() - 1] = aux5;
                    }
                    if (!estadosGerados.count(aux))
                    {
                        novosEstados.push_back(aux);
                        fila.push(aux);
                    }
                }
                aux3.insert(std::make_pair(estados, aux));
            }
        }
    }
    //Criando os novos estados
    estados.clear();
    //Map para indicar se o estado já foi criado
    std::map<std::vector<std::shared_ptr<Estado>>, bool> aux1;
    //Map para associar um estado e a sua posição em novosEstados
    std::map<std::vector<std::shared_ptr<Estado>>, int> aux2;
    bool estadoFinal;
    //Map para associar um conjunto de estados a um estado
    std::map<std::vector<std::shared_ptr<Estado>>, std::shared_ptr<Estado>> aux4;
    for (int i = 0; i < novosEstados.size(); i++)
    {
        if (!aux1.count(novosEstados[i]))
        {
            estadoFinal = estadosGerados.find(novosEstados[i])->second;
            std::shared_ptr<Estado> estado(new Estado(i, estadoFinal));
            estados.push_back(estado);
            aux1.insert(std::make_pair(novosEstados[i], true));
            aux2.insert(std::make_pair(novosEstados[i], i));
            aux4.insert(std::make_pair(novosEstados[i], estado));
        }
    }
    //Criando as transições
    aux1.clear();
    for (int i = 0; i < novosEstados.size(); i++)
    {
        if (!aux1.count(novosEstados[i]))
        {
            aux1.insert(std::make_pair(novosEstados[i], true));
            std::shared_ptr<Estado> estado = aux4.find(novosEstados[i])->second;
            auto range = aux3.equal_range(novosEstados[i]);
            int contador = 0;
            //Obtendo todos os estados que se relacionam com novosEstados[i]
            for (auto iterador = range.first; iterador != range.second; iterador++)
            {
                std::shared_ptr<Estado> aux = aux4.find(iterador->second)->second;
                std::shared_ptr<Transicao> transicao(new Transicao(aux, this->alfabeto[contador]));
                estado->getTransicoes().insert(std::make_pair(this->alfabeto[contador], transicao));
                contador++;
            }
        }
    }
    this->afnd = false;
    this->estados = estados;
}