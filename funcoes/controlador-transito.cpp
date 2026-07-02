#include "../classes/controlador-transito.h"
#include "../classes/cidade.h"
#include "../classes/passageiro.h"
#include "../classes/trajeto.h"
#include "../classes/transporte.h"

using namespace std;

// Construtor vazio por enquanto
void ControladorTransito::cadastrarCidade(string nome)
{

    Cidade *novaCidade = new Cidade(nome);

    cidades.push_back(novaCidade);

    cout << "A cidade " << nome << " foi criada no mapa." << endl;
}

void ControladorTransito::cadastrarPassageiro(string nome, string locAtual)
{

    Cidade *cidEncontrada = nullptr;

    for (Cidade *cid : cidades)
    {
        if (cid->getNome() == locAtual)
        {
            cidEncontrada = cid;
            break;
        }
    }

    if (cidEncontrada == nullptr)
    {
        cout << "A cidade " << locAtual << " não foi encontrada no mapa.\n"
             << endl;
        return;
    }

    Passageiro *nvPassageiro = new Passageiro(nome, cidEncontrada);
    passageiros.push_back(nvPassageiro);

    cout << "O passageiro " << nome << " foi cadastrado na cidade " << locAtual << ".\n"
         << endl;
}

void ControladorTransito::cadastrarTrajeto(string nmorigem, string nmdest, char tpo, int dist)
{
    Cidade *cidOrigem = nullptr;
    Cidade *cidDestino = nullptr;

    for (Cidade *cid : cidades)
    {
        if (cid->getNome() == nmorigem)
        {
            cidOrigem = cid;
        }
        if (cid->getNome() == nmdest)
        {
            cidDestino = cid;
        }
    }
    if (cidOrigem == nullptr)
    {
        cout << "A cidade de origem [" << nmorigem << "] nao foi encontrada no mapa.\n"
             << endl;
        return;
    }

    if (cidDestino == nullptr)
    {
        cout << "A cidade de destino [" << nmdest << "] nao foi encontrada no mapa.\n"
             << endl;
        return;
    }

    Trajeto *nvTrajeto = new Trajeto(cidOrigem, cidDestino, tpo, dist);
    trajetos.push_back(nvTrajeto);

    cout << "O trajeto de " << nmorigem << " para " << nmdest << " foi cadastrado com sucesso.\n"
         << endl;
}

void ControladorTransito::cadastrarTransporte(string nome, char tp, int capc, int veloc, int distDesc, int tempoDesc, string locAtual)
{
    Cidade *cidEncontrada = nullptr;

    for (Cidade *cid : cidades)
    {
        if (cid->getNome() == locAtual)
        {
            cidEncontrada = cid;
            break;
        }
    }

    if (cidEncontrada == nullptr)
    {
        cout << "A cidade " << locAtual << " não foi encontrada no mapa. Inicie em uma cidade válida!\n"
             << endl;
        return;
    }

    Transporte *nvTransporte = new Transporte(nome, tp, capc, veloc, distDesc, tempoDesc, cidEncontrada);
    transportes.push_back(nvTransporte);

    cout << "O transporte " << nome << " foi cadastrado na cidade " << locAtual << ".\n"
         << endl;
}

