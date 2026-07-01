#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"

class ControladorTransito {
    private:
        std::vector<Cidade*> cidades;
        std::vector<Passageiro*> passageiros;
        std::vector<Trajeto*> trajetos;
    public:
        void cadastrarCidade(std::string nome);
    //string getNome();

        void cadastrarPassageiro(std::string nome, std::string locAtual);
        void cadastrarTrajeto(Cidade* nmorigem, Cidade* nmdest, char tpo, int dist);
};