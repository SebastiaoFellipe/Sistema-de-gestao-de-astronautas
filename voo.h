#ifndef VOO_H
#define VOO_H

#include "astronauta.h"
#include <vector>
#include <string>

class Astronauta;

class Voo{
private:
    int codigo;
    std::string status;
    std::vector<Astronauta*> lista_de_passageiros;

public:
    Voo(int codigo);
    int getCodigo();
    void setStatus(std::string novoStatus);
    std::string getStatus();
    std::vector<Astronauta*> getListaPassageiros();
    void removerAstronautaListaPassageiros(Astronauta* a);
    void adicionarAstronauta(Astronauta* astronauta);
    void exibir();
};

#endif
