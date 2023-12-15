#include "dados_usuario_txt.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Dados::Dados()
    : arquivo_nome("nome.txt", ios::app),
      arquivo_telefone("telefone.txt", ios::app),
      arquivo_cpf("cpf.txt", ios::app),
      arquivo_endereco("endereco.txt", ios::app) {}

void Dados::salvar(string _nome, string _telefone, string _cpf,
                   string _endereco) {
  arquivo_cpf << _cpf << std::endl;
  arquivo_nome << _cpf << " " << _nome << std::endl;
  arquivo_telefone << _cpf << " " << _telefone << std::endl;
  arquivo_endereco << _cpf << " " << _endereco << std::endl;

  arquivo_nome.close();
  arquivo_telefone.close();
  arquivo_cpf.close();
  arquivo_endereco.close();
}

bool Dados::procurar(string _cpf) {
  ifstream arquivo_cpf("cpf.txt");
  std::string linha;
  while (!arquivo_cpf.eof()) {
    std::getline(arquivo_cpf, linha);
    if (linha == _cpf) {
      arquivo_cpf.close();
      return true;
    }
  }
  arquivo_cpf.close();
  return false;
}

void Dados::auxiliar(string _cpf, const char *x) {
  std::ofstream arquivoTemporario("temp.txt");
  std::string linha;
  ifstream arquivo_aux(x);
  while (!arquivo_aux.eof()) {
    std::getline(arquivo_aux, linha);
    if (linha.substr(0, 3) != _cpf) {
      arquivoTemporario << linha << std::endl;
    }
  }
  arquivo_aux.close();
  arquivoTemporario.close();
  remove(x);
  rename("temp.txt", x);
}

void Dados::apagar(string _cpf) {
  auxiliar(_cpf, "cpf.txt");
  auxiliar(_cpf, "nome.txt");
  auxiliar(_cpf, "endereco.txt");
  auxiliar(_cpf, "telefone.txt");
}
