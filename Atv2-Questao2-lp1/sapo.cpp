#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

class Sapo {
private:
    string nome;
    string cor;
    int identificacao;
    int distancia;       //Distância do sapo na corrida
    int distanciaTotal;  //Distância total percorrida
    int qntPulos;
    int qntProvas;
    int qntVitorias;
    int qntDerrotas;
    int qntEmpates;
    int totalPulos;
    int distanciaPulo;   
    bool pularDuasVezes; //Indica se tem a modificação de pular duas vezes
    bool pernasMetalicas;//Indica se tem a modificação de pernas metalicas

public:
    static int distanciaTotalCorrida; //Distância total da corrida
    
    //Construtor da classe
    Sapo(string nome, string color, int id, int maxPulo) 
        : nome(nome), cor(color), identificacao(id), distancia(0), distanciaTotal(0),
          qntPulos(0), qntProvas(0), qntVitorias(0), qntDerrotas(0),
          qntEmpates(0), totalPulos(0), distanciaPulo(maxPulo), pularDuasVezes(false), pernasMetalicas(false)
    {}

    //Getters
    string getNome()const { return nome; }
    string getCor()const { return cor; }
    int getID()const { return identificacao; }
    int getDistanciaTotal()const { return distanciaTotal; }
    int getPulos()const { return qntPulos; }
    int getProvas()const { return qntProvas; }
    int getVitorias()const { return qntVitorias; }
    int getDerrotas()const { return qntDerrotas; }
    int getEmpates()const { return qntEmpates; }
    int getDistancia()const {return distancia;}
    int getTotalPulos()const { return totalPulos; }
    int getDistanciaPulo()const { return distanciaPulo; }
    bool getPularDuasVezes() const { return pularDuasVezes; }
    bool getPernasMetalicas() const { return pernasMetalicas;}

    //Setters
    void setNome(string novoNome) { nome = novoNome; }
    void setDistancia(int distancia) {distancia = distancia;}
    void setDistanciaTotal(int distanciaTotal) { distanciaTotal = distanciaTotal;}
    void setCor(string color) {cor = color;}
    void setPulos(int pulos) {qntPulos = pulos;}
    void setProvas(int provas) { qntProvas = provas;}
    void setVitorias(int vitorias) { qntVitorias = vitorias; }
    void setDerrotas(int derrotas) { qntDerrotas = derrotas; }
    void setEmpates(int empates) { qntEmpates = empates; }
    void setTotalPulos(int pulos) { totalPulos = pulos; }
    void setDistanciaPulo(int maxPulo) { distanciaPulo = maxPulo; }
    void setPularDuasVezes(bool ativar) { pularDuasVezes = ativar; }
    void setPernasMetalicas(bool ativar) { pernasMetalicas = ativar; }


    //Método estático para a categoria de peso do sapo
    static int definirCategoriaPeso(string categoriaPeso) {
        int maxPulo; //maxPulo é o tamanho de pulo máximo do sapo, cada categoria tem um maxPulo diferente
        if (categoriaPeso == "leve") {
            maxPulo = 15;
        } else if (categoriaPeso == "medio") {
            maxPulo = 12;
        } else if (categoriaPeso == "pesado") {
            maxPulo = 10;
        } else {     //A categoria padrão é médio.
            cout << "Erro na definicao da categoria! Definindo como Medio." << endl;
            categoriaPeso = "medio";
            maxPulo = 12;
        }
        return maxPulo;
    }

    void pular() {
        int pulo = rand() % distanciaPulo + 1;
        distancia += pulo; // Atualiza a distância atual do sapo
        distanciaTotal = distancia; // Atualiza a distância total acumulada
        qntPulos++;
        totalPulos++;

    if (pularDuasVezes) { //Caso tenha a modificação, realiza um segundo pulo
        pulo = rand() % distanciaPulo + 1;
        distancia += pulo;
        distanciaTotal = distancia;
        qntPulos++;
        totalPulos++;
    }
}

