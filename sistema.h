#ifndef SISTEMA_H
#define SISTEMA_H

#include "astronauta.h"
#include "voo.h"

void linhaDivisoria();
void CadastrarAstronauta(std::vector<astronauta*>& lista_de_astronautas, std::string cpf, std::string nome, int idade);
void listarAstronautas(std::vector<astronauta*>& lista_de_astronautas);

#endif