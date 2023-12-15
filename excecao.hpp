#include <stdexcept>
#include <iostream>

#ifndef EXCECAO_HPP
#define EXCECAO_HPP

class EscolhaInvalida : public std::exception{
private:
  string escolha;      
  string mensagem;  
public:

EscolhaInvalida(string t){
  escolha = t;
  mensagem = "A opção escolhida '"+ escolha +"' não existe.\nDigite uma das opçoes abaixo:\n";
}

  const char* what() const throw() override{
    return mensagem.c_str();
  }
};

class CampoInvalido : public std::exception{
private:
  string digitado;      
  string mensagem;  
  string tipo;
  string caracteres;
public:

CampoInvalido(string _digitado, string _tipo, string _caracteres){
  digitado = _digitado;
  tipo = _tipo;
  caracteres = _caracteres;
  mensagem = "" +tipo+ ": '" +digitado+ "' inválido. Diferente de " +caracteres+ " caracteres.\n";
}

  const char* what() const throw() override{
    return mensagem.c_str();
  }
};


class CaractereInvalido : public std::exception{
private:
  string digitado;      
  string mensagem;  
  string tipo;
public:

CaractereInvalido(string _digitado, string _tipo){
  digitado = _digitado;
  tipo = _tipo;
mensagem = "" +tipo+ ": '" +digitado+ "' inválido. " +tipo+ " só deve conter caracteres de letras.\n";
}

  const char* what() const throw() override{
    return mensagem.c_str();
  }
};

class CampoVazio : public std::exception{
private:   
  string mensagem;  
  string tipo;
public:

CampoVazio(string _tipo){
  tipo = _tipo;
mensagem = "Este campo '"+tipo+"' deve ser preenchido.";
}

  const char* what() const throw() override{
    return mensagem.c_str();
  }
};
#endif