    void reset() { //Reseta os dados para a próxima corrida
        distancia= 0;
        qntPulos = 0;
    }

    void resetTorneio(){ //Reseta todas as informações para o torneio
        distancia= 0;
        qntPulos = 0;
        qntProvas = 0;
        qntVitorias = 0;
        qntDerrotas = 0;
        qntEmpates = 0;
        totalPulos = 0;
        distanciaTotal = 0;
    }

    void vitoria() { qntVitorias++; qntProvas++; }
    void derrota() { qntDerrotas++; qntProvas++; }
    void empates() { qntEmpates++; qntProvas++; }
};

int Sapo::distanciaTotalCorrida = 100;

void registrarSapo(vector<Sapo>& sapos) {
    string nome;
    string cor;
    int id;
    bool idValido = false;
    string categoriaPeso;

    cout << "Digite o nome do sapo: ";
    cin >> nome;
    cout << "Digite a cor do sapo: ";
    cin >> cor;
    cout << "Digite o id do sapo: ";
    while (!idValido){
        cin >> id;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Insira um numero inteiro." << endl; 
        }else{
            idValido = true;
        }

    }
    cout << "Digite a categoria de peso do sapo (Leve, Medio ou Pesado): ";
    cin >> categoriaPeso;
    transform(categoriaPeso.begin(), categoriaPeso.end(), categoriaPeso.begin(), ::tolower); //Converte tudo pra letras minúsculas

    int maxPulo = Sapo::definirCategoriaPeso(categoriaPeso);

    Sapo novoSapo(nome, cor, id, maxPulo); 
    sapos.push_back(novoSapo); //Armazena no vetor

    cout << "Sapo registrado com sucesso" << endl;
}

void customizarSapo(vector<Sapo>& sapos) {
    int id;
    cout << "Digite o ID do sapo: ";
    cin >> id;
    for (auto& sapo : sapos) {
        if (sapo.getID() == id) {
            int opcao;
            cout << "Escolha uma opcao para customizar o sapo:" << endl;
            cout << "1 - Alterar o nome do sapo" << endl;
            cout << "2 - Alterar a cor do sapo" << endl;
            cout << "3 - Adicionar Acelerador de Ritmo: O sapo pula duas vezes por vez, mas perde 5 de MaxPulo!" << endl;
            cout << "4 - Adicionar Pernas Metalicas: +2 em MaxPulo!" << endl;
            cout << "Digite sua opcao: ";
            cin >> opcao;

            switch (opcao) {
                case 1: {
                    string novoNome;
                    cout << "Digite o novo nome do sapo: ";
                    cin >> novoNome;
                    sapo.setNome(novoNome);
                    break;
                }
                case 2: {
                    string novaCor;
                    cout << "Digite a nova cor do sapo: ";
                    cin >> novaCor;
                    sapo.setCor(novaCor);
                    break;
                }
                case 3: {
                    if (sapo.getPularDuasVezes()) {
                        cout << "Sapo ja possui essa modificacao" << endl;
                    } else {
                        int novoMaxPulo = sapo.getDistanciaPulo() - 5;
                        if (novoMaxPulo < 0) novoMaxPulo = 0;
                        sapo.setDistanciaPulo(novoMaxPulo);
                        sapo.setPularDuasVezes(true);
                        cout << "Sapo agora pode pular duas vezes, mas o MaxPulo foi reduzido em 5." << endl;
                    }
                    break;
                }
                case 4: {
                    if (sapo.getPernasMetalicas()) {
                        cout << "Sapo ja possui essa modificacao" << endl;
                    } else {
                        int novoMaxPulo = sapo.getDistanciaPulo() + 2;
                        sapo.setDistanciaPulo(novoMaxPulo);
                        sapo.setPernasMetalicas(true);
                        cout << "MaxPulo do sapo foi aumentado em 2." << endl;
                    }
                    break;
                }
                default:
                    cout << "Opcao invalida!" << endl;
                    break;
            }
            return; 
        }
    }
    cout << "Sapo com ID " << id << " nao encontrado." << endl;
}

