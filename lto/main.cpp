#include "helper.hpp" 
#include <iostream>   // for std::cout

int main() {
    volatile long long sum = 0;
    /*
    Using volatile to prevent compiler from optimizing this loop. 
    Removing `volatile` triggers loop optimization and amke it run 
    almost 1000 times faster!
    */

    const long long iterations = 1000000000; // 1e9

    for (long long i = 0; i < iterations; ++i) {
        sum += simple_compute(i);
    }

    std::cout << "Final sum: " << sum << std::endl;
    
    return 0;
}
