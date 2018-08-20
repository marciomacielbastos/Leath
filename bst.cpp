#include "bst.h"

BST::BST(){
    this->root = nullptr;
}

Vertice * BST::search(unsigned long long int key){
    if(this->root == nullptr) return this->root;
    else if (this->root->getN() == key) return this->root;
    else if (this->root->getN() > key){
        if(this->root->getLeft() == nullptr) return this->root;
        else return search(this->root->getLeft(), key);
    } else {
        if(this->root->getRight() == nullptr) return this->root;
        else return search(this->root->getRight(), key);
    }
}

Vertice * BST::search(Vertice * root, unsigned long long int key){
    if (root->getN() == key) return root;
    else if (root->getN() > key){
        if(root->getLeft() == nullptr) return root;
        else return search(root->getLeft(), key);
    } else {
        if(root->getRight() == nullptr) return root;
        else return search(root->getRight(), key);
    }
}

bool BST::insert(Vertice *v){
    Vertice *parent = search(v->getN());
    if(parent == nullptr){
        this->root = v;
        return true;
    } else {
        if(parent->getN() == v->getN()) return false;
        else if (parent->getN() > v->getN()) {
            parent->setLeft(v);
            return true;
        } else {
            parent->setRight(v);
            return true;
        }
    }
}
