# 🚌 Sistema Controlador de Viagens (Trabalho Final LP1)

Um sistema interativo de linha de comando (CLI) desenvolvido em **C++** para o gerenciamento e simulação de rotas de transporte, controle de passageiros e viagens. O projeto aplica conceitos de Programação Orientada a Objetos (POO), persistência de dados em arquivos e algoritmos de grafos (Dijkstra) para calcular as melhores rotas.

Desenvolvido por **Davi Summer, Marcos Paulo e Artur Medeiros**.

---

## ✨ Funcionalidades

* **CRUD Completo:** Cadastro de Cidades, Trajetos (Terrestres e Aquáticos), Transportes e Passageiros.
* **Simulação de Viagens:** Embarque de passageiros e progressão baseada no tempo (horas simuladas).
* **Algoritmo de Dijkstra:** Cálculo automático da rota mais curta e compatível entre duas cidades.
* **Persistência de Dados:** O sistema salva e carrega automaticamente o estado das viagens, entidades e localizações em arquivos de texto (`.txt`), permitindo pausar e continuar a simulação sem perda de dados.
* **Relatórios:** Geração de relatórios detalhados do status das frotas, histórico de viagens e passageiros.

---

## 🚀 Como Compilar e Executar

O projeto foi estruturado separando os arquivos de cabeçalho (`.h`) na pasta `classes/`, as implementações dos métodos (`.cpp`) na pasta `funcoes/` e o arquivo de execução principal (`main.cpp`) na raiz do projeto.

Para compilar, você precisará do compilador **GCC (g++)** instalado no seu sistema.

### 🐧 Linux e 🍏 macOS

Abra o terminal na pasta raiz do projeto (`TRABALHO-FINAL-LP1`) e execute os seguintes comandos:

**1. Compilação:**
```bash
g++ main.cpp funcoes/*.cpp -I classes -o sistema

2. Execução:
./sistema

Windows

Certifique-se de ter o compilador MinGW configurado nas variáveis de ambiente do sistema. Abra o Prompt de Comando ou PowerShell na pasta raiz do projeto:

1. Compilação:
g++ main.cpp funcoes\*.cpp -I classes -o sistema.exe

2. Execução:
sistema.exe

 Como Utilizar o Sistema
Ao executar o programa, você será recebido por um prompt perguntando se deseja carregar os dados da última sessão.

O menu principal possui 13 opções, divididas em três categorias principais:

1. Cadastros (Opções 1 a 4)
Antes de iniciar qualquer viagem, o ecossistema deve ser criado:

Cidades: Os "nós" do nosso mapa.

Trajetos: As "arestas" do mapa. Requer uma cidade de origem, destino e tipo de transporte (T para Terrestre, etc).

Transportes: Veículos com capacidades limitadas, velocidade específica e regras de descanso.

Passageiros: Pessoas associadas a uma cidade inicial.

2. Simulação e Lógica (Opções 5 a 7)
[5] Iniciar Viagem: Vincula passageiros e um transporte a um trajeto válido. O sistema valida as capacidades.

[6] Avançar Tempo: Simula a passagem das horas. É aqui que a mágica acontece e a distância percorrida avança.

[7] Calcular Melhor Trajeto (Dijkstra): Informando a origem, destino e tipo de transporte, o sistema diz a melhor rota.

3. Relatórios e Saída (Opções 8 a 12 e 0)
[8-12]: Exibe no console tudo o que está registrado na memória (lista de cidades, veículos, histórico).

[0] Sair do Sistema: Ao encerrar, o sistema perguntará se você deseja salvar as alterações antes de fechar.

 Tecnologias Utilizadas
Linguagem: C++ Standard (C++11/C++14 ou superior).

Estruturas de Dados: std::vector, std::map, std::priority_queue, std::string.

Manipulação de Arquivos: std::ifstream, std::ofstream, std::stringstream.