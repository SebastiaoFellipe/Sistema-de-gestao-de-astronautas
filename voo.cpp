#include "voo.h"

#include <iostream>

voo::voo(int codigo){
    this->codigo = codigo;
    setStatus("PLANEJAMENTO");
}
int voo::getCodigo(){
    return codigo;
}
void voo::setStatus(std::string s){
    status = s;
}
std::string voo::getStatus(){
    if (status == "PLANEJAMENTO") {
        return "Planejamento";
    } else if (status == "EM_CURSO") {
        return "Em curso";
    } else if (status == "FINALIZADO_COM_SUCESSO") {
        return "Finalizado com sucesso";
    } else if (status == "FINALIZADO_COM_FALHA") {
        return "Finalizado com falha";
    } else {
        return "Status desconhecido";
    }
}
void voo::adicionarAstronauta(astronauta* a){
    lista_de_passageiros.push_back(a);
}
void voo::exibir() {
    std::cout << "Código do voo: " << codigo << std::endl;
    if (lista_de_passageiros.empty()) {
        std::cout << "Nenhum astronauta está associado a este voo." << std::endl;
    } else {
        std::cout << "Astronautas associados ao voo:" << std::endl;
        for (auto astronauta : lista_de_passageiros) {
            std::cout << "- " << astronauta->getNome() << std::endl;
        }
    }
}

