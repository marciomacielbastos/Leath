#ifndef BST_H
#define BST_H
#include <vertice.h>


class BST{

private:
        Vertice *root;
public:
    BST();
    Vertice * search(unsigned long long int key);
    Vertice * search(Vertice * root, unsigned long long int key);
    bool insert(Vertice *v);
};

#endif // BST_H
