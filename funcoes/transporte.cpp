#include "../classes/transporte.h"

using namespace std;

// Construtor vazio por enquanto
Transporte::Transporte(string nome, char tp, int capc, int veloc, int distDesc, int tempoDesc, Cidade *locAtual)
{
    this->nome = nome;
    this->tp = tp;
    this->capc = capc;
    this->veloc = veloc;
    this->distDesc = distDesc;
    this->tempoDesc = tempoDesc;
    this->locAtual = locAtual;
    this->tjtAtual = nullptr;
    this->distPerc = 0;
}

// Método vazio por enquanto
string Transporte::getNome()
{
    return this->nome;
}

char Transporte::getTipo()
{
    return this->tp;
}

int Transporte::getCapac()
{
    return this->capc;
}

int Transporte::getVeloc()
{
    return this->veloc;
}

int Transporte::getDistDesc()
{
    return this->distDesc;
}

int Transporte::getTempoDesc()
{
    return this->tempoDesc;
}

int Transporte::getDistPerc()
{
    return this->distPerc;
}

Cidade *Transporte::getLocAtual()
{
    return this->locAtual;
}

void Transporte::setLocAtual(Cidade *loc)
{
    this->locAtual = loc;
}

bool Transporte::embarcar(Passageiro *p)
{
    if (passageirosEmbarc.size() < capc)
    {
        passageirosEmbarc.push_back(p);
        return true;
    }
    return false;
}
void Transporte::iniciarViagem(Trajeto *tjt)
{
    this->tjtAtual = tjt;
    this->distPerc = 0;
}

Trajeto *Transporte::getTjtAtual()
{
    return this->tjtAtual;
}

void Transporte::setDistPerc(int dist)
{
    this->distPerc = dist;
}

void Transporte::desembarcarTodos()
{
    passageirosEmbarc.clear();
}