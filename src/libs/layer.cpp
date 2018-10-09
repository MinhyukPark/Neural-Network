/**
 * @file layer.cpp
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief File containing definitions for layer object
 */

#include "layer.h"

Layer::Layer(int _input_unit, int _output_unit) : _input_unit(_input_unit),
                                                  _output_unit(_output_unit) {
    this->_init_layer();
}

int Layer::_init_layer() {
    std::cout << "init layer" << std::endl;    
    _nodes = new std::vector<double>();
    _bias = new std::vector<double>();
    return 0;
}
