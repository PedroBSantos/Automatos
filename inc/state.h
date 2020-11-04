#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <map>
#include <memory>

class State
{
private:
    int number;
    bool finalState;
    std::multimap<char, std::shared_ptr<class Transiction>> transictions;

public:
    State();
    State(int number, bool finalState);
    State(const State &state);
    ~State();
    int getNumber();
    bool isFinalState();
    void setFinalState(bool finalState);
    std::multimap<char, std::shared_ptr<class Transiction>> &getTransictions();
    friend bool operator>(std::shared_ptr<State> state1, std::shared_ptr<State> state2)
    {
        return state1->number > state2->number;
    }
    friend bool operator==(std::shared_ptr<State> state1, std::shared_ptr<State> state2)
    {
        return state1->number == state2->number;
    }
};
#endif