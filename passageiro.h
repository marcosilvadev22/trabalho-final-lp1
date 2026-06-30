#pragma once
#include <string>

class Passageiro {
private:
    std::string nome;
public:
    Passageiro(std::string nome);
    std::string getNome();
};