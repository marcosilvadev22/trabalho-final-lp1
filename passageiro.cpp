#include "passageiro.h"

using namespace std;


Passageiro::Passageiro(string nome, Cidade* locAtual) {
    this->nome = nome;
    this->locAtual = locAtual;
}

string Passageiro::getNome() {
    return this->nome;
}

Cidade* Passageiro::getLocAtual() {
    return this->locAtual;
}

void Passageiro::setLocAtual(Cidade* loc) {
    this->locAtual = loc;
}