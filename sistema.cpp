#include "sistema.h"
#include "astronauta.h"
#include "voo.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using std::cin; 
using std::cout;
using std::endl;

void linhaDivisoria(){
    for (int i = 0; i < 72; i++){
        cout << "-";
    } cout << endl;
}

void cadastrarAstronauta(std::vector<Astronauta*>& Lista_de_Astronautas, std::string cpf, std::string nome, int idade){
    for (const auto& a : Lista_de_Astronautas) {
        if (a->getCPF() == cpf) {
            cout << "Astronauta com CPF " << cpf << " já cadastrado." << endl;
            return;
        }
    }
    Lista_de_Astronautas.push_back(new Astronauta(cpf, nome, idade));
    cout << "Astronauta cadastrado com sucesso!" << endl;
}

void cadastrarVoo(std::vector<Voo*>& Lista_de_Voos, int codigo){
    for (const auto& v : Lista_de_Voos) {
        if (v->getCodigo() == codigo) {
            std::cout << "Voo com código " << codigo << " já cadastrado." << std::endl;
            return;
        }
    }
    Lista_de_Voos.push_back(new Voo(codigo));
    cout << "Voo cadastrado com sucesso!" << endl;
}

void adicionarAstronautaNoVoo(std::vector<Astronauta*>& Lista_de_Astronautas, std::string cpf, std::vector<Voo*>& Lista_de_Voos, int codigo){
    Astronauta* astronauta = nullptr;
    Voo* voo = nullptr;
    for (auto a : Lista_de_Astronautas) {
        if (a->getCPF() == cpf) {
            astronauta = a;
            break;
        }
    }
    for (auto& v : Lista_de_Voos) {
        if (v->getCodigo() == codigo) {
            voo = v;
            break;
        }
    }
    if (astronauta && voo) {
        if (voo->getStatus()=="Planejamento"){
            if (astronauta->getDisponivel()==true){
                voo->adicionarAstronauta(astronauta);
                cout << "Astronauta " << astronauta->getNome() << " adicionado ao voo " << voo->getCodigo() << endl;
            } else {
                cout << "Operação não concluída, pois o astronauta " << astronauta->getNome() << " não está disponível." << endl;
            }
        } else {
            cout << "Operação não concluída, pois o voo " << voo->getCodigo() << " não está em planejamento." << endl;
        }
    } else {
        if (!astronauta) {
            cout << "Astronauta com CPF " << cpf << " não encontrado." << endl;
        }
        if (!voo) {
            cout << "Voo com código " << codigo << " não encontrado." << endl;
        }
    }
}

void removerAstronautaDoVoo(std::vector<Astronauta*>& Lista_de_Astronautas, std::string cpf, std::vector<Voo*>& Lista_de_Voos, int codigo){
    Astronauta* astronauta = nullptr;
    Voo* voo = nullptr;
    for (auto a : Lista_de_Astronautas) {
        if (a->getCPF() == cpf) {
            astronauta = a;
            break;
        }
    }
    for (auto v : Lista_de_Voos) {
        if (v->getCodigo() == codigo) {
            voo = v;
            break;
        }
    }
    if (astronauta && voo) {
        if (voo->getStatus()=="Planejamento" && astronauta->getDisponivel()==true){
            voo->removerAstronautaListaPassageiros(astronauta);
            std::cout << "Astronauta " << astronauta->getNome() << " foi removido do voo " << voo->getCodigo() << std::endl;
        } else {
            cout << "Operação não concluída, pois o voo " << voo->getCodigo() << " não está em planejamento." << endl;
        }
    } else {
        if (!astronauta) {
            cout << "Astronauta com CPF " << cpf << " não encontrado." << endl;
        }
        if (!voo) {
            cout << "Voo com código " << codigo << " não encontrado." << endl;
        }
    }
}

void lancarVoo(std::vector<Voo*>& Lista_de_Voos, int codigo){
    Voo* voo = nullptr;
    for (auto& v : Lista_de_Voos) {
        if (v->getCodigo() == codigo) {
            voo = v;
            break;
        }
    }
    if (voo) {
        if (voo->getListaPassageiros().size()>0){
            if (voo->getStatus()=="Planejamento"){
                voo->setStatus("EM_CURSO");
                for (auto astronauta : voo->getListaPassageiros()) {
                    astronauta->tornarIndisponivel();
                }
                cout << "Voo " << voo->getCodigo() << " está agora em curso." << endl;
            } else if(voo->getStatus()=="Em curso") {
                cout << "Operação não concluída, pois o voo " << voo->getCodigo() << " já está em curso." << endl;
            } else {
                cout << "Operação não concluída, pois o voo " << voo->getCodigo() << " já foi finalizado." << endl;
            }
        } else {
            cout << "É necessário no mínimo 1 astronauta para lançar o voo." << endl;
        }
    } else {
        cout << "Voo com código " << codigo << " não encontrado." << endl;
    }
}

