#ifndef HASHING_H
#define HASHING_H
#include "bst.h"


class Hashing
{
    BST * hash_table;
    unsigned long int size_ht;
    unsigned long int M;

public:
    Hashing();
    static unsigned long int pow2(unsigned long int m);
    Hashing(unsigned long int m);
    unsigned long h(unsigned long long int n);
    bool insert(Vertice *v);
    bool search(Vertice *v);

};

#endif // HASHING_H
