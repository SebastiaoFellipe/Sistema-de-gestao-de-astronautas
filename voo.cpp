#include <iostream>
#include "voo.h"

void voo::setCodigo(int c){
    codigo = c;
}
int voo::getCodigo(){
    return codigo;
}
void voo::adicionarAstronauta(astronauta* a){
    astronautas.push_back(a);
}
void voo::exibir() {
    std::cout << "Código do voo: " << codigo << std::endl;
    if (astronautas.empty()) {
        std::cout << "Nenhum astronauta está associado a este voo." << std::endl;
    } else {
        std::cout << "Astronautas associados ao voo:" << std::endl;
        for (auto astronauta : astronautas) {
            std::cout << "- " << astronauta->getNome() << std::endl;
        }
    }
}

