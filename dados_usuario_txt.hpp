#ifndef DADOS_USUARIO_TXT_HPP
#define DADOS_USUARIO_TXT_HPP
#include <fstream>
#include <iostream>

using namespace std;

class Dados{
protected:
  std::ofstream arquivo_nome;
  std::ofstream arquivo_telefone;
  std::ofstream arquivo_cpf;
  std::ofstream arquivo_endereco; 
  //std::ofstream arquivo_senhas;
public:
  Dados();
  void salvar(string _nome,string _telefone, string _cpf, string _endereco);
  bool procurar(string _cpf);
  void apagar(string _cpf);
  void auxiliar(string _cpf, const char *x);
};
#endif