void explodirVoo(std::vector<Voo*>& Lista_de_Voos, int codigo){
    Voo* voo = nullptr;
    for (auto& v : Lista_de_Voos) {
        if (v->getCodigo() == codigo) {
            voo = v;
            break;
        }
    }
    if (voo) {
        if (voo->getStatus()=="Em curso"){
            voo->setStatus("FINALIZADO_COM_FALHA");
            for (auto astronauta : voo->getListaPassageiros()) {
                astronauta->tornarIndisponivel();
                astronauta->matarAstronauta();
                astronauta->adicionarVooAoAstronauta(voo);
            }
            cout << "Voo " << voo->getCodigo() << " explodiu e todos os seus astronautas foram de submarino." << endl;
        } else {
            cout << "Operação não concluída, pois o voo " << voo->getCodigo() << " não está em curso." << endl;
        }
    } else {
        cout << "Voo com código " << codigo << " não encontrado." << endl;
    }
}

void finalizarVoo(std::vector<Voo*>& Lista_de_Voos, int codigo){
    Voo* voo = nullptr;
    for (auto& v : Lista_de_Voos) {
        if (v->getCodigo() == codigo) {
            voo = v;
            break;
        }
    }
    if (voo) {
        if (voo->getStatus()=="Em curso"){
            voo->setStatus("FINALIZADO_COM_SUCESSO");
            for (auto astronauta : voo->getListaPassageiros()) {
                astronauta->tornarDisponivel();
                astronauta->adicionarVooAoAstronauta(voo);
            }
            cout << "Voo " << voo->getCodigo() << " finalizado com sucesso." << endl;
        } else {
            cout << "Operação não concluída, pois o voo " << voo->getCodigo() << " não está em curso." << endl;
        }
    } else {
        cout << "Voo com código " << codigo << " não encontrado." << endl;
    }
}


void listarVoos(std::vector<Voo*>& Lista_de_Voos){
    cout << "Lista de Voos" << endl;
    if (Lista_de_Voos.size()==0){
        cout << "Nenhum voo cadastrado no sistema." << endl;
    } else {
        linhaDivisoria();
        for (auto voo : Lista_de_Voos){
            voo->exibir();
            linhaDivisoria();
        }
    }
}

void listarAstronautas(std::vector<Astronauta*>& Lista_de_Astronautas){
    cout << "Lista de Astronautas" << endl;
    if (Lista_de_Astronautas.size()==0){
        cout << "Nenhum astronauta cadastrado no sistema." << endl;
    } else {
        linhaDivisoria();
        cout << std::left << std::setw(16) << "CPF" << std::setw(40) << "|Nome" << std::setw(8) << "|Idade" << "|Disponível" << endl;
        linhaDivisoria();
        int countAstronautas = 0;
        for (auto astronauta : Lista_de_Astronautas) {
            cout << std::setw(16) << astronauta->getCPF() << "|" << std::setw(39) << astronauta->getNome() << "|" << std::setw(7) << astronauta->getIdade() << "|" << (astronauta->getDisponivel() ? "Sim" : "Não") << endl;
            countAstronautas++;
        }
        linhaDivisoria();
        cout << "Total de astronautas: " << countAstronautas << endl;
    }
}

void listarAstronautasMortos(std::vector<Astronauta*>& Lista_de_Astronautas) {
    bool encontrouMortos = false;
    cout << "Lista de Astronautas Mortos" << endl;
    for (auto astronauta : Lista_de_Astronautas) {
        if (!astronauta->getVivo()) {
            encontrouMortos = true;
        }
    }
    if (!encontrouMortos) {
        cout << "Nenhum astronauta foi morto." << endl;
    } else {
        linhaDivisoria();
        for (auto astronauta : Lista_de_Astronautas) {
            if (!astronauta->getVivo()) {
                if (!encontrouMortos) {
                    encontrouMortos = true;
                } 
                cout << "CPF: " << astronauta->getCPF() << endl;
                cout << "Nome: " << astronauta->getNome() << endl;
                cout << "Código dos voos que participou: ";
                std::vector<Voo*> voosDoAstronauta = astronauta->getVoosQueParticipou();
                for (size_t i = 0; i < voosDoAstronauta.size(); i++){
                    if (i==voosDoAstronauta.size()-1){
                        cout << voosDoAstronauta[i]->getCodigo() << endl;
                    } else {
                        cout << voosDoAstronauta[i]->getCodigo() << ", ";
                    }
                }
            }
            linhaDivisoria();
        }
    }  
}

void mostrarOpcoes(){
    cout << "Menu de Opções:" << endl;
    cout << "1 - Cadastrar Astronauta" << endl;
    cout << "2 - Cadastrar Voo" << endl;
    cout << "3 - Adicionar Astronauta no Voo" << endl;
    cout << "4 - Remover Astronauta do Voo" << endl;
    cout << "5 - Lançar Voo" << endl;
    cout << "6 - Explodir Voo" << endl;
    cout << "7 - Finalizar Voo" << endl;
    cout << "8 - Listar Voos" << endl;
    cout << "9 - Listar Astronautas" << endl;
    cout << "10- Listar Astronautas Mortos" << endl;
    cout << "11- Sair" << endl;
}