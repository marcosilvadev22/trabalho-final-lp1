#include "controlador-transito.h"


using namespace std; 

// Construtor vazio por enquanto
ControladorTransito::ControladorTransito(string nome) {
    this->nome = nome; 
}

// Método vazio por enquanto
string ControladorTransito::getNome() {
    return this->nome;
}