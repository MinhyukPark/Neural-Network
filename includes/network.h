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
        Network();
        void test();
    private:
        std::vector<Layer*>* _layers;
        //! Initializes appropriate member variables
        int _init_network();
};

#endif
