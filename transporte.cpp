#include "transporte.h"

using namespace std;

// Construtor vazio por enquanto
Transporte::Transporte(string nome, char tp, int capc, int veloc, int distDesc, int tempoDesc, Cidade* locAtual) {
    this->nome = nome;
    this->tp = tp;
    this->capc = capc;
    this->veloc = veloc;
    this->distDesc = distDesc;
    this->tempoDesc = tempoDesc;
    this->locAtual = locAtual;
}

// Método vazio por enquanto
string Transporte::getNome() {
    return this->nome;
}

char Transporte::getTipo() {
    return this->tp;
}

int Transporte::getCapac() {
    return this->capc;
}

int Transporte::getVeloc() {
    return this->veloc;
}

int Transporte::getDistDesc() {
    return this->distDesc;
}

int Transporte::getTempoDesc() {
    return this->tempoDesc;
}

Cidade* Transporte::getLocAtual() {
    return this->locAtual;
}

void Transporte::setLocAtual(Cidade* loc) {
    this->locAtual = loc;
}