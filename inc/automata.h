#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <memory>
#include "transiction.h"
#include "state.h"
#include <limits>

class Automata
{
private:
    std::vector<std::shared_ptr<State>> states;
    int numberStates;
    std::vector<char> alphabet;
    bool afnd;
    void afndToAfd();
    std::shared_ptr<State> initVoidState();

public:
    Automata(int numberStates, std::vector<char> alphabet, bool afnd = false);
    Automata(const Automata &automata);
    ~Automata();
    bool readWord(const char *word);
    void createTransiction(int initialState, int finalState, char symbol);
    void makeFinalState(int stateNumber);
};
#endif