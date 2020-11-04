#ifndef TRANSICTION_H
#define TRANSICTION_H

#include "state.h"
#include <memory>

class Transiction
{
private:
    std::shared_ptr<State> nextState;
    char symbol;

public:
    Transiction();
    Transiction(std::shared_ptr<State> nextState, char symbol);
    Transiction(const Transiction &transicao);
    ~Transiction();
    std::shared_ptr<State> getNextState();
    char getSymbol();
};
#endif