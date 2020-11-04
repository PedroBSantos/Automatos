#include "../inc/automata.h"

/*
    Inicializa um autômato com uma quantidade de states passada como parâmetro, o alphabet do autômato e se é um afnd.
    Por padrão, o parâmetro afnd é false.
*/
Automata::Automata(int numberStates, std::vector<char> alphabet, bool afnd)
{
    this->numberStates = numberStates;
    for (int i = 0; i < this->numberStates; i++)
    {
        std::shared_ptr<State> state(new State(i, false));
        this->states.push_back(state);
    }
    this->alphabet = alphabet;
    this->afnd = afnd;
}

Automata::Automata(const Automata &automata)
{
    this->numberStates = automata.numberStates;
    this->states = automata.states;
    this->alphabet = alphabet;
    this->afnd = afnd;
}

Automata::~Automata() {}

/*
    Adiciona uma transição entre 2 states dado um symbol.
*/
void Automata::createTransiction(int initialState, int finalState, char symbol)
{
    if (initialState < 0 || initialState >= this->numberStates || finalState < 0 || finalState >= this->numberStates)
    {
        return;
    }
    std::shared_ptr<Transiction> transiction(new Transiction(this->states[finalState], symbol));
    this->states[initialState]->getTransictions().insert(std::make_pair(symbol, transiction));
}

/*
    Define um ou mais states do autômato como final.
*/
void Automata::makeFinalState(int state)
{
    if (state < 0 || state >= this->numberStates)
    {
        return;
    }
    this->states[state]->setFinalState(true);
}

/*
    Realiza a leitura de uma word passada como parâmetro.
    Retorna true se a word fizer parte da linguagem do autômato,
    false caso contrário.
*/
bool Automata::readWord(const char *word)
{
    char acctualSymbol;
    if (this->afnd)
    {
        this->afndToAfd();
    }
    std::shared_ptr<State> acctualState = this->states[0];
    for (int i = 0; i < strlen(word); i++)
    {
        acctualSymbol = word[i];
        if (acctualState->getTransictions().count(acctualSymbol) == 0)
        {
            return false;
        }
        std::shared_ptr<Transiction> transiction = acctualState->getTransictions().find(acctualSymbol)->second;
        acctualState = transiction->getNextState();
    }
    return acctualState->isFinalState();
}

std::shared_ptr<State> Automata::initVoidState()
{
    std::shared_ptr<State> state(new State(std::numeric_limits<int>::max(), false));
    for (int i = 0; i < this->alphabet.size(); i++)
    {
        std::shared_ptr<Transiction> transiction(new Transiction(state, this->alphabet[i]));
        state->getTransictions().insert(std::make_pair(this->alphabet[i], transiction));
    }
    return state;
}

