#include <string>
using std::string;

class astronauta{
private:
    string cpf;
    string nome;
    int idade;

public:
    string getCPF();
    void setCPF(string cpf);
    string getNome();
    void setNome(string nome);
    int getIdade();
    void setIdade(int idade);
};