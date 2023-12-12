#include "usuario.hpp"
#include <iostream>

using namespace std;
Usuario::Usuario() {}

Usuario::Usuario(string _nome, string _telefone, string _cpf,
                 string _endereco) {
  cpf = _cpf;
  nome = _nome;
  endereco = _endereco;
  telefone = _telefone;
}

Usuario::~Usuario() {}

string Usuario::getNome() { return nome; }

string Usuario::getTelefone() { return telefone; }

string Usuario::getCpf() { return cpf; }

string Usuario::getEndereco() { return endereco; }
