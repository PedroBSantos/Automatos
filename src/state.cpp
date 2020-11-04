#include "../inc/state.h"
#include "../inc/transiction.h"

State::State() {}

State::State(int number, bool finalState)
{
    this->number = number;
    this->finalState = finalState;
}

State::State(const State& state)
{
    this->number = state.number;
    this->finalState = state.finalState;
    this->transictions = state.transictions;
}

State::~State() {}

int State::getNumber()
{
    return this->number;
}

bool State::isFinalState()
{
    return this->finalState;
}

void State::setFinalState(bool finalState)
{
    this->finalState = finalState;
}

std::multimap<char, std::shared_ptr<Transiction>>& State::getTransictions()
{
    return this->transictions;
}