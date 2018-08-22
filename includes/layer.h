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

/**
 * @brief Layer object
 * the layer object contains nodes 
 */

class Layer {
    public:
        Layer();
        friend std::ostream& operator<< (std::ostream &out, const Layer & layer) {
            out << "First element is: ";
            out << (*(layer._nodes))[0] << std::endl;
            return out;
        }
    private:
        std::vector<int>* _nodes;
        //! Initializes appropriate member variables
        int _init_layer();
};

#endif
