#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class Usuario{
    private:
      string nome;
      string endereco;
      string telefone;
      string cpf;

    public:
      Usuario();
      Usuario(string _nome, string _telefone, string _cpf, string _endereco);
      ~Usuario(); 
      string getEndereco();
      string getNome();
      string getTelefone();
      string getCpf();
};
#endif
