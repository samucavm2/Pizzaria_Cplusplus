#include "interface_usuario.hpp"
#include "excecao.hpp"
#include <iostream>
Interface::Interface() : usuario() {}
Interface::~Interface() {}
void Interface::bemVindo() {
  try {
    std::cout << "Bem vindo ao restaurante C++" << std::endl;
    std::cout << "O que deseja?" << std::endl;
    std::cout << "1 - Cadastrar" << std::endl;
    std::cout << "2 - Fazer login" << std::endl;
    std::cout << "3 - Excluir cadastro" << std::endl;
    std::cout << "4 - Sair" << std::endl;
    std::cout << "Digite aqui: ";
    string escolha;
    std::cin >> escolha;
    if (escolha == "1") {
      fazerCadastro();
    } else if (escolha == "2") {
      fazerLogin();
    } else if (escolha == "3") {
      ExcluirCadastro();
    } else if (escolha == "4") {
      sair();
    } else {
      throw EscolhaInvalida(escolha);
    }
  } catch (EscolhaInvalida e) {
    cout << e.what();
  }
}

void Interface::fazerLogin() {}
void Interface::fazerCadastro() {
  cout << "Iniciando o cadastro" << endl;
  string nome;
  string telefone;
  string cpf;
  string endereco;
  cout << " Digite seu nome" << endl;
  cin >> nome;
  cout << "Insira seu telefone" << endl;
  cin >> telefone;
  cout << "Insira seu cpf" << endl;
  cin >> cpf;
  cout << "Insira seu endereço" << endl;
  cin >> endereco;
  usuario = Usuario(nome, telefone, cpf, endereco);
  cout << usuario.getCpf() << endl;
  cout << "Cadastro realizado com sucesso!Caso queira prosseguir com o pedido, "
          "digite 1, caso contrário digite 2"
       << endl;
}
void Interface::proseguirPedido() {}
void Interface::ExcluirCadastro() {}
void Interface::sair() {}
