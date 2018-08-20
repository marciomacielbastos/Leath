#include "uf.h"
#include <iostream>

UF::UF(int N){
        this->N = N;
        this->count = N;
        this->id = new int[N];
        for (int i = 0; i < N; i++) id[i] = i;
        this->sz = new int[N];
        for (int i = 0; i < N; i++) sz[i] = 1;
}

int UF::getCount(){
    return this->count;
}

int UF::find(int p){
    while(this->id[p]!=p){
        p = id[p];
    }
    return p;
}

bool UF::connected(int p, int q){
    return (find(p) == find(q));
}

void UF::f_union(int p, int q){
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot) return;
    else if(this->sz[pRoot] > this->sz[qRoot]) id[qRoot] = pRoot;
    else id[pRoot] = qRoot;
    this->count--; //every time you do a union, you reduce one unit of the number of connected componets;
}

void UF::printComponents(){
    for(int i =0; i < N; i++){
        int p = i;
        while(this->id[p]!=p){
            std::cout << p << ",";
            p = id[p];
        }
        std::cout << p << std::endl;
     }
}
