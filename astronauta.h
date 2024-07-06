#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include "voo.h"
#include <string>
#include <vector>

class Voo;

class Astronauta{
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool vivo;
    bool disponivel;
    std::vector<Voo*> voos_que_participou;

public:
    Astronauta(std::string cpf, std::string nome, int idade);
    std::string getCPF();
    std::string getNome();
    int getIdade();
    bool getVivo();
    void matarAstronauta();
    bool getDisponivel();
    void tornarDisponivel();
    void tornarIndisponivel();
    void adicionarVooAoAstronauta(Voo* voo);
    std::vector<Voo*> getVoosQueParticipou();
};

#endif