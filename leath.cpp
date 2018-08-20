#include "leath.h"
#include "lattice.h"
#include "pseudodes.h"

Leath::Leath(unsigned long int m, unsigned long long int * seed, double p): h(Hashing(m)), seed(Vertice(seed, 0)){
    h.insert(& (this->seed));
    occupiedQueue.push(this->seed);
    this->p = p;
}

unsigned long long int Leath::setMask(int m){
    unsigned long long int mask = 1;
    mask = mask << (Lattice::getD() -1);
    mask = mask >> m;
    return mask;
}

void Leath::visit(Vertice v, bool plusorminus){
    unsigned long long * x = v.getX();
    for(int i = 0; i < Lattice::getD(); i++){
        if(x[i]+1 >= Lattice::getL()[i] && x[i]+1 <= 0) continue;
        if(plusorminus) x[i] += 1;
        else x[i] -= 1;
        Vertice node = Vertice(x, v.getCS()+1);
        node.setBitmap(setMask(i));
        if(h.insert(&node)){
            if(PseudoDES::psdes(v.getN()) < Hashing::pow2(63)*(2*this->p)){
                this->occupiedQueue.push(v);
            }
        }
        if(plusorminus) x[i] -= 1;
        else x[i] += 1;
    }
}

bool Leath::run(){
    while (!this->occupiedQueue.empty()){
        Vertice v = this->occupiedQueue.front();
        this->occupiedQueue.pop();
        visit(v, 1);
        visit(v, 0);
    }
    return true;
}
