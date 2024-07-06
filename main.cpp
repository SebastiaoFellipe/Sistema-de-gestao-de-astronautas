#include "sistema.h"
#include "astronauta.h"
#include "voo.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    std::vector<Astronauta*> lista_de_astronautas;
    std::vector<Voo*> lista_de_voos;
    
    cout << "Bem-vindo ao sistema de gestão de astronautas!" << endl;
    int opcao;
    do {
        cout << endl;
        mostrarOpcoes();
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cout << endl;
        linhaDivisoria();

        // variaveis para cadastro de astronautas
        std::string cpf;
        std::string nome;
        int idade;
        // variaveis para cadastro de voos
        int codigo;

        switch (opcao) {
            case 1:
                cout << "Cadastrar Astronauta" << endl;
                cout << "Digite os dados do astronauta" << endl; 
                cout << "CPF: ";
                cin >> cpf;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Idade: ";
                cin >> idade;
                cadastrarAstronauta(lista_de_astronautas, cpf, nome, idade);
                break;
            case 2:
                cout << "Cadastrar Voo" << endl;
                cout << "Digite o código do voo: "; 
                cin >> codigo;
                cadastrarVoo(lista_de_voos, codigo);
                break;
            case 3:
                cout << "Adicionar Astronauta no Voo" << endl;
                cout << "Digite o CPF do astronauta: ";
                cin >> cpf;
                cout << "Digite o código do voo: ";
                cin >> codigo;
                adicionarAstronautaNoVoo(lista_de_astronautas, cpf, lista_de_voos, codigo);
                break;
            case 4:
                cout << "Remover Astronauta do Voo" << endl;
                cout << "Digite o CPF do astronauta: ";
                cin >> cpf;
                cout << "Digite o código do voo: ";
                cin >> codigo;
                removerAstronautaDoVoo(lista_de_astronautas, cpf, lista_de_voos, codigo);
                break;
            case 5:
                cout << "Lançar Voo" << endl;
                cout << "Digite o código do voo para ser lançado: "; 
                cin >> codigo;
                lancarVoo(lista_de_voos, codigo);
                break;
            case 6:
                cout << "Explodir Voo" << endl;
                cout << "Digite o código do voo para ser explodido: "; 
                cin >> codigo;
                explodirVoo(lista_de_voos, codigo);
                break;
            case 7:
                cout << "Finalizar Voo" << endl;
                cout << "Digite o código do voo para ser finalizado: "; 
                cin >> codigo;
                finalizarVoo(lista_de_voos, codigo);
                break;
            case 8:
                listarVoos(lista_de_voos);
                break;
            case 9:
                listarAstronautas(lista_de_astronautas);
                break;
            case 10:
                listarAstronautasMortos(lista_de_astronautas);
                break;
            case 11:
                cout << "Obrigado por usar nosso sistema, volte sempre!" << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 11);
    
    // liberar a memoria
    for (auto& a : lista_de_astronautas) {
        delete a;
    }
    for (auto& v : lista_de_voos) {
        delete v;
    }

    return 0;
}