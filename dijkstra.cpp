#include "dijkstra.h"

Dijkstra::Dijkstra(std::vector<long> &e, std::vector<long> &d, std::vector<long> &p){
    this->distances = d;
    this->energy = e;
    this->parents = p;
    this->Q = Heap(this->distances);
    this->Q.insert(0);
}

void Dijkstra::relax(long u, long v){
    if(this->distances[v] > this->distances[u]+this->energy[v]){
        this->distances[v] = this->distances[u]+this->energy[v];
        this->parents[v] = u;
    }
}

void Dijkstra::run(){
    Bst S =
}


