/**
 * @file network.h
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief header file for network object
 */

#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <iostream>
#include "layer.h"

/**
 * @brief Network object
 * the network object acts as a layer between the 
 * user and the input,hidden, and output layers
 */

class Network {
    public:
        //! Constructor that calls _init_network
        Network(int _num_layers, int _input_unit, int _layer_unit, int _output_unit);
        matrix* affine_forward(matrix* a, Layer* layer);
        matrix* relu_forward(matrix* z);
        matrix* cross_entropy(matrix* f, matrix* a);
        matrix* affine_backward(matrix* df, matrix* a, Layer* layer);
        matrix* relu_backward(matrix* df, matrix* a, Layer* layer, matrix* a_prev); 
        void test();
    private:
        std::vector<Layer*>* _layers;
        int _num_layers;
        int _input_unit;
        int _layer_unit;
        int _output_unit;
        //! Initializes appropriate member variables
        int _init_network();
};

#endif
