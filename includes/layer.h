/**
 * @file layer.h
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief header file for layer object
 */

#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "linalg.h"

/**
 * @brief Layer object
 * the layer object contains nodes 
 */

class Layer {
    public:
        Layer(int _input_unit, int _output_unit);
        inline friend std::ostream& operator<< (std::ostream &out, const Layer & layer) {
            out << "_nodes is: " << std::endl;
            out << *layer._nodes<< std::endl;
            out << "_bias is: " << std::endl;
            out << *layer._bias << std::endl;
            return out;
        }
        matrix* _nodes;
        vector* _bias;
    private:
        int _input_unit;
        int _output_unit;
        //! Initializes appropriate member variables
        int _init_layer();
};

#endif
