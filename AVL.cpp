#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "AVL.h"
#include <string>

using namespace std;

AVLNode::AVLNode()
{
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(string Nome, string Uf, string Localidade, string Linguas, string Segmentos) //Criação do nó com as informações do prestador
{
    left = NULL;
    right = NULL;
    nome = Nome;
    uf = Uf;
    localidade = Localidade;
    linguas = Linguas;
    segmentos = Segmentos;
    height = 0;
}

AVLNode::~AVLNode()
{
}

void AVLNode::setData(string Nome)
{
    nome = Nome;
}

void AVLNode::setUf(string Uf) {
    uf = Uf;
}

void AVLNode::setLocalidade(string Localidade) {
    localidade = Localidade;
}

void AVLNode::setLinguas(string Linguas) {
    linguas = Linguas;
}

void AVLNode::setSegmentos(string Segmentos) {
    segmentos = Segmentos;
}

string AVLNode::getData()
{
    return nome;
}

string AVLNode::getUf() {
    return uf;
}

string AVLNode::getLocalidade() {
    return localidade;
}

string AVLNode::getLinguas() {
    return linguas;
}

string AVLNode::getSegmentos() {
    return segmentos;
}

void AVLNode::setLeft(AVLNode* n)
{
    left = n;
}

AVLNode* AVLNode::getLeft()
{
    return left;
}

void AVLNode::setRight(AVLNode* n)
{
    right = n;
}

AVLNode* AVLNode::getRight()
{
    return right;
}

void AVLNode::setHeight(int h)
{
    height = h;
}

int AVLNode::getHeight()
{
    return height;
}

void AVLTree::create(string nomeArquivo) {//Função para criar a árvore
    ifstream ip(nomeArquivo); //Localiza o arquivo
    string nome, uf, localidade, linguas, segmentos; //Criação de variáveis para armazenar as informações
    while (ip.peek() != EOF) { //Laço para pegar todos os elementos da planilha
        getline(ip, nome, ';'); //Função para pegar as informações de cada linha da planilha
        getline(ip, uf, ';');
        getline(ip, localidade, ';');
        getline(ip, linguas, ';');
        getline(ip, segmentos, '\n');
        if (nome == "Nome do Prestador" && uf == "UF" && localidade == "Localidade" && linguas == "Línguas" && segmentos == "Segmentos") {
            cout << "----INFORMAÇÕES DA TABELA -----" << "\n";
            cout << nome << "\n";
            cout << uf << "\n";
            cout << localidade << "\n";
            cout << linguas << "\n";
            cout << segmentos << "\n";
            cout << "--------------" << endl;
        }
        else { //Print do das informações do prestador
            cout << "nome: " << nome << "\n";
            cout << "uf: " << uf << "\n";
            cout << "localidade: " << localidade << "\n";
            cout << "linguas: " << linguas << "\n";
            cout << "segmentos: " << segmentos << "\n";
            cout << "----------------" << endl;
            AVLTree::inserir(nome, uf, localidade, linguas, segmentos); //Função para inserir essas informações na árvore como um nó

        }
    }
}


AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::~AVLTree()
{

}

AVLNode* AVLTree::getRoot() {
    return root;
}

int AVLTree::getBalance(AVLNode* N)
{
    if (N == NULL)
        return 0;
    return height(N->getLeft()) - height(N->getRight());
}

bool AVLTree::isEmpty()
{
    return root == NULL;
}

int AVLTree::height()
{
    return height(root);
}

int AVLTree::height(AVLNode* no)
{
    return no == NULL ? -1 : no->getHeight();
}

AVLNode* AVLTree::minimo(AVLNode* no)
{
    AVLNode* current = no;
    while (current->getLeft() != NULL)
        current = current->getLeft();
    return current;
}

int AVLTree::maximo(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

int AVLTree::qtNodes()
{
    return qtNodes(root);
}

int AVLTree::qtNodes(AVLNode* no)
{
    if (no == NULL)
        return 0;
    int qtleft = qtNodes(no->getLeft());
    int qtright = qtNodes(no->getRight());
    return qtleft + qtright + 1;

}

void AVLTree::search(AVLNode* node, string Nome) { //Função que pesquisa um nó pelo nome
    if (root == nullptr) {
        cout << "Usuário Não encontrado.";
    }
    if (node == nullptr) { // Condição caso o nó não exista na árvore.
        cout << "Usuário nao encontrado." << "\n";
        return;
    }
    else if (node->getData() == Nome) { //Print dos elementos do nó caso ele esteja na árvore
        cout << "Usuário encontrado." << "\n";
        cout << "nome: " << node->getData() << "\n";
        cout << "uf: " << node->getUf() << "\n";
        cout << "localidade: " << node->getLocalidade() << "\n";
        cout << "linguas: " << node->getLinguas() << "\n";
        cout << "segmentos: " << node->getSegmentos() << "\n";
        cout << "----------------" << endl;
    }
    else if (Nome <= node->getData()) return search(node->getLeft(), Nome);
    else return search(node->getRight(), Nome);
}

void AVLTree::getName() { //Função para pegar o nome do prestador e fazer a busca desse nome na árvore
    cout << "Digite o nome do usuário que deseja pesquisar: ";
    string palavra;
    getline(cin, palavra);
    AVLTree::search(AVLTree::getRoot(), palavra);
}

void AVLTree::emOrdem(AVLNode* node) { //Função para printar todas as informações do nó em ordem alfabética
    if (node) {
        emOrdem(node->getLeft());
        cout << "nome: " << node->getData() << "\n";
        cout << "uf: " << node->getUf() << "\n";
        cout << "localidade: " << node->getLocalidade() << "\n";
        cout << "linguas: " << node->getLinguas() << "\n";
        cout << "segmentos: " << node->getSegmentos() << "\n";
        cout << "----------------" << endl;
        emOrdem(node->getRight());
    }
}


void AVLTree::inserir(string name, string uf, string localidade, string linguas, string segmento)
{
    root = inserir(root, name, uf, localidade, linguas, segmento);
}



AVLNode* AVLTree::inserir(AVLNode* node, string name, string uf, string localidade, string linguas, string segmentos) //Função para inserir as informações como um nó na árvore
{
    if (node == NULL)
        return new AVLNode(name, uf, localidade, linguas, segmentos);
    if (name < node->getData())
    {
        node->setLeft(inserir(node->getLeft(), name, uf, localidade, linguas, segmentos));
        if (height(node->getRight()) - height(node->getLeft()) == -2)
        {
            if (name < node->getLeft()->getData())
            {
                node = rotateLL(node);
            }
            else {
                node = rotateLR(node);
            }
        }
    }
    else
    {
        if (name > node->getData())
        {
            node->setRight(inserir(node->getRight(), name, uf, localidade, linguas, segmentos));
            if (height(node->getRight()) - height(node->getLeft()) == 2)
            {
                if (name > node->getRight()->getData())
                    node = rotateRR(node);
                else
                    node = rotateRL(node);

            }

        }
    }
    node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);

    return node;
}

AVLNode* AVLTree::rotateLL(AVLNode* node)
{
    AVLNode* leftSubTree = node->getLeft();
    node->setLeft(leftSubTree->getRight());
    leftSubTree->setRight(node);
    node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
    leftSubTree->setHeight(maximo(height(leftSubTree->getLeft()), height(node) + 1));
    return leftSubTree;
}

AVLNode* AVLTree::rotateRR(AVLNode* node)
{
    AVLNode* rightSubTree = node->getRight();
    node->setRight(rightSubTree->getLeft());
    rightSubTree->setLeft(node);
    node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
    rightSubTree->setHeight(maximo(height(rightSubTree->getRight()), height(node) + 1));
    return rightSubTree;
}


AVLNode* AVLTree::rotateLR(AVLNode* node)
{
    node->setLeft(rotateRR(node->getLeft()));
    return rotateLL(node);
}

AVLNode* AVLTree::rotateRL(AVLNode* node)
{
    node->setRight(rotateLL(node->getRight()));
    return rotateRR(node);
}

AVLNode* AVLTree::leftRotate(AVLNode* x)
{
    AVLNode* y = x->getRight();
    AVLNode* T2 = y->getLeft();

    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(maximo(height(x->getLeft()), height(x->getRight())) + 1);
    y->setHeight(maximo(height(y->getLeft()), height(y->getRight())) + 1);

    return y;
}
AVLNode* AVLTree::rightRotate(AVLNode* y)
{
    AVLNode* x = y->getLeft();
    AVLNode* T2 = x->getRight();

    x->setRight(y);
    y->setLeft(T2);

    y->setHeight(maximo(height(y->getLeft()), height(y->getRight())) + 1);
    x->setHeight(maximo(height(x->getLeft()), height(x->getRight())) + 1);

    return x;
}


void AVLTree::preOrder()
{
    preOrder(root);
}

void AVLTree::inOrder()
{
    inOrder(root);
}

void AVLTree::posOrder()
{
    posOrder(root);
}

void AVLTree::reverseOrder()
{
    reverseOrder(root);
}

void AVLTree::preOrder(AVLNode* no)
{
    if (no != NULL)
    {
        cout << no->getData() << endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void AVLTree::posOrder(AVLNode* no)
{
    if (no != NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout << no->getData() << endl;
    }
}

void AVLTree::inOrder(AVLNode* no)
{
    if (no != NULL)
    {
        inOrder(no->getLeft());
        cout << no->getData() << endl;
        inOrder(no->getRight());
    }
}

void AVLTree::reverseOrder(AVLNode* no)
{
    if (no != NULL)
    {
        reverseOrder(no->getRight());
        cout << no->getData() << endl;
        reverseOrder(no->getLeft());
    }
}

