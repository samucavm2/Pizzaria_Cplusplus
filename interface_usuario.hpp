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
      void proseguirPedido();
      void ExcluirCadastro();
      void sair();
};
#endif
