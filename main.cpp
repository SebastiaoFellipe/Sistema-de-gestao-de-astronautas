#include "sistema.h"
#include "astronauta.h"
#include "voo.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    std::vector<astronauta*> lista_de_astronautas;
    std::vector<voo*> lista_de_voos;
    lista_de_voos.push_back(new voo(13));
    cout << lista_de_voos[0]->getCodigo() << endl;
    cout << lista_de_voos[0]->getStatus() << endl;
    CadastrarAstronauta(lista_de_astronautas, "123.456.789-00", "Sebastião Fellipe Pinto Lopes", 20);
    CadastrarAstronauta(lista_de_astronautas, "123.456.789-00", "Sebastião Fellipe Pinto Lopes", 20);
    CadastrarAstronauta(lista_de_astronautas, "123.456.789-00", "Sebastião Fellipe Pinto Lopes", 20);
    CadastrarAstronauta(lista_de_astronautas, "123.456.789-00", "Sebastião Fellipe Pinto Lopes", 20);
    CadastrarAstronauta(lista_de_astronautas, "123.456.789-00", "Sebastião Fellipe Pinto Lopes", 20);

    listarAstronautas(lista_de_astronautas);
    return 0;
}
