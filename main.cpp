#include <iostream>
#include <string>
#include "controlador-transito.h"

using namespace std;

int main() {

    ControladorTransito controlador;
    int opcao = 0;
    string nCidade;

    while (opcao != 9) {
        cout << "=== GUANABARA EMPRESA DE TRANSPORTE COLETIVO S.A. ===\n" << endl;
        cout << "Sistema de controle de viagens\n" << endl;
        cout << "1. Cadastrar Cidade\n" << endl;
        cout << "9. Sair\n" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome da cidade: ";
                cin >> nCidade;
                controlador.cadastrarCidade(nCidade);
                break;
            case 9:
                cout << "Saindo do sistema em 3,2,1..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }
    // cout << "Sistema a iniciar..." << endl; 
    return 0;
}