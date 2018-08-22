/**
 * @file nn.cpp
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief File with int main
 */

#include <iostream>
#include "network.h"

int main() {
    std::cout<<"NN start?"<<std::endl;
    Network* nn = new Network();
    nn->test();
    return 0;
}