void verificarPlacar(const vector<Sapo>& sapos) {
    if (sapos.empty()) { //Precisa de pelo menos um sapo no vetor
        cout << "Erro: Nao ha sapos registrados para verificar o placar." << endl;
        return;
    }

    vector<Sapo> saposOrdenados = sapos;
    //Ordena por número de vitórias, empates e derrotas.
    sort(saposOrdenados.begin(), saposOrdenados.end(), [](const Sapo& a, const Sapo& b) {
        if (a.getVitorias() != b.getVitorias()) {
            return a.getVitorias() > b.getVitorias();
        }
        if (a.getEmpates() != b.getEmpates()) {
            return a.getEmpates() > b.getEmpates();
        }
        return a.getDerrotas() < b.getDerrotas();
    });

    cout << "Placar dos Sapos:" << endl;
    cout << "| Nome               | Vitorias | Derrotas | Empates |" << endl;
    cout << "|--------------------|----------|----------|---------|" << endl;
    for (const auto& sapo : saposOrdenados) {
        cout << "| " << left << setw(18) << sapo.getNome() 
             << " | " << setw(8) << sapo.getVitorias() 
             << " | " << setw(8) << sapo.getDerrotas() 
             << " | " << setw(7) << sapo.getEmpates() << " |" << endl;
    }
    cout << "|--------------------|----------|----------|---------|" << endl;

    return;
}

void verificarSapo(const vector<Sapo>& sapos) {
    if (sapos.empty()) {
        cout << "Erro: Nao ha sapos registrados para verificar." << endl;
        return;
    }

    int id;
    cout << "Digite o ID do sapo que deseja verificar: ";
    cin >> id;

    for (const auto& sapo : sapos) {
        if (sapo.getID() == id) {
            cout << "Informaçoes do sapo com ID " << id << ":" << endl;
            cout << "| " << left << setw(20) << "Nome" 
                 << "| " << setw(20) << sapo.getNome() << " |" << endl;
            cout << "| " << setw(20) << "Cor"
                 << "| " << setw(20) << sapo.getCor() << " |" << endl;
            cout << "| " << setw(20) << "Distancia Total"
                 << "| " << setw(20) << (to_string(sapo.getDistanciaTotal()) + " centimetros") << " |" << endl;
            cout << "| " << setw(20) << "Quantidade de Provas"
                 << "| " << setw(20) << sapo.getProvas() << " |" << endl;
            cout << "| " << setw(20) << "Vitorias"
                 << "| " << setw(20) << sapo.getVitorias() << " |" << endl;
            cout << "| " << setw(20) << "Derrotas"
                 << "| " << setw(20) << sapo.getDerrotas() << " |" << endl;
            cout << "| " << setw(20) << "Empates"
                 << "| " << setw(20) << sapo.getEmpates() << " |" << endl;
            cout << "| " << setw(20) << "Total de Pulos"
                 << "| " << setw(20) << sapo.getTotalPulos() << " |" << endl;
            cout << "| " << setw(20) << "MaxPulo"
                 << "| " << setw(20) << (to_string(sapo.getDistanciaPulo()) + " centimetros") << " |" << endl;
            return;
        }
    }

    cout << "Sapo com ID " << id << " nao encontrado." << endl;
}

//Interface que mostra o percurso da corrida
void exibirPercurso(const vector<Sapo>& sapos) {
    for (const auto& sapo : sapos) {
        int posicao = sapo.getDistancia() * 10 / Sapo::distanciaTotalCorrida;
        if (posicao < 0) posicao = 0;
        if (posicao > 10) posicao = 10;
        cout << string(posicao, '-') << "o" << string(10 - posicao, '-') << "|" << endl;
    }
    cout << endl;
}

