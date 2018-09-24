#ifndef BST_H
#define BST_H
#include <vertice.h>


class BST{

private:
        Vertice *root;
        BST *right = nullptr;
        BST *left= nullptr;
        long id = -1;
        long count = 0;
        long value = -1;



public:
    BST();
    BST(long id);
    Vertice * search(unsigned long long int key);
    Vertice * search(Vertice * root, unsigned long long int key);
    bool insert(Vertice *v);
};

#endif // BST_H
