#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
#include "astronauta.h"

int main(){
    std::vector<astronauta*> ListaAstronautas;
    ListaAstronautas.push_back(new astronauta());
    ListaAstronautas[0]->setCPF("111.222.333-44");
    ListaAstronautas[0]->setNome("Sebastião");
    ListaAstronautas[0]->setIdade(20);
    cout << "Astronauta 01" << endl;
    cout << "CPF: " << ListaAstronautas[0]->getCPF() << endl;
    cout << "Nome: " << ListaAstronautas[0]->getNome() << endl;
    cout << "Idade: " << ListaAstronautas[0]->getIdade() << endl;
    return 0;
}