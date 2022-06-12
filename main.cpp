#include <iostream>
#include <locale>
#include <fstream>

void TelaInicial() {
	std::cout << "Bem-vindo(a) ao nosso sistema!" << std::endl;
	std::cout << "Escolha uma opção:" << std::endl;
	std::cout << "1 - Logar" << std::endl;
	std::cout << "2 - Registrar-se" << std::endl;
}

std::string Login() {
	std::cout << "Digite o seu login: ";
	std::string login;
	std::cin >> login;
	return login;
}

std::string Senha() {
	std::cout << "Digite a sua senha: ";
	std::string senha;
	std::cin >> senha;
	return senha;
}

bool Sistema(int opcao) {

	std::ofstream outFile;

	if (opcao == 1) {
		std::string login = Login();
		std::string senha = Senha();

		std::ifstream inFile;
		inFile.open("login.txt");
		if (inFile.is_open()) {
			std::string x, y;
			inFile >> x >> y;
			if (x == login && y == senha) {
				std::cout << "Login efetuado com sucesso!" << std::endl;
				return true;
			}
			else {
				std::cout << "Login ou senha incorretos!" << std::endl;
				return false;
			}
			inFile.close();
		}
		
	}
	else if (opcao == 2) {
		std::string login = Login();
		std::string senha = Senha();

		outFile.open("login.txt");

		if (outFile.is_open()) {
			outFile << login << std::endl;
			outFile << senha << std::endl;
			outFile.close();
		}
		return true;
	}
	else {
		std::cout << "Suas opções são: 1 ou 2." << std::endl;
		return false;
	}
}

int main() {
	setlocale(LC_ALL, "pt-br");

	TelaInicial();
	int opcao;
	std::cin >> opcao;
	Sistema(opcao);
	return 0;
}