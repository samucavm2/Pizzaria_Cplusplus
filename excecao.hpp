#include <stdexcept>
#include <iostream>

#ifndef EXCECAO_HPP
#define EXCECAO_HPP




class EscolhaInvalida : public std::exception{
private:
  string escolha;      
  std::string mensagem;  
public:

EscolhaInvalida(string t){
  escolha = t;
  mensagem = "A opção escolhida não existe.\nDigite uma das opçoes abaixo:\n";
}

  const char* what() const throw() override{
    return mensagem.c_str();
  }
};
#endif
