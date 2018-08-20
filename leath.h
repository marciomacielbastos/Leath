#ifndef LEATH_H
#define LEATH_H
#include "hashing.h"
#include "vertice.h"
#include <queue>


class Leath{
private:
    Hashing h;
    Vertice seed;
    std::queue<Vertice> occupiedQueue;
    double p;


public:
    Leath(unsigned long int m, unsigned long long int * seed, double p);
    unsigned long long int setMask(int i);
    void visit(Vertice v, bool plusorminus);
    bool run();
};

#endif // LEATH_H
