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
    this->_nodes = matrix_create(this->_input_unit, this->_output_unit);
    this->_bias = vector_create(this->_output_unit);
    for(size_t i = 0; i < this->_nodes->row; i ++) {
        for(size_t j = 0; j < this->_nodes->col; j ++) {
            MAT(this->_nodes, i, j) = -1 + ((double)rand() / RAND_MAX) * (1 - (-1));
        }
    }
    for(size_t i = 0; i < this->_bias->size; i ++) {
        VEC(this->_bias, i) = -1 + ((double)rand() / RAND_MAX) * (1 - (-1));
        
    }
    return 0;
}
