#include "astronauta.h"
#include <algorithm>

Astronauta::Astronauta(std::string cpf, std::string nome, int idade) : cpf(cpf), nome(nome), idade(idade), vivo(true), disponivel(true) {}

std::string Astronauta::getCPF(){
    return cpf;
}
std::string Astronauta::getNome(){
    return nome;
}
int Astronauta::getIdade() {
    return idade;
}
bool Astronauta::getVivo(){
    return vivo;
}
void Astronauta::matarAstronauta(){
    vivo = false;
}
bool Astronauta::getDisponivel(){
    return disponivel;
}
void Astronauta::tornarDisponivel(){
    disponivel = true;
}
void Astronauta::tornarIndisponivel(){
    disponivel = false;
}
void Astronauta::adicionarVooAoAstronauta(Voo* voo) {
    if (std::find(voos_que_participou.begin(), voos_que_participou.end(), voo)==voos_que_participou.end()) {
        voos_que_participou.push_back(voo);
    }
}
std::vector<Voo*> Astronauta::getVoosQueParticipou() {
        return voos_que_participou;
    }