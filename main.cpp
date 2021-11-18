//Adriano Pinheiro Fernandes TIA: 32055161
//Lucas Andrew Lopes TIA: 32092245
#include "AVL.h"
#include <iostream>
#include <locale.h>

using namespace std;

void menu();
AVLTree arv; // Variável global para criar a árvore para usar suas funções

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
		while (arv.getRoot() == nullptr) { //Loop para verificar se o arquivo existe ou não. Caso não exista, usuário digita novamente.
			cout << "Arquivo vazio/Não encontrado. Digite novamente o nome do arquivo: ";
			getline(cin, arquivo);
			arv.create(arquivo);
		}
		cout << "Árvore criada ." << endl;
		menu();
	}
	return 0;
}

void menu() { //Função que mostra o menu para o usuário
	string numero;
	cout << "Digite 2 para buscar um elemento na árvore ou 3 para imprimir a árvore ou 4 para sair: ";
	getline(cin, numero);
	if (numero == "2") {
		arv.getName();
		menu(); //Chamada recursiva da função para tornar o menu interativo
	}
	else if (numero == "3") {
		arv.emOrdem(arv.getRoot());
		menu(); //Chamada recursiva da função para tornar o menu interativo
	}
}
