#include "interface_usuario.hpp"
#include "dados_usuario_txt.hpp"
#include "excecao.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
Interface::Interface() : usuario() {}
Interface::~Interface() {}
void Interface::bemVindo() {
  string escolha;
  std::cout << "Bem vindo ao restaurante C++" << std::endl;
  do {
    std::cout << "O que deseja?" << std::endl;
    std::cout << "1 - Cadastrar" << std::endl;
    std::cout << "2 - Fazer login" << std::endl;
    std::cout << "3 - Sair" << std::endl;
    std::cout << "Digite aqui: ";
    try {
      std::cin >> escolha;
      if (escolha == "1") {
        fazerCadastro();
      } else if (escolha == "2") {
        fazerLogin();
      } else if (escolha == "3") {
        sair();
      } else {
        throw EscolhaInvalida(escolha);
      }
    } catch (EscolhaInvalida e) {
      cout << e.what();
    }
  } while (escolha != "1" && escolha != "2" && escolha != "3");
}

void Interface::fazerLogin() {
  string cpf;
  string senha;
  const string tamanho_cpf = "3";
  do {
    std::cout << "Digite seu CPF: ";
    try {
      cin >> cpf;
      if (cpf.length() != stoi(tamanho_cpf)) {
        throw CampoInvalido(cpf, "Cpf", tamanho_cpf);
      }
    } catch (CampoInvalido e) {
      cout << e.what();
    }

  } while (cpf.length() != 3);

  cout << "Digite sua senha: ";
  cin >> senha;
  Dados login;
  string escolha;

  do {
    try {
      if (login.procurar(cpf)) {
        cout << "Login realizado com sucesso" << endl;
        proseguirPedido(cpf);
      } else {
        cout << "Cadastro não encontrado" << endl;
        cout << "1 - Criar cadastro" << endl;
        cout << "2 - Tentar login novamente" << endl;
        cout << "3 - Sair" << endl;
        cout << "Digite aqui: ";
        getline(cin, escolha);
        if (escolha == "1") {
          fazerCadastro();
        } else if (escolha == "2") {
          fazerLogin();
        } else if (escolha == "3") {
          sair();
        } else {
          throw EscolhaInvalida(escolha);
        }
      }
    } catch (EscolhaInvalida e) {
      cout << e.what();
    }
  } while (escolha != "1" && escolha != "2" && escolha != "3");
}

void Interface::fazerCadastro() {
  cout << "Iniciando o cadastro" << endl;
  string pri_nome;
  string seg_nome;
  string telefone;
  string cpf;
  string endereco;
  bool letra = true;
  bool campo_vazio;
  // string temporaria para limpar o buffer
  string temp;
  getline(cin, temp);
  do {
    try {
      cout << "Digite seu primeiro nome" << endl;
      getline(cin, pri_nome);
      letra = true;
      campo_vazio = false;
      for (char c : pri_nome) {
        if (!isalpha(c)) {
          letra = false;
          break;
        }
      }

      if (!letra) {
        throw CaractereInvalido(pri_nome, "primeiro nome");
      }
      if (pri_nome.empty()) {
        campo_vazio = true;
        throw CampoVazio("primeiro nome");
      }
    } catch (CaractereInvalido e) {
      cout << e.what();
    } catch (CampoVazio e) {
      std::cerr << "Erro: " << e.what() << std::endl;
    }
  } while (!letra);

  cout << "Digite seu segundo nome" << endl;
  getline(cin, seg_nome);

  string nome = pri_nome + " " + seg_nome;
  cout << "Insira seu telefone" << endl;
  cin >> telefone;
  cout << "Insira seu cpf" << endl;
  cin >> cpf;
  cout << "Insira seu endereço" << endl;
  cin >> endereco;
  usuario = Usuario(nome, telefone, cpf, endereco);
  Dados save;
  save.salvar(nome, telefone, cpf, endereco);
  proseguirPedido(cpf);
}
void Interface::proseguirPedido(string _cpf) {
  string escolha;
  do {
    cout << "Deseja fazer um pedido?" << endl << "1 - sim, 2 - não" << endl;
    std::cout << "Digite aqui: ";
    try {
      cin >> escolha;
      if (escolha == "1") {
        // interface pedido;
      } else if (escolha == "2") {
        menuOpcoes(_cpf);
      } else {
        throw EscolhaInvalida(escolha);
      }
    } catch (EscolhaInvalida e) {
      cout << e.what();
    }
  } while (escolha != "1" && escolha != "2");
}
void Interface::menuOpcoes(string _cpf) {
  std::cout << "Mais opções" << std::endl;
  string escolha;
  do {
    std::cout << "1 - Redefinir informações de cadastro" << std::endl;
    std::cout << "2 - Excluir cadastro" << std::endl;
    std::cout << "3 - Ver histórico de pedidos" << std::endl;
    std::cout << "4 - Sair" << std::endl;
    std::cout << "Digite aqui: ";
    try {
      std::cin >> escolha;
      if (escolha == "1") {
        redefinirCadastro();
      } else if (escolha == "2") {
        excluirCadastro(_cpf);
      } else if (escolha == "3") {
        // historicoPedidos();
      } else if (escolha == "4") {
        sair();
      } else {
        throw EscolhaInvalida(escolha);
      }
    } catch (EscolhaInvalida e) {
      cout << e.what();
    }
  } while (escolha != "1" && escolha != "2" && escolha != "3" &&
           escolha != "4");
}
void Interface::redefinirCadastro() {}
void Interface::excluirCadastro(string _cpf) {
  Dados deleter;
  deleter.apagar(_cpf);
}
void Interface::sair() { cout << "Saindo do sistema" << endl; }
