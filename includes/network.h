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
        double** affine_forward(double** a, Layer* layer);
        double** relu_forward(double** z);
        double** cross_entropy(double** f, double** a);
        double** affine_backward(double** df, double** a, Layer* layer);
        double** relu_backward(double** df, double** a, Layer* layer, double** a_prev); 
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
