#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
#include "astronauta.h"
#include "voo.h"

int main(){
    std::vector<astronauta*> ListaAstronautas;
    std::vector<voo*> ListaVoos;
    ListaVoos.push_back(new voo());
    ListaVoos[0]->setCodigo(13);
    ListaAstronautas.push_back(new astronauta());
    ListaVoos[0]->adicionarAstronauta(ListaAstronautas[0]);
    ListaAstronautas[0]->setCPF("111.222.333-44");
    ListaAstronautas[0]->setNome("Sebastião");
    ListaAstronautas[0]->setIdade(20);
    cout << "Astronauta 01" << endl;
    cout << "CPF: " << ListaAstronautas[0]->getCPF() << endl;
    cout << "Nome: " << ListaAstronautas[0]->getNome() << endl;
    cout << "Idade: " << ListaAstronautas[0]->getIdade() << endl;
    ListaVoos[0]->exibir();
    return 0;
}