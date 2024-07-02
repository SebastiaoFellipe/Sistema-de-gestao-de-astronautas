#include "sistema.h"
#include "astronauta.h"
#include "voo.h"

#include <iostream>
#include <iomanip>
using std::cin; 
using std::cout;
using std::endl;

void linhaDivisoria(){
    for (int i = 0; i < 72; i++){
        cout << "-";
    } cout << endl;
}

void CadastrarAstronauta(std::vector<astronauta*>& Lista_de_Astronautas, std::string cpf, std::string nome, int idade){
    Lista_de_Astronautas.push_back(new astronauta(cpf, nome, idade));
}

void listarAstronautas(std::vector<astronauta*>& Lista_de_Astronautas){
    cout << std::setw(44) << "Lista de Astronautas" << endl;
    linhaDivisoria();
    cout << std::left << std::setw(16) << "CPF" << std::setw(50) << "|Nome" << "|Idade" << endl;
    linhaDivisoria();
    int countAstronautas = 0;
    for (auto astronauta : Lista_de_Astronautas) {
        cout << std::setw(16) << astronauta->getCPF() << "|" << std::setw(50) << astronauta->getNome() << "|" << astronauta->getIdade() << endl;
        countAstronautas++;
    }
    if (countAstronautas==0){
        cout << "Total: " << countAstronautas << endl;
    } else {
        linhaDivisoria();
        cout << "Total: " << countAstronautas << endl;
    }
}
