#include "helper.hpp" 
#include <functional> // for std::functional
#include <iostream>   // for std::cout
#include <string> //for std::string

int main(int argc, char* argv[]) {
    // Make sure we are getting valid arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <simple | complex>" << std::endl;
        return 1;
    }
    volatile double sum = 0;
    /*
    Using volatile to prevent compiler from optimizing this loop. 
    Removing `volatile` triggers loop optimization and amke it run 
    almost 1000 times faster!
    */

    // Decide whether to use simple or complex compute function
    std::function<double(long long)> compute_func;

    std::string choice = argv[1];
    if (choice == "simple") {
        compute_func = simple_compute;
    } else if (choice == "complex") {
        compute_func = complex_compute;
    } else {
        std::cout << "Invalid choice " << choice << ". ";
        std::cout << "Choose either 'simple' or 'complex'" << std::endl;
    }

    const long long iterations = 100000000; // 1e8

    for (long long i = 0; i < iterations; ++i) {
        sum += compute_func(i);
    }

    std::cout << "(" << choice << ")" << " final sum: " << sum << std::endl;
    
    return 0;
}
