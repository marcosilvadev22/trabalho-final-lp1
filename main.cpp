#include <iostream>
#include <string>
#include "controlador-transito.h"

using namespace std;

int main() {

    ControladorTransito controlador;
    int opcao = 0;
    string nCidade, nOrigem, nDestino;
    char tVia;
    int dist;

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
            case 3: 
                cout << "Digite o nome da cidade de origem: ";
                cin >> ws;
                getline(cin, nOrigem);

                cout << "Digite o nome da cidade de destino: ";
                getline(cin, nDestino);
                cout << "Digite o tipo de via (A para asfalto, T para terra): ";
                cin >> tVia;
                cout << "Digite a distância entre as cidades: ";
                cin >> dist;
                controlador.cadastrarTrajeto(nOrigem, nDestino, tVia, dist);
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