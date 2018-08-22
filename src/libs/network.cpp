/**
 * @file network.cpp
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief File containing definitions for network object
 */

#include "network.h"

Network::Network() {
    this->_init_network();
}

int Network::_init_network() {
    std::cout << "init network" << std::endl;    
    _layers = new std::vector<Layer*>();
    _layers->push_back(new Layer()); // should be push_back node
    return 0;
}

void Network::test() {
    std::cout <<"size of vector: ";
    std::cout << _layers->size() <<std::endl;
    std::cout << *(*_layers)[0] <<std::endl;
}