void ControladorTransito::embarcarPassageiro(string nmPassageiro, string nmTransp)
{
    Passageiro *passagEncontrado = nullptr;
    Transporte *transpEncontrado = nullptr;

    for (Passageiro *pass : passageiros)
    {
        if (pass->getNome() == nmPassageiro)
        {
            passagEncontrado = pass;
        }
    }

    for (Transporte *transp : transportes)
    {
        if (transp->getNome() == nmTransp)
        {
            transpEncontrado = transp;
        }
    }

    if (passagEncontrado == nullptr || transpEncontrado == nullptr)
    {
        cout << "O passageiro ou transporte não foi encontrado.\n"
             << endl;
        return;
    }

    if (passagEncontrado->getLocAtual() != transpEncontrado->getLocAtual())
    {
        cout << "O passageiro " << nmPassageiro << " não está na mesma cidade que o transporte " << nmTransp << ".\n"
             << endl;
        return;
    }

    if (transpEncontrado->embarcar(passagEncontrado))
    {
        cout << "O passageiro " << nmPassageiro << " foi embarcado no transporte " << nmTransp << ".\n"
             << endl;
    }
    else
    {
        cout << "Não foi possível embarcar o passageiro " << nmPassageiro << " no transporte " << nmTransp << ".\n"
             << endl;
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

void ControladorTransito::iniciarViagem(string nmTransp, string nmOrigTransp, string nmDest)
{
    Transporte *transpEncontrado = nullptr;
    Trajeto *tjtEncontrado = nullptr;

    for (Transporte *transp : transportes)
    {
        if (transp->getNome() == nmTransp)
        {
            transpEncontrado = transp;
        }
    }

    for (Trajeto *tjt : trajetos)
    {
        if (tjt->getOrigem()->getNome() == nmOrigTransp && tjt->getDest()->getNome() == nmDest)
        {
            tjtEncontrado = tjt;
            break;
        }
    }

    if (transpEncontrado == nullptr)
    {
        cout << "O transporte " << nmTransp << " não foi encontrado.\n"
             << endl;
        return;
    }

    if (tjtEncontrado == nullptr)
    {
        cout << "O trajeto de " << nmOrigTransp << " para " << nmDest << " não foi encontrado.\n"
             << endl;
        return;
    }
    if (transpEncontrado->getLocAtual() != tjtEncontrado->getOrigem())
    {
        cout << "O transporte " << nmTransp << " não está na cidade de origem do trajeto.\n"
             << endl;
        return;
    }
    if (transpEncontrado->getTipo() != tjtEncontrado->getTpo())
    {
        cout << "O transporte " << nmTransp << " não é compatível com o tipo do trajeto.\n"
             << endl;
        return;
    }

    transpEncontrado->iniciarViagem(tjtEncontrado);
    transpEncontrado->setLocAtual(nullptr);

    cout << "O transporte " << nmTransp << " iniciou a viagem de " << nmOrigTransp << " para " << nmDest << ".\n"
         << endl;
}

void ControladorTransito::avancarTempo(int tempo)
{

    cout << "Avançando o tempo em " << tempo << " horas.\n"
         << endl;

    for (Transporte *transp : transportes)
    {

        if (transp->getTjtAtual() != nullptr)
        {

            // int distPerc = transp->getDistPerc();

            int distPerc = transp->getVeloc() * tempo;
            int par = distPerc / transp->getDistDesc();
            int tempoPerd = par * transp->getTempoDesc();
            int tempoReal = tempo - tempoPerd;

            if (tempoReal < 0)
            {
                tempoReal = 0;
            }

            int distReal = tempoReal * transp->getVeloc();
            transp->setDistPerc(transp->getDistPerc() + distReal);

            Trajeto *tjtAtual = transp->getTjtAtual();

            if (transp->getDistPerc() >= tjtAtual->getDist())
            {
                transp->setLocAtual(tjtAtual->getDest());
                transp->iniciarViagem(nullptr);
                transp->desembarcarTodos();
                // transp->setDistPerc(0);
                cout << "O transporte " << transp->getNome() << " chegou ao destino " << transp->getLocAtual()->getNome() << ".\n"
                     << endl;
            }
            else
            {
                cout << "O transporte " << transp->getNome() << " percorreu " << distReal << " km na viagem.\n"
                     << endl;
            }

            /*  if (nvDistPerc >= transp->getTjtAtual()->getDist()) {
                 transp->setLocAtual(transp->getTjtAtual()->getDest());
                 transp->desembarcarTodos();
                 transp->setDistPerc(0);
                 cout << "O transporte " << transp->getNome() << " chegou ao destino " << transp->getLocAtual()->getNome() << ".\n" << endl;
             } else {
                 transp->setDistPerc(novaDistPercorrida);
                 cout << "O transporte " << transp->getNome() << " percorreu " << novaDistPercorrida << " km na viagem.\n" << endl;
             } */
        }
    }
    cout << "---------------------\n"
         << endl;
}

void ControladorTransito::mostrarStatus()
{
    cout << "=== STATUS ATUAL DO SISTEMA ===\n"
         << endl;

    cout << "Cidades cadastradas:\n"
         << endl;
    for (Cidade *cid : cidades)
    {
        cout << "- " << cid->getNome() << endl;
    }

    cout << "\nPassageiros cadastrados:\n"
         << endl;
    for (Passageiro *pass : passageiros)
    {
        string locAtualPass = (pass->getLocAtual() != nullptr) ? pass->getLocAtual()->getNome() : "Em viagem";
        cout << "- " << pass->getNome() << " (Localizacao atual: " << locAtualPass << ")" << endl;
    }

    cout << "\nTransportes cadastrados:\n"
         << endl;
    for (Transporte *transp : transportes)
    {
        string locAtualTrans = (transp->getLocAtual() != nullptr) ? transp->getLocAtual()->getNome() : "Em viagem";
        cout << "- " << transp->getNome() << " (Localizacao atual: " << locAtualTrans << ")" << endl;
    }
    cout << "---------------------\n"
         << endl;
}

ControladorTransito::~ControladorTransito()
{
    for (Cidade *cid : cidades)
    {
        delete cid;
    }
    for (Passageiro *pass : passageiros)
    {
        delete pass;
    }
    for (Trajeto *tjt : trajetos)
    {
        delete tjt;
    }
    for (Transporte *transp : transportes)
    {
        delete transp;
    }
}

// Método vazio por enquanto
// string ControladorTransito::getNome() {
//  return this->nome;
// }