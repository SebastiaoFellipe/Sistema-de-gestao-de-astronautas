#ifndef SISTEMA_H
#define SISTEMA_H

#include "astronauta.h"
#include "voo.h"

void linhaDivisoria();
void cadastrarAstronauta(std::vector<Astronauta*>& lista_de_astronautas, std::string cpf, std::string nome, int idade);
void cadastrarVoo(std::vector<Voo*>& Lista_de_Voos, int codigo);
void adicionarAstronautaNoVoo(std::vector<Astronauta*>& Lista_de_Astronautas, std::string cpf, std::vector<Voo*>& Lista_de_Voos, int codigo);
void removerAstronautaDoVoo(std::vector<Astronauta*>& Lista_de_Astronautas, std::string cpf, std::vector<Voo*>& Lista_de_Voos, int codigo);
void lancarVoo(std::vector<Voo*>& Lista_de_Voos, int codigo);
void explodirVoo(std::vector<Voo*>& Lista_de_Voos, int codigo);
void finalizarVoo(std::vector<Voo*>& Lista_de_Voos, int codigo);
void listarVoos(std::vector<Voo*>& Lista_de_Voos);
void listarAstronautas(std::vector<Astronauta*>& lista_de_astronautas);
void listarAstronautasMortos(std::vector<Astronauta*>& Lista_de_Astronautas);
void mostrarOpcoes();

#endif