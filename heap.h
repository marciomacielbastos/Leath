#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <vector>


class Heap
{
private:
    std::vector<long> pq;
    std::vector<long> dist;

public:
    Heap(std::vector<long>& d);
    long size();
    bool bigger(long i, long j);
    void exch(long i, long j);
    void swim(long k);
    void sink(long k);
    void insert(int v);
    long get_min();
};

#endif // HEAP_H
