#include "controlador-transito.h"
#include "cidade.h" 
#include "passageiro.h"
#include "trajeto.h"

using namespace std; 


// Construtor vazio por enquanto
void ControladorTransito::cadastrarCidade(string nome) {
    
    Cidade* novaCidade = new Cidade(nome); 
    
    cidades.push_back(novaCidade); 
    
    cout << "A cidade " << nome << " foi criada no mapa." << endl;
}

void ControladorTransito::cadastrarPassageiro(string nome, string locAtual) {

  Cidade* cidEncontrada = nullptr;

  for(Cidade* cid : cidades) {
    if(cid->getNome() == locAtual) {
      cidEncontrada = cid;
      break;
    }
  }

  if (cidEncontrada == nullptr) {
    cout << "A cidade " << locAtual << " não foi encontrada no mapa.\n" << endl;
    return;
  }

  Passageiro* nvPassageiro = new Passageiro(nome, cidEncontrada);
  passageiros.push_back(nvPassageiro);

  cout << "O passageiro " << nome << " foi cadastrado na cidade " << locAtual << ".\n" << endl;
}

/* void ControladorTransito::cadastrarTrajeto(Cidade* nmorigem, Cidade* nmdest, char tpo, int dist) {

  Cidade* 
    Trajeto* nvTrajeto = new Trajeto(nmorigem, nmdest, tpo, dist);
    trajetos.push_back(nvTrajeto);
    cout << "O trajeto de " << nmorigem->getNome() << " para " << nmdest->getNome() << " foi cadastrado com sucesso." << endl;
} */

// Método vazio por enquanto
//string ControladorTransito::getNome() {
  //  return this->nome;
// } 