#include <iostream>
#include "functions.h"

int main(){
    int c;
    std::cin >> c;
    for(int i = 1; i <= c; ++i){
        int n, m;
        std::cin >> n;
        std::cin >> m;
        std::cout << "Case #" << i << ": "<< CalculateHoles(n, m) << std::endl;
    }
    return 0;
}
