#ifndef VERTICE_H
#define VERTICE_H


class Vertice{
private:
        unsigned long long int *x;
//        unsigned long long int n;
        unsigned long long int chemical_shell;
        unsigned long long int bitmap; //one bit for each direction from which the vertice (site) can be visited.
        Vertice *left;
        Vertice *right;
        
public:
    Vertice();
    static unsigned long long int getN(unsigned long long int *x);
    Vertice(unsigned long long int *x, unsigned long long int cs);
    void setLeft(Vertice *v);
    void setRight(Vertice *v);
    void setBitmap(unsigned long long int mask);
    unsigned long long int getN();
    unsigned long long int * getX();
    unsigned long long int getCS();
    Vertice * getLeft();
    Vertice * getRight();

};

#endif // VERTICE_H
