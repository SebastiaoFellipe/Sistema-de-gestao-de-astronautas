#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
using std::string;

class astronauta{
private:
    string cpf;
    string nome;
    int idade;

public:
    void setCPF(string cpf);
    string getCPF();
    void setNome(string nome);
    string getNome();
    void setIdade(int idade);
    int getIdade();
};

#endif