/**
 * @file network.cpp
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief File containing definitions for network object
 */

#include "network.h"

Network::Network(int _num_layers, int _input_unit, int _layer_unit, int _output_unit) :
                                                      _num_layers(_num_layers),
                                                      _input_unit(_input_unit), 
                                                      _layer_unit(_layer_unit),
                                                      _output_unit(_output_unit) {
    this->_init_network();
}

int Network::_init_network() {
    std::cout << "init network" << std::endl;    
    _layers = new std::vector<Layer*>();
    for(int i = 0; i < this->_num_layers; i ++) {
        if(i == 0) {
            _layers->push_back(new Layer(this->_input_unit, this->_layer_unit));
        } else if(i == this->_num_layers - 1) {
            _layers->push_back(new Layer(this->_layer_unit, this->_output_unit));
        } else {
            _layers->push_back(new Layer(this->_layer_unit, this->_layer_unit));
        }
    }
    return 0;
}

double** affine_forward(double** a, Layer* layer) {
    return NULL;
}

double** relu_forward(double** z) {
    return NULL;
}

double** cross_entropy(double** f, double** a) {
    return NULL;
} 

double** affine_backward(double** df, double** a, Layer* layer) {
    return NULL;
}

double** relu_backward(double** df, double** a, Layer* layer, double** a_prev) {
    return NULL;
}

void Network::test() {
    std::cout <<"num layers: ";
    std::cout << _layers->size() <<std::endl;
}