void Automata::afndToAfd()
{
    std::queue<std::vector<std::shared_ptr<State>>> queue;
    std::vector<std::shared_ptr<State>> states;
    std::vector<std::vector<std::shared_ptr<State>>> newStates;
    newStates.push_back(std::vector<std::shared_ptr<State>>{this->states[0]});
    queue.push(std::vector<std::shared_ptr<State>>{this->states[0]});
    //Instância do estadoVAzio
    std::shared_ptr<State> voidState = this->initVoidState();
    /*Map para armazenar os states que foram gerados no algoritmo para que estes não sejam processados novamente. 
    Chave vetor de states, valor bool para indicar se é um state final.*/
    std::map<std::vector<std::shared_ptr<State>>, bool> generatedStates;
    //Cria uma associação entre state e quais states ele possui transições
    std::multimap<std::vector<std::shared_ptr<State>>, std::vector<std::shared_ptr<State>>> aux3;
    aux3.insert(std::make_pair(std::vector<std::shared_ptr<State>>{voidState}, std::vector<std::shared_ptr<State>>{voidState}));
    int emptyValue = std::numeric_limits<int>::max();
    while (!queue.empty())
    {
        states = queue.front();
        queue.pop();
        if (states.size() >= 1 && states[0] != voidState && !generatedStates.count(states))
        {
            bool haveFinalState = false;
            for (int i = 0; i < this->alphabet.size(); i++)
            {
                std::vector<std::shared_ptr<State>> aux;
                std::map<int, std::shared_ptr<State>> findStates;
                for (int j = 0; j < states.size(); j++)
                {
                    if (!haveFinalState && states[j]->isFinalState() && !generatedStates.count(states))
                    {
                        haveFinalState = true;
                        generatedStates.insert(std::make_pair(states, true));
                    }
                    else if (j == states.size() - 1 && !haveFinalState && !generatedStates.count(states))
                    {
                        generatedStates.insert(std::make_pair(states, false));
                    }
                    if (states[j]->getTransictions().count(this->alphabet[i]) >= 1)
                    {
                        auto transictions = states[j]->getTransictions().equal_range(this->alphabet[i]);
                        for (auto it = transictions.first; it != transictions.second; it++)
                        {
                            std::shared_ptr<Transiction> transiction = it->second;
                            if (!findStates.count(transiction->getNextState()->getNumber()))
                            {
                                findStates.insert(std::make_pair(transiction->getNextState()->getNumber(), transiction->getNextState()));
                                aux.push_back(transiction->getNextState());
                            }
                        }
                    }
                    else if (!findStates.count(emptyValue))
                    {
                        aux.push_back(voidState);
                        findStates.insert(std::make_pair(emptyValue, voidState));
                    }
                }
                if (!findStates.count(emptyValue) || aux.size() > 1)
                {
                    std::sort(aux.begin(), aux.end());
                    if (aux[0]->getNumber() == emptyValue)
                    {
                        std::shared_ptr<State> aux5 = aux[0];
                        aux[0] = aux[aux.size() - 1];
                        aux[aux.size() - 1] = aux5;
                    }
                    if (!generatedStates.count(aux))
                    {
                        newStates.push_back(aux);
                        queue.push(aux);
                    }
                }
                aux3.insert(std::make_pair(states, aux));
            }
        }
    }
    //Criando os novos states
    states.clear();
    //Map para indicar se o state já foi criado
    std::map<std::vector<std::shared_ptr<State>>, bool> aux1;
    //Map para associar um state e a sua posição em newStates
    std::map<std::vector<std::shared_ptr<State>>, int> aux2;
    bool finalState;
    //Map para associar um conjunto de states a um state
    std::map<std::vector<std::shared_ptr<State>>, std::shared_ptr<State>> aux4;
    for (int i = 0; i < newStates.size(); i++)
    {
        if (!aux1.count(newStates[i]))
        {
            finalState = generatedStates.find(newStates[i])->second;
            std::shared_ptr<State> state(new State(i, finalState));
            states.push_back(state);
            aux1.insert(std::make_pair(newStates[i], true));
            aux2.insert(std::make_pair(newStates[i], i));
            aux4.insert(std::make_pair(newStates[i], state));
        }
    }
    //Criando as transições
    aux1.clear();
    for (int i = 0; i < newStates.size(); i++)
    {
        if (!aux1.count(newStates[i]))
        {
            aux1.insert(std::make_pair(newStates[i], true));
            std::shared_ptr<State> state = aux4.find(newStates[i])->second;
            auto range = aux3.equal_range(newStates[i]);
            int count = 0;
            //Obtendo todos os states que se relacionam com newStates[i]
            for (auto it = range.first; it != range.second; it++)
            {
                std::shared_ptr<State> aux = aux4.find(it->second)->second;
                std::shared_ptr<Transiction> transiction(new Transiction(aux, this->alphabet[count]));
                state->getTransictions().insert(std::make_pair(this->alphabet[count], transiction));
                count++;
            }
        }
    }
    this->afnd = false;
    this->states = states;
}