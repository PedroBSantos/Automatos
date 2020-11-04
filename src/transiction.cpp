#include "../inc/transiction.h"

Transiction::Transiction() {}

Transiction::Transiction(std::shared_ptr<State> nextState, char symbol)
{
    this->nextState = nextState;
    this->symbol = symbol;
}

Transiction::Transiction(const Transiction &transiction)
{
    this->nextState = transiction.nextState;
    this->symbol = transiction.symbol;
}

Transiction::~Transiction() {}

std::shared_ptr<State> Transiction::getNextState()
{
    return this->nextState;
}

char Transiction::getSymbol()
{
    return this->symbol;
}