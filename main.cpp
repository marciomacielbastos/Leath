#include <iostream>
#include <fstream>
#include <vector>

std::vector<long> tests(std::vector<long>& d){
    d[6] = 999;
    return d;
}

int main(){
    std::vector<long> test;
    for(int i=0; i <10; i++) test.insert(test.begin(), i);
    test[6] = 1072;
    tests(test);
    for(int i=0; i <10; i++) std::cout<<test[i]<<std::endl;
    std::cout<<tests(test)[6]/4;
    return 0;
}
