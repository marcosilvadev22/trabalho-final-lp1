#pragma once
#include <string>

class Trajeto {
private:
    std::string nome;
public:
    Trajeto(std::string nome);
    std::string getNome();
};