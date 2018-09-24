#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <vector>
#include <heap.h>

class Dijkstra
{
private:
    std::vector<long> distances;
    std::vector<long> energy;
    std::vector<long> parents;
    Heap Q;

public:
    Dijkstra(std::vector<long> &e, std::vector<long> &d, std::vector<long> &p);
    void relax(long u, long v);
    void run();
};

#endif // DIJKSTRA_H
