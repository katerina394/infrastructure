#include "Percolation.h"
#include <iostream>

int main() {
    std::cout << Probability(3, 100000);  // 0,613628
    std::cout << Probability(3, 10000);  // 0,613538
    std::cout << Probability(3, 1000);  // 0, 613696
    std::cout << Probability(5, 1000);  // 0,614272
}
