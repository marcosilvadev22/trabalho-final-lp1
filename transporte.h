#pragma once
#include <string>

class Transporte {
private:
    std::string nome;
public:
    Transporte(std::string nome);
    std::string getNome();
};