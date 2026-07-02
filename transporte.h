#pragma once
#include <string>
#include <vector>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"

class Transporte {
private:
    std::string nome;
    std::vector<Passageiro*> passageirosEmbarc;

    char tp;
    int capc;
    int veloc;
    int distDesc;
    int tempoDesc;
    int distPerc;

    Cidade* locAtual;
    Trajeto* tjtAtual;
    
public:
    Transporte(std::string nome, char tp, int capc, int veloc, int distDesc, int tempoDesc, Cidade* locAtual);

    std::string getNome();
    char getTipo();
    int getCapac();
    int getVeloc();
    int getDistDesc();
    int getTempoDesc();
    Cidade* getLocAtual();

    void setLocAtual(Cidade* loc);

    bool embarcar(Passageiro* p);

    void iniciarViagem(Trajeto* tjt);
    Trajeto* getTjtAtual();
};