//Adriano Pinheiro Fernandes TIA: 32055161
//Lucas Andrew Lopes TIA: 32092245
#include "AVL.h"
#include <iostream>
#include <locale.h>

using namespace std;

void menu();
AVLTree arv; // Vari�vel global para criar a �rvore para usar suas fun��es

int main() {
	setlocale(LC_ALL, "");
	string number;
	string arquivo;
	cout << "--------------- MENU --------------" << "\n";
	cout << "Digite 1 para inserir a tabela do excel e montar a arvore: ";
	getline(cin, number);
	if (number == "1") {
		cout << "Digite o nome do arquivo: ";
		getline(cin, arquivo);
		arv.create(arquivo);
		while (arv.getRoot() == nullptr) { //Loop para verificar se o arquivo existe ou n�o. Caso n�o exista, usu�rio digita novamente.
			cout << "Arquivo vazio/N�o encontrado. Digite novamente o nome do arquivo: ";
			getline(cin, arquivo);
			arv.create(arquivo);
		}
		cout << "�rvore criada ." << endl;
		menu();
	}
	return 0;
}

void menu() { //Fun��o que mostra o menu para o usu�rio
	string numero;
	cout << "Digite 2 para buscar um elemento na �rvore ou 3 para imprimir a �rvore ou 4 para sair: ";
	getline(cin, numero);
	if (numero == "2") {
		arv.getName();
		menu(); //Chamada recursiva da fun��o para tornar o menu interativo
	}
	else if (numero == "3") {
		arv.emOrdem(arv.getRoot());
		menu(); //Chamada recursiva da fun��o para tornar o menu interativo
	}
}
