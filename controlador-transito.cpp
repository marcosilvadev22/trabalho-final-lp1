#include "controlador-transito.h"
#include "cidade.h" 
#include "passageiro.h"
#include "trajeto.h"
#include "transporte.h"

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

 void ControladorTransito::cadastrarTrajeto(string nmorigem, string nmdest, char tpo, int dist) {
    Cidade* cidOrigem = nullptr;
    Cidade* cidDestino = nullptr;

    for (Cidade* cid : cidades) {
        if (cid->getNome() == nmorigem) {
            cidOrigem = cid;
        }
        if (cid->getNome() == nmdest) {
            cidDestino = cid;
        }
    }
   if (cidOrigem == nullptr) {
        cout << "A cidade de origem [" << nmorigem << "] nao foi encontrada no mapa.\n" << endl;
        return;
    }

    if (cidDestino == nullptr) {
        cout << "A cidade de destino [" << nmdest << "] nao foi encontrada no mapa.\n" << endl;
        return;
    }

    Trajeto* nvTrajeto = new Trajeto(cidOrigem, cidDestino, tpo, dist);
    trajetos.push_back(nvTrajeto);

    cout << "O trajeto de " << nmorigem << " para " << nmdest << " foi cadastrado com sucesso.\n" << endl;
}

void ControladorTransito::cadastrarTransporte(string nome, char tp, int capc, int veloc, int distDesc, int tempoDesc, string locAtual) {
    Cidade* cidEncontrada = nullptr;

    for (Cidade* cid : cidades) {
        if (cid->getNome() == locAtual) {
            cidEncontrada = cid;
            break;
        }
    }

    if (cidEncontrada == nullptr) {
        cout << "A cidade " << locAtual << " não foi encontrada no mapa. Inicie em uma cidade válida!\n" << endl;
        return;
    }

    Transporte* nvTransporte = new Transporte(nome, tp, capc, veloc, distDesc, tempoDesc, cidEncontrada);
    transportes.push_back(nvTransporte);

    cout << "O transporte " << nome << " foi cadastrado na cidade " << locAtual << ".\n" << endl;
}

void ControladorTransito::embarcarPassageiro(string nmPassageiro, string nmTransp) {
    Passageiro* passagEncontrado = nullptr;
    Transporte* transpEncontrado = nullptr;

    for (Passageiro* pass : passageiros) {
        if (pass->getNome() == nmPassageiro) {
            passagEncontrado = pass;

        }
    }

    for (Transporte* transp : transportes) {
        if (transp->getNome() == nmTransp) {
            transpEncontrado = transp;

        }
    }

    if (passagEncontrado == nullptr || transpEncontrado == nullptr) {
        cout << "O passageiro ou transporte não foi encontrado.\n" << endl;
        return;

    }

    if (passagEncontrado->getLocAtual() != transpEncontrado->getLocAtual()) {
        cout << "O passageiro " << nmPassageiro << " não está na mesma cidade que o transporte " << nmTransp << ".\n" << endl;
        return;
    }

    if (transpEncontrado->embarcar(passagEncontrado)) {
        cout << "O passageiro " << nmPassageiro << " foi embarcado no transporte " << nmTransp << ".\n" << endl;
    } else {
        cout << "Não foi possível embarcar o passageiro " << nmPassageiro << " no transporte " << nmTransp << ".\n" << endl;
    } // novo teste que deu certo

    /*if (passagEncontrado == nullptr) {
        cout << "O passageiro " << nmPassageiro << " não foi encontrado.\n" << endl;
        return;
    }

    if (transpEncontrado == nullptr) {
        cout << "O transporte " << nmTransp << " não foi encontrado.\n" << endl;
        return;
    

    if (transpEncontrado->embarcar(passagEncontrado)) {
        cout << "O passageiro " << nmPassageiro << " foi embarcado no transporte " << nmTransp << ".\n" << endl;
    } else {
        cout << "Não foi possível embarcar o passageiro " << nmPassageiro << " no transporte " << nmTransp << ".\n" << endl;
    }} teste que deu errado */
}
// Método vazio por enquanto
//string ControladorTransito::getNome() {
  //  return this->nome;
// } 