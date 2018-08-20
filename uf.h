#ifndef UF_H
#define UF_H

class UF
{
private:
    int N;
    int* id; // parent link (site indexed)
    int* sz; // size of component for roots (site indexed)
    int count; // number of components

public:
    UF(int N);
    int getCount();
    bool connected(int p, int q);
    int find(int p);
    void f_union(int p, int q);
    void printComponents();
};

#endif // UF_H
