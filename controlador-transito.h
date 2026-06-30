#pragma once
#include <string>

class ControladorTransito {
private:
    std::string nome;
public:
    ControladorTransito(std::string nome);
    std::string getNome();
};