//Inicia a simulação da corrida
void simularCorrida(vector<Sapo>& sapos) {
    if (sapos.size() < 2) {
        cout << "Erro: Sao necessarios pelo menos 2 sapos para realizar uma corrida." << endl;
        return;
    }

    bool corridaEmAndamento = true;
    vector<Sapo*> vencedores;

    cout << "A corrida comecou!" << endl;
    while (corridaEmAndamento) {
        for (auto& sapo : sapos) {
            sapo.pular();
            if (sapo.getDistancia() >= Sapo::distanciaTotalCorrida) { //Continua enquanto a distãncia do sapo não igualar ou superar a distancia total da corrida.
                vencedores.push_back(&sapo);
                corridaEmAndamento = false;
            }
        }
        exibirPercurso(sapos); 
        cout << "--------------------" << endl;
    }

    if (!vencedores.empty()) {
        cout << "Temos um vencedor!" << endl;
        Sapo* vencedor = vencedores[0];
        for (auto& sapo : sapos) {
            if (sapo.getDistancia() >= Sapo::distanciaTotalCorrida) {
                if (&sapo == vencedor) {
                    sapo.vitoria();
                    cout << "Sapo " << sapo.getNome() << " venceu a corrida com " << sapo.getPulos() << " pulos!" << endl;
                } else {
                    sapo.empates();
                    cout << "Sapo " << sapo.getNome() << " empatou com " << sapo.getPulos() << " pulos!" << endl;
                }
            } else {
                sapo.derrota();
                cout << "Sapo " << sapo.getNome() << " foi derrotado com " << sapo.getPulos() << " pulos." << endl;
            }
            sapo.reset();
        }
    }

    cout << "A corrida terminou!" << endl;
}

//Inicializa o torneio
void simularTorneio(vector<Sapo>& sapos) {

    if (sapos.size() < 2) {
        cout << "Erro: Sao necessarios pelo menos 2 sapos para realizar um torneio." << endl;
        return;
    }
    // Reseta todos os sapos no início do torneio
    for (auto& sapo : sapos) {
        sapo.resetTorneio();
    }

    int i; // i é o número de corridas que o torneio terá
    cout << "Insira quantas corridas terao o torneio: ";
    cin >> i;

    int corrida = 0; //corrida é o número atual da corrida

    int escolhaTorneio = 0;
    cout << "=== Torneio Iniciado! ===" << endl;
    do {
        cout << "1 - Iniciar corrida" << endl;
        cout << "2 - Verificar Sapos" << endl;
        cout << "3 - Verificar placar" << endl;
        cout << "4 - Desistir do torneio" << endl;
        cout << "Digite sua escolha: ";
        cin >> escolhaTorneio;

        switch (escolhaTorneio) {
            case 1:
                if (corrida < i) {
                    cout << "=== Corrida " << (corrida + 1) << " ===" << endl;
                    simularCorrida(sapos);
                    corrida++;
                } else {
                    cout << "O máximo de corridas já foi atingido." << endl;
                }

                if (corrida == i) {
                    cout << "=== Resultado Final ===" << endl;
                    verificarPlacar(sapos);
                }
                break;
                break;
            case 2: {
                cout << "Informacoes dos Sapos:" << endl;
                cout << "| ID | Nome               | Cor            | Vitorias | Derrotas |" << endl;
                cout << "|----|--------------------|----------------|----------|----------|" << endl;
                for (const auto& sapo : sapos) {
                    cout << "| " << setw(2) << sapo.getID()
                         << " | " << setw(18) << sapo.getNome()
                         << " | " << setw(14) << sapo.getCor()
                         << " | " << setw(8) << sapo.getVitorias()
                         << " | " << setw(8) << sapo.getDerrotas()
                         << " |" << endl;
                }
                cout << "|----|--------------------|----------------|----------|----------|" << endl;
                break;
            }
            case 3:
                verificarPlacar(sapos);
                break;
            case 4:
                cout << "Abandonando torneio...";
                corrida = i;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    } while (corrida < i);

    cout << "=== Torneio Encerrado! ===" << endl;
}