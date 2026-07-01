#include "trajeto.h"

using namespace std;

Trajeto::Trajeto(Cidade* origem, Cidade* dest, char tpo, int dist) {
    this->origem = origem;
    this->dest = dest;
    this->tpo = tpo;
    this->dist = dist;
}


Cidade* Trajeto::getOrigem() {
    return this->origem;
}

Cidade* Trajeto::getDest() {
    return this->dest;
}

char Trajeto::getTpo() {
    return this->tpo;
}

int Trajeto::getDist() {
    return this->dist;
}