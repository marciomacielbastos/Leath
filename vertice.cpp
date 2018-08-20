#include "vertice.h"
#include "lattice.h"

unsigned long long int Vertice::getN(unsigned long long int *x){
    unsigned long long int n = x[0];
    for(int i = 1; i < Lattice::getD(); i++){
        n = n * (Lattice::getL()[i]) +x[i];
    }
    return n;
}

Vertice::Vertice(unsigned long long int *x, unsigned long long int cs):  x(x){
    this->bitmap = 0;
    this->left = nullptr;
    this->right = nullptr;
//    this->n = Vertice::getN(x);
    this->chemical_shell = cs;
}

void Vertice::setLeft(Vertice *v){
    this->left = v;
}

void Vertice::setRight(Vertice *v){
    this->right = v;
}

void Vertice::setBitmap(unsigned long long int mask){
    this->bitmap |= mask;
}

unsigned long long int Vertice::Vertice::getN(){
    return getN(this->x);
}

unsigned long long int * Vertice::Vertice::getX(){
    return this->x;
}

unsigned long long int Vertice::getCS(){
    return this->chemical_shell;
}

Vertice * Vertice::getLeft(){
    return this->left;
}

Vertice * Vertice::getRight(){
    return this->right;
}
