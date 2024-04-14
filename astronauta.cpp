#include "astronauta.h"

string astronauta::getCPF(){
    return cpf;
}
void astronauta::setCPF(string c){
    cpf = c;
}
string astronauta::getNome(){
    return nome;
}
void astronauta::setNome(string n){
    nome = n;
}
int astronauta::getIdade() {
    return idade;
}
void astronauta::setIdade(int i) {
    idade = i;
}