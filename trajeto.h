#pragma once
#include <string>
#include "cidade.h"

class Trajeto {
private:
    Cidade* origem;
    Cidade* dest;
    char tpo; 
    int dist;
public:
    Trajeto(Cidade* origem, Cidade* dest, char tpo, int dist);
    Cidade* getOrigem();
    Cidade* getDest();
    char getTpo();
    int getDist();
};