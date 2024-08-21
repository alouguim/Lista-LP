#include <iostream>
#include <vector>
#include <string>
#include "sapo.cpp"

using namespace std;

int main(){

    vector<Sapo> sapos;

    int escolha = 0;
    cout << "== Bem vindo ao gerenciador de corrida de sapos! ==" << endl;
    do{
        cout << "-----ESCOLHA UMA OPCAO-----" << endl;
        cout << "1 - Registrar novo sapo" << endl;
        cout << "2 - Customizar sapo" << endl;
        cout << "3 - Verificar placar" << endl;
        cout << "4 - Simular corrida" << endl;
        cout << "5 - Entrar em torneio" << endl;
        cout << "6 - Verificar sapo" << endl;
        cout << "7 - Sair\n";
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
            simularTorneio(sapos);
            break;
        case 6:
            verificarSapo(sapos);
            break;
        case 7:
            cout << "Saindo...";
            break;
        default:
            cout << "Opcao invalida!\n";
            break;
        }
    } while (escolha != 6);

    return 0;
    
}