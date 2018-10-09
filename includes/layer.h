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
#include "linalg.h"

/**
 * @brief Layer object
 * the layer object contains nodes 
 */

class Layer {
    public:
        Layer(int _input_unit, int _output_unit);
        friend std::ostream& operator<< (std::ostream &out, const Layer & layer) {
            out << "First element is: ";
            out << (*(layer._nodes))[0] << std::endl;
            return out;
        }
    private:
        std::vector<double>* _nodes;
        std::vector<double>* _bias;
        int _input_unit;
        int _output_unit;
        //! Initializes appropriate member variables
        int _init_layer();
};

#endif
