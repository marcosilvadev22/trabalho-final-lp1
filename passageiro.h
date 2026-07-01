#pragma once
#include <string>
#include "cidade.h"

class Passageiro {
private:
    std::string nome;
    Cidade* locAtual;
public:
    Passageiro(std::string nome, Cidade* locAtual);
    std::string getNome();
    Cidade* getLocAtual();
    void setLocAtual(Cidade* cidade);
};