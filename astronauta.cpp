#include "astronauta.h"

void astronauta::setCPF(string c){
    cpf = c;
}
string astronauta::getCPF(){
    return cpf;
}
void astronauta::setNome(string n){
    nome = n;
}
string astronauta::getNome(){
    return nome;
}
void astronauta::setIdade(int i) {
    idade = i;
}
int astronauta::getIdade() {
    return idade;
}