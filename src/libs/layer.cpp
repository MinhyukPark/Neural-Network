/**
 * @file layer.cpp
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief File containing definitions for layer object
 */

#include "layer.h"

Layer::Layer() {
    this->_init_layer();
}

int Layer::_init_layer() {
    std::cout << "init layer" << std::endl;    
    _nodes = new std::vector<int>();
    _nodes->push_back(40); // should be push_back node
    return 0;
}
