#include <iostream>
#include <string>
#include "controlador-transito.h"

using namespace std;

int main() {

    ControladorTransito controlador;
    int opcao = 0;
    string nCidade, nOrigem, nDestino, nTrans, nCidTrans;
    char tVia, tTrans;
    int dist, capc, veloc, distDesc, tempoDesc;

    while (opcao != 9) {
        cout << "=== GUANABARA EMPRESA DE TRANSPORTE COLETIVO S.A. ===\n" << endl;
        cout << "Sistema de controle de viagens\n" << endl;
        cout << "1. Cadastrar Cidade\n" << endl;
        cout << "2. Cadastrar Passageiro\n" << endl; // ainda falta a implementação na main 
        cout << "3. Cadastrar Trajeto\n" << endl;
        cout << "4. Cadastrar Transporte\n" << endl;
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
            case 4: 
                cout << "Digite o nome do transporte: ";
                cin >> ws;
                getline(cin, nTrans);

                cout << "Digite o tipo de transporte (A - Aquatico, T - Terrestre, AR - Aereo): ";
                cin >> tTrans;
                cout << "Digite a capacidade de passageiros do transporte: ";
                cin >> capc;
                cout << "Digite a velocidade do transporte: ";
                cin >> veloc;
                cout << "Digite a distância ate precisar descansar: ";
                cin >> distDesc;
                cout << "Digite o tempo de desccanso: ";
                cin >> tempoDesc;
                cout << "Digite o nome da cidade onde o transporte esta localizado: ";
                cin >> ws;
                getline(cin, nCidTrans);

                controlador.cadastrarTransporte(nTrans, tTrans, capc, veloc, distDesc, tempoDesc, nCidTrans);
                break;

            case 5: 
                cout << "Digite o nome do passageiro: ";
                cin >> ws;
                getline(cin, nTrans);

                cout << "Digite o nome do transporte: ";
                cin >> ws;
                getline(cin, nTrans);

                controlador.embarcarPassageiro(nTrans, nTrans);
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