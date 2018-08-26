#include "leath.h"
#include "lattice.h"

Leath::Leath(long int m, unsigned long long int * seed): h(Hashing(m)), seed(Vertice(seed, 0)){
    h.insert(& (this->seed));
    occupiedQueue.push(this->seed);
}

void Leath::setMask(int m){
    unsigned long long int mask = 1;
    mask = mask << (Lattice::getD() -1);
    mask = mask >> m;
    return mask;
}

bool Leath::run(){
    int k = 0;
    while (!this->occupiedQueue.empty()){
        Vertice v = this->occupiedQueue.front();
        this->occupiedQueue.pop();
        unsigned long long * x = v.getX();
        for(int i = 0; i < Lattice::getD(); i++){
            if(x[i]+1 >= Lattice::getL()[i]) break;
            x[i] += 1;
            Vertice node = Vertice(x, v.getCS()+1);
            node.setBitmap(setMask(i));
            if(h.insert(&node)){
                //Random test (change on monday)!
                if(k < 15){
                    this->occupiedQueue.push(v);
                    k++;
                }
            }
            x[i] -= 1;
        }
        for(int i = 0; i < Lattice::getD(); i++){
            if(x[i]+1 <= 0) break;
            x[i] -= 1;
            Vertice node = Vertice(x, v.getCS()+1);
            node.setBitmap(setMask(i));
            if(h.insert(&node)){
                //Random test (change on monday)!
                if(k < 15){
                    this->occupiedQueue.push(v);
                    k++;
                }
            }
            x[i] += 1;
        }
    }
    return true;
}
