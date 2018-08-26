#include "lattice.h"

Lattice::Lattice(){

}

unsigned long long int * Lattice::getL(){
    return Lattice::L;
}
unsigned int Lattice::getD(){
    return Lattice::d;
}

void Lattice::setL(unsigned long long int *L){
    Lattice::L = L;
}
void Lattice::setD(unsigned int d){
    Lattice::d = d;
}

unsigned long long int * Lattice::L = nullptr;
unsigned int Lattice::d = 0;
