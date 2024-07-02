#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include "voo.h"
#include <string>
#include <vector>

class voo;

class astronauta{
private:
    std::string cpf;
    std::string nome;
    int idade;
    bool vivo;
    std::vector<voo*> voos_que_participou;

public:
    astronauta(std::string cpf, std::string nome, int idade);
    std::string getCPF();
    std::string getNome();
    int getIdade();
    bool getVivo();
};

#endif