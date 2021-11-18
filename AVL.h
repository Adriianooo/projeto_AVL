#ifndef AVLNODE_H
#define AVLNODE_H
#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>

using namespace std;

class AVLNode
{
public:
    AVLNode();
    AVLNode(string Nome, string Uf, string Localidade, string Linguas, string Segmentos);
    virtual ~AVLNode();
    string getData();
    string getUf();
    string getLocalidade();
    string getLinguas();
    string getSegmentos();
    int getHeight();
    void setData(string Nome);
    void setUf(string Uf);
    void setLocalidade(string Localidade);
    void setLinguas(string Linguas);
    void setSegmentos(string Segmentos);
    void setHeight(int);
    AVLNode* getLeft();
    AVLNode* getRight();
    void setRight(AVLNode*);
    void setLeft(AVLNode*);
    int getBalance(AVLNode* N);


private:
    AVLNode* left, * right;
    string nome;
    string uf;
    string localidade;
    string linguas;
    string segmentos;
    int height;

};

class AVLTree
{
public:
    AVLTree();
    virtual ~AVLTree();
    AVLNode* getRoot();
    bool isEmpty();
    int height();
    int qtNodes();
    void preOrder();
    void posOrder();
    void inOrder();
    void reverseOrder();
    int getBalance(AVLNode* N);
    void create(string nomeArquivo);
    void inserir(string Nome, string Uf, string Localidade, string Linguas, string Segmentos);
    void search(AVLNode* node, string Nome);
    void emOrdem(AVLNode* node);
    void getName();


private:
    AVLNode* root;
    int height(AVLNode*);
    int qtNodes(AVLNode*);
    AVLNode* inserir(AVLNode* node, string Nome, string Uf, string Localidade, string Linguas, string Segmentos);
    void preOrder(AVLNode* no);
    void posOrder(AVLNode* no);
    void inOrder(AVLNode* no);
    AVLNode* rotateLL(AVLNode*);
    AVLNode* rotateRR(AVLNode*);
    AVLNode* rotateLR(AVLNode*);
    AVLNode* rotateRL(AVLNode*);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* rightRotate(AVLNode* y);
    void reverseOrder(AVLNode*);
    int maximo(int, int);
    AVLNode* minimo(AVLNode* no);
};

#endif // AVLTREE_H
#endif // AVLNODE_H