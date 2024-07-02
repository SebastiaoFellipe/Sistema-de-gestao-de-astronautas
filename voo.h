#ifndef VOO_H
#define VOO_H

#include "astronauta.h"
#include <vector>
#include <string>

class astronauta;

class voo{
private:
    int codigo;
    std::string status;
    std::vector<astronauta*> lista_de_passageiros;

public:
    voo(int codigo);
    int getCodigo();
    void setStatus(std::string novoStatus);
    std::string getStatus();
    void adicionarAstronauta(astronauta* astronauta);
    void exibir();
};

#endif
