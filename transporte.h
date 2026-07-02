#pragma once
#include <string>
#include "cidade.h"

class Transporte {
private:
    std::string nome;
    char tp;
    int capc;
    int veloc;
    int distDesc;
    int tempoDesc;

    Cidade* locAtual;
    
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
};