#ifndef LATICE_H
#define LATICE_H


class Lattice{
private:
    static unsigned long long int *L;
    static unsigned int d;
public:
    Lattice();
    static unsigned long long int * getL();
    static unsigned int getD();
    static void setL(unsigned long long int *L);
    static void setD(unsigned int d);
};

#endif // LATICE_H
