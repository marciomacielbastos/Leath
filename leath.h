#ifndef LEATH_H
#define LEATH_H
#define MAX 10000
#include "hashing.h"
#include "vertice.h"
#include <queue>

class Leath{
private:
    Hashing h;
    Vertice seed;
    std::queue<Vertice> occupiedQueue;
    double p;
    static unsigned long long int m;


public:
    Leath(unsigned long int m, unsigned long long int * seed, double p);
    unsigned long long int setMask(unsigned int mask_shift);
    void visit(Vertice v, bool plusorminus);
    bool run();
    unsigned long long int getM();
    void addM();
};

#endif // LEATH_H
