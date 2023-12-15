#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
using namespace std;
#include "usuario.hpp"

class Interface{
    private:
      Usuario usuario;
    public:
       Interface();
      ~Interface();
      void bemVindo();
      void fazerLogin();
      void fazerCadastro();
      void proseguirPedido(string _cpf);
      void menuOpcoes(string _cpf);
      void excluirCadastro(string _cpf);
      void redefinirCadastro();
      void sair();
};
#endif
