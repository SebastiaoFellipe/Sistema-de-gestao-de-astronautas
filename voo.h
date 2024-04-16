#ifndef VOO_H
#define VOO_H

#include "astronauta.h"
#include <vector>

class voo{
private:
    int codigo;
    std::vector<astronauta*> astronautas;

public:
    void setCodigo(int codigo);
    int getCodigo();
    void adicionarAstronauta(astronauta* astronauta);
    void exibir();
};

#endif
