#include "astronauta.h"

astronauta::astronauta(std::string cpf, std::string nome, int idade){
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
}
std::string astronauta::getCPF(){
    return cpf;
}
std::string astronauta::getNome(){
    return nome;
}
int astronauta::getIdade() {
    return idade;
}
bool astronauta::getVivo(){
    return vivo;
}