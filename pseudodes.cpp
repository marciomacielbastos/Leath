#include "pseudodes.h"
#define NITER 4

PseudoDES::PseudoDES(){
}
unsigned long * PseudoDES::break_64(unsigned long long int word){
    static unsigned long int numbers[2];
    numbers[0] = (word>>32);
    numbers[1] = ((word) & 0Xffffffff);
    return numbers;
}

unsigned long PseudoDES::g(unsigned long *rword, int i){
    unsigned long t1, t2, lo, hi;
    static unsigned long c1[NITER] = {0xbaa96887L, 0x1e17d32cL, 0x03bcdc3cL, 0x0f33d1b2L};
    static unsigned long c2[NITER] = {0x4b0f3b58L, 0xe874f0c3L, 0x6955c5a6L, 0x55a7ca46L};
    // right 32-bit word  XOR c1
    t1 = (*rword) ^ c1[i];
    // break the 32-bit word in two 16-bit words
    lo = t1 & 0xffff;
    hi = t1 >> 16;
    // square of the lower 16 bits plus neg of square of the higher 16 bits
    t2 = (lo*lo) + ~(hi*hi);
    //Swap half-words
    t1 = ((t2 >> 16) | ((t2 & 0xffff) << 16));
    //result above XOR c2
    t2 = t1 ^ c2[i];
    //result above plus hi*lo
    t1 = t2 + hi*lo;
    return t1;
}

unsigned long long int PseudoDES::psdes(unsigned long long int word){
    //break the 64-bit word in two 32-bit word
    unsigned long *lword = PseudoDES::break_64(word);
    unsigned long *rword = (lword+1);

    unsigned long long code = 0;
    unsigned long rsswap;
    /*perform the DES algorithm swaping the lower 32-bit word
      with the higher 32-bi word in each iteration*/
    for(int i=0; i < NITER; i++){
        rsswap=(*rword);
        *rword = (*lword) ^ PseudoDES::g(rword, i);
        *lword = rsswap;
    }
    //join the new lower and higher words
    code = (code | (*lword) << 32) | (*rword);
    return code;
}
