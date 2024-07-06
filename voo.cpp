#include "voo.h"

#include <iostream>
#include <algorithm>

Voo::Voo(int codigo) : codigo(codigo), status("PLANEJAMENTO") {}

int Voo::getCodigo(){
    return codigo;
}
void Voo::setStatus(std::string s){
    status = s;
}
std::vector<Astronauta*> Voo::getListaPassageiros(){
    return lista_de_passageiros;
}
void Voo::removerAstronautaListaPassageiros(Astronauta* a){
    auto it = std::find(lista_de_passageiros.begin(), lista_de_passageiros.end(), a);
    if (it != lista_de_passageiros.end()) {
        lista_de_passageiros.erase(it);
    }
}
std::string Voo::getStatus(){
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
void Voo::adicionarAstronauta(Astronauta* a){
    lista_de_passageiros.push_back(a);
}
void Voo::exibir() {
    std::cout << "Código do voo: " << codigo << std::endl;
    std::cout << "Status do voo: " << getStatus() << std::endl;
    if (lista_de_passageiros.empty()) {
        std::cout << "Nenhum astronauta está associado a este voo." << std::endl;
    } else {
        std::cout << "Astronautas associados ao voo:" << std::endl;
        for (size_t i = 0; i < lista_de_passageiros.size(); i++){
            if (i==lista_de_passageiros.size()-1){
                std::cout << lista_de_passageiros[i]->getNome() << std::endl;
            } else {
                std::cout << lista_de_passageiros[i]->getNome() << ", ";
            }
            
        }
        
    }
}

