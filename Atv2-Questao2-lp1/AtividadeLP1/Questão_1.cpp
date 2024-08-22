/**********************************************************************************************************************
string menu{} será o menu que é mostrado inicialmente para o usuário.

main está a escolha de opções do usuário semelhante ao ultimo projeto

QUESTÃO 1-A : Está no arquivo Calculadora.cpp
QUESTÃO 1-B : Está neste arquivo
1-A : Explicação
Básicamente polimorfismo será a capacidade do objeto de "ter varias formas", um objeto geometrico por exemplo, se tornando cubo ou esfera.

1-B : Explicação:
    Métodos virtuais em c++ usam ponteiro para função, ou ponteiro para método, para que o polimorfismo dinamico seja aplicado.
    Ao chamar objetos que possuem métodos virtuais o compilador tem um ponteiro já criado para aponta para a classe que está sendo chamada.
    O método calcular_area/calcular_volume usa o pronteiro vptr para acessar o método correto. (Ou seja, Chama os metodos calc_area/calc_vol baseado no tipo real do objeto).
    Que por sua vez está listado em vtable (contém todos os métodos virtuais e seus ponteiros).
***********************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "Calculadora.cpp"

using namespace std;

string menu(){
    cout << "Escolha uma das funcoes abaixo: " << endl;
    cout << "1 - Calculador de area e volume de Piramide" << endl;
    cout << "2 - Calculador de area e volume de Cubo" << endl;
    cout << "3 - Calculador de area e volume de Paralelepipedo" << endl;
    cout << "4 - Calculador de area e volume de Esfera" << endl;
    cout << "5 - Sair\n" << endl;
    
    return "";
}

int main(){ 
    char input;
    double valor1, valor2, valor3;

    cout << "Bem vindo a Calculadora Magica de Formas Geometricas!" << endl;
    cout << "Disclaimer: considere todas as medidas entregues como centimetros." << endl;

    do {
        menu();

        cin >> input;

        switch (input)
        {
        case '1':
            cout << "Digite o valor da base: ";
            cin >> valor1;
            cout << "Digite o valor da Altura: ";
            cin >> valor2;
            
            {
            CalcPiramide cpira = CalcPiramide(valor1, valor2); 

            cout << "\nA area da piramide: " << calcular_area(&cpira) << "cm quadrados.\n" << "O volume da piramide: " << calcular_volume(&cpira); 
            cout << "cm cubicos.\n" << endl;
            }
            break;
        case '2':
            cout << "Digite o valor da Aresta: ";
            cin >> valor1;
            
            { 
            CalcCubo cc = CalcCubo(valor1); 

            cout << "\nA area do Cubo: " << calcular_area(&cc) << "cm quadrados.\n" << "O volume do Cubo: " << calcular_volume(&cc); 
            cout << "cm cubicos.\n" << endl; 
            }
            break;
        case '3':
            cout << "Digite o valor da Primeira Aresta: ";
            cin >> valor1;
            cout << "Digite o valor da Segunda Aresta: ";
            cin >> valor2;
            cout << "Digite o valor da Terceira Aresta: ";
            cin >> valor3;
            
            {
            CalcParalelepipedo cpara = CalcParalelepipedo(valor1, valor2, valor3); 
            cout << "\nA area do Paralelepipedo: " << calcular_area(&cpara) << "cm quadrados.\n" << "O volume do Paralelepipedo: " << calcular_volume(&cpara); 
            cout << "cm cubicos.\n" << endl;
            }
            break;
        case '4':
            cout << "Digite o valor do Diametro: ";
            cin >> valor1;
            
            
            {
            CalcEsfera ce = CalcEsfera(valor1); 
            cout << "\nA area da Esfera: " << calcular_area(&ce) << "cm quadrados.\n" << "O volume da Esfera: " << calcular_volume(&ce); 
            cout << "cm cubicos.\n" << endl;
            }
            break;
        case '5':
            break;
        default:
            cout << "Opcao invalida, tente um dos numeros da tabela.\n";
            break;  
        }


    } while (input != '5');

    cout << "Obrigado por utilizar a Calculadora Magica de Formas Geometricas!";

    return 0;
}