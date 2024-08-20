#include <iostream>
#include <vector>
#include <string>
#include "sapo.cpp"

using namespace std;

int main(){

    vector<Sapo> sapos;

    int escolha = 0;
    cout << "== Bem vindo ao gerenciador de corrida de sapos! ==\n";
    do{
        cout << "-----ESCOLHA UMA OPCAO-----\n";
        cout << "1 - Registrar novo sapo\n";
        cout << "2 - Customizar sapo\n";
        cout << "3 - Verificar placar\n";
        cout << "4 - Simular corrida\n";
        cout << "5 - Verificar sapo\n";
        cout << "6 - Sair\n";
        cin >> escolha;

        switch (escolha){
        case 1:
            registrarSapo(sapos);
            break;
        case 2:
            customizarSapo(sapos);
            break;
        case 3:
            verificarPlacar(sapos);
            break;
        case 4:
            simularCorrida(sapos);
            break;
        case 5:
            verificarSapo(sapos);
            break;
        case 6:
            cout << "Saindo...";
            break;
        default:
            cout << "Opcao invalida!\n";
            break;
        }
    } while (escolha != 6);

    return 0;
    
}