#include "hashing.h"
#include <iostream>
#include "bst.h"
#include <math.h>
#define GOLDEN_RATIO (sqrt(5)-1)/2
#define w 32

unsigned long int Hashing::pow2(unsigned long int m){
    unsigned long int p = 1;
    for(unsigned long int i=0; i < m; i++){
        p *= 2;
    }
    return p;
}

Hashing::Hashing(long int m): hash_table(new BST[pow2(m)]){
    //m must be less than w
    this->size_ht = m;
    this->M = pow2(m);
}

unsigned long Hashing::h(unsigned long long int n){
    double temp;
    temp = (pow2(w)*GOLDEN_RATIO);
    unsigned long long C = (*reinterpret_cast<unsigned long long*>(&temp))%pow2(w);
    return ((n*C)%pow2(w))/(pow2(w-this->size_ht));
}

bool Hashing::insert(Vertice *v){
    return this->hash_table[h(v->getN())].insert(v);
}

bool Hashing::search(Vertice *v){
    if (this->hash_table[h(v->getN())].search(v->getN()) == nullptr) return false;
    else if (v->getN() == this->hash_table[h(v->getN())].search(v->getN())->getN()) {
        return true;
    } else return false;
}
