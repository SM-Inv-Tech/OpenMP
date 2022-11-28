#include <iostream>

#include "omp.h"

int main(int argc, char **argv)
{
    std::cout << "Hello 1" << std::endl;

    #pragma omp parallel num_threads(8)
    {
        std::cout << "Hi" << std::endl;
    }

    std::cout << "Hello 2" << std::endl;

    return 0;
}
