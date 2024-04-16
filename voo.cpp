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
    // Exibe o código do voo
    std::cout << "Código do voo: " << codigo << std::endl;

    // Verifica se há astronautas associados ao voo
    if (astronautas.empty()) {
        std::cout << "Nenhum astronauta está associado a este voo." << std::endl;
    } else {
        std::cout << "Astronautas associados ao voo:" << std::endl;
        // Itera sobre a lista de astronautas e exibe suas informações
        for (auto astronauta : astronautas) {
            std::cout << "- " << astronauta->getNome() << std::endl; // Supondo que existe um método getNome() na classe Astronauta
            // Você pode exibir outras informações do astronauta aqui, se necessário
        }
    }
}

