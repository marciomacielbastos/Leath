#include "bst.h"

BST::BST(){
    this->root = nullptr;
}

BST::BST(long id){
    this->id = id;
    this->root = nullptr;
    if(this->id >= 0){
        this->count++;
    }
}

void BST::set_value(long value){
    this->value = value;
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

bool BST::search(long v){
    if(this->id == v){
        return true;
    } else if(v < this->id){
        if(this->left == nullptr){
            return false;
        } else {
            return this->left->search(v);
        }
    } else if (v > this->id) {
        if(this->right == nullptr){
            return false;
        } else {
          return this->right->search(v);
        }
    }
}

bool BST::insert(long id){
    if(this->count > 0){
        if(this->id < id){
            if(this->left == nullptr){
                this->left = BST(id);
            } else {
                this->left->insert(id);
            }

        }else if (id > this->id) {
            if(this->right == nullptr){
                this->right = BST(id);
            } else {
                this->right->insert(id);
            }
        }
    } else {
        this->id = id;
        this->count++;
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

