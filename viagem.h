#pragma once
#include <string>

class Viagem {
private:
    std::string nome;
public:
    Viagem(std::string nome);
    std::string getNome();
};