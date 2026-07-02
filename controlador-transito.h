#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "cidade.h"
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"

class ControladorTransito {
    private:
        std::vector<Cidade*> cidades;
        std::vector<Passageiro*> passageiros;
        std::vector<Trajeto*> trajetos;
        std::vector<Transporte*> transportes;
    public:
        void cadastrarCidade(std::string nome);
    //string getNome();

        void cadastrarPassageiro(std::string nome, std::string locAtual);
        void cadastrarTrajeto(std::string nmorigem, std::string nmdest, char tpo, int dist);
        void cadastrarTransporte(std::string nome, char tp, int capc, int veloc, int distDesc, int tempoDesc, std::string locAtual);
        void embarcarPassageiro(std:: string nmPassageiro, std:: string nmTransp);
        void iniciarViagem(std:: string nmTransp, std:: string nmOrigTransp, std:: string nmDest);
};