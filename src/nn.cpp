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
    Network* nn = new Network(4, 5, 256, 3);
    nn->test();
    return 0;
}
