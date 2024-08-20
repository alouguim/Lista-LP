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
    int distancia;
    int distanciaTotal;
    int qntPulos;
    int qntProvas;
    int qntVitorias;
    int qntDerrotas;
    int qntEmpates;
    int totalPulos;
    int distanciaPulo;

public:
    static int distanciaTotalCorrida; 

    Sapo(string nome, string color, int id, int maxPulo) 
        : nome(nome), cor(color), identificacao(id), distancia(0), distanciaTotal(0),
          qntPulos(0), qntProvas(0), qntVitorias(0), qntDerrotas(0),
          qntEmpates(0), totalPulos(0), distanciaPulo(maxPulo) 
    {}

    string getNome()const { return nome; }
    string getCor()const { return cor; }
    int getID()const { return identificacao; }
    int getDistanciaTotal()const { return distanciaTotal; }
    int getPulos()const { return qntPulos; }
    int getProvas()const { return qntProvas; }
    int getVitorias()const { return qntVitorias; }
    int getDerrotas()const { return qntDerrotas; }
    int getEmpates()const { return qntEmpates; }
    int getTotalPulos()const { return totalPulos; }
    int getDistanciaPulo()const { return distanciaPulo; }

    void setNome(string novoNome) { nome = novoNome; }
    void setDistanciaTotal(int distancia) { distanciaTotal = distancia; }
    void setCor(string color) { cor = color; }
    void setPulos(int pulos) { qntPulos = pulos; }
    void setProvas(int provas) { qntProvas = provas; }
    void setVitorias(int vitorias) { qntVitorias = vitorias; }
    void setDerrotas(int derrotas) { qntDerrotas = derrotas; }
    void setEmpates(int empates) { qntEmpates = empates; }
    void setTotalPulos(int pulos) { totalPulos = pulos; }
    void setDistanciaPulo(int maxPulo) { distanciaPulo = maxPulo; }

    static int definirCategoriaPeso(string categoriaPeso) {
        int maxPulo;
        if (categoriaPeso == "Leve") {
            maxPulo = 15;
        } else if (categoriaPeso == "Medio") {
            maxPulo = 12;
        } else if (categoriaPeso == "Pesado") {
            maxPulo = 10;
        } else {
            cout << "Erro na definição da categoria! Definindo como Medio." << endl;
            categoriaPeso = "Medio";
            maxPulo = 12;
        }
        return maxPulo;
    }

    void pular() {
        int pulo = rand() % distanciaPulo + 1;
        distanciaTotal += pulo;
        qntPulos++;
        totalPulos++;
    }

    void reset() {
        distancia= 0;
        qntPulos = 0;
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
    string categoriaPeso;

    cout << "Digite o nome do sapo: ";
    cin >> nome;
    cout << "Digite a cor do sapo: ";
    cin >> cor;
    cout << "Insira o id do sapo: ";
    cin >> id;
    cout << "Insira a categoria de peso do sapo (Leve, Medio ou Pesado): ";
    cin >> categoriaPeso;

    int maxPulo = Sapo::definirCategoriaPeso(categoriaPeso);

    Sapo novoSapo(nome, cor, id, maxPulo);
    sapos.push_back(novoSapo);

    cout << "Sapo registrado com sucesso" << endl;
}

void customizarSapo(vector<Sapo>& sapos) {
    int id;
    cout << "Digite o ID do sapo: ";
    cin >> id;
    for (auto& sapo : sapos) {
        if (sapo.getID() == id) {
            int opcao;
            cout << "Escolha uma opção para customizar o sapo:" << endl;
            cout << "1 - Alterar o nome do sapo" << endl;
            cout << "2 - Alterar a cor do sapo" << endl;
            cout << "3 - Adicionar Acelerador de Ritmo: O sapo pula duas vezes por vez, mas perde 5 de distância de pulo máxima!" << endl;
            cout << "4 - Adicionar Pernas Metálicas: +2 na distância de pulo máxima!" << endl;
            cout << "Digite sua opção: ";
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
                    int novoMaxPulo = sapo.getDistanciaPulo() - 5;
                    if (novoMaxPulo < 0) novoMaxPulo = 0; 
                    sapo.setDistanciaPulo(novoMaxPulo);
                    cout << "Sapo agora pode pular duas vezes, mas o maxPulo foi reduzido em 5." << endl;
                    break;
                }
                case 4: {
                    int novoMaxPulo = sapo.getDistanciaPulo() + 2;
                    sapo.setDistanciaPulo(novoMaxPulo);
                    cout << "MaxPulo do sapo foi aumentado em 2." << endl;
                    break;
                }
                default:
                    cout << "Opção inválida!" << endl;
                    break;
            }
        }
    }
    cout << "Sapo com ID " << id << " não encontrado." << endl;
}

void verificarPlacar(const vector<Sapo>& sapos) {
    if (sapos.empty()) {
        cout << "Erro: Não há sapos registrados para verificar o placar." << endl;
        return;
    }
    vector<Sapo> saposOrdenados = sapos;

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
}

void verificarSapo(const vector<Sapo>& sapos) {
    if (sapos.empty()) {
        cout << "Erro: Não há sapos registrados para verificar." << endl;
        return;
    }

    int id;
    cout << "Digite o ID do sapo que deseja verificar: ";
    cin >> id;

    for (const auto& sapo : sapos) {
        if (sapo.getID() == id) {
            cout << "Informações do sapo com ID " << id << ":" << endl;
            cout << "Nome: " << sapo.getNome() << endl;
            cout << "Cor: " << sapo.getCor() << endl;
            cout << "Distância Total Percorrida: " << sapo.getDistanciaTotal() << endl;
            cout << "Quantidade de Provas: " << sapo.getProvas() << endl;
            cout << "Quantidade de Vitórias: " << sapo.getVitorias() << endl;
            cout << "Quantidade de Derrotas: " << sapo.getDerrotas() << endl;
            cout << "Quantidade de Empates: " << sapo.getEmpates() << endl;
            cout << "Total de Pulos: " << sapo.getTotalPulos() << endl;
            cout << "Distância Máxima de Pulo: " << sapo.getDistanciaPulo() << endl;
            return;
        }
    }

    cout << "Sapo com ID " << id << " não encontrado." << endl;
}