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
    _training_data = new std::vector<std::vector<double>>();
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

matrix* Network::affine_forward(matrix* a, Layer* layer) {
    matrix* z = matmat_multiply(a, layer->_nodes);
    for(size_t i = 0; i < z->row; i ++) {
        for(size_t j = 0; j < z->col; j ++) {
            MAT(z, i, j) += VEC(layer->_bias, j);
        }
    }
    return z;
}

matrix* Network::relu_forward(matrix* z) {
    matrix* a = matrix_create(z->row, z->col);
    for(size_t i = 0; i < a->row; i ++) {
        for(size_t j = 0; j < a->col; j ++) {
            if(MAT(z, i, j) > 0) {
                MAT(a, i, j) = MAT(z, i, j);
            } else {
                MAT(a, i, j) = 0;
            }
        }
    }
    return a;
}

matrix* Network::cross_entropy(matrix* f, matrix* a) {
    matrix* df = matrix_create(f->row, f->col);
    for(size_t i = 0; i < df->row; i ++) {
        for(size_t j = 0; j < df->col; j ++) {
            double curval = -1.0 / a->row;
            double sum_scores = 0.0;
            for(size_t k = 0; k < f->col; k ++) {
                sum_scores += exp(MAT(f, i, k) / sum_scores);
            }
            if(j == MAT(a, i, a->col)) {
                curval *= (1 - exp(MAT(f, i, j) / sum_scores));
            } else {
                curval *= (0 - exp(MAT(f, i, j) / sum_scores));
            }
            MAT(df, i, j) = curval;
        } 
    }
    return df;
} 

void** Network::affine_backward(matrix* df, matrix* a, Layer* layer) {
    matrix* w_t = mat_transpose(layer->_nodes);
    matrix* da = matmat_multiply(df, w_t);
    matrix* a_t = mat_transpose(a);
    matrix* dw = matmat_multiply(a_t, df);
    vector* db = vector_create(df->col);
    for(size_t i = 0; i < df->col; i ++) {
        double curdbval = 0.0;
        for(size_t j = 0; j < df->row; i ++) {
            curdbval += MAT(df, j, i);
        }
        VEC(db, i) = curdbval;
    } 
    void** retarr = (void**)malloc(sizeof(void*) * 3);
    retarr[0] = malloc(sizeof(matrix*));
    retarr[1] = malloc(sizeof(matrix*));
    retarr[2] = malloc(sizeof(vector*));
    retarr[0] = da;
    retarr[1] = dw;
    retarr[2] = db;
    return retarr;
}

matrix* Network::relu_backward(matrix* da, matrix* a_prev) {
    matrix* dz = matrix_create(da->row, da->col);
    for(size_t i = 0; i < da->row; i ++) {
        for(size_t j = 0; j < da->col; j ++) {
            if(MAT(a_prev, i, j) > 0) {
                MAT(dz, i, j) = MAT(da, i, j);
            } else {
                MAT(dz, i, j) = 0;
            }
        }
    }
    return dz;
}

int Network::import_data(std::string filename) {
    std::ifstream input_file(filename, std::ifstream::in);
    std::vector<double> vec;
    double d = 0.0;
    int counter = 0;
    while(input_file >> d) {
        vec.push_back(d);
        counter ++;
        if(counter > this->_input_unit) {
            counter = 0;
            this->_training_data->push_back(vec);
            vec.clear();
        }
    } 
    input_file.close();
    return this->_training_data->size(); 
}

int Network::train_network() {
    auto random_engine = std::default_random_engine {};
    for(int i = 0; i < this->_EPOCH; i ++) {
        std::shuffle((*(this->_training_data)).begin(),
                     (*(this->_training_data)).end(), random_engine);
        for(int j = 0; j < this->_input_unit / this->_BATCH_SIZE; j ++) {
            matrix* current_batch = matrix_create(this->_BATCH_SIZE,
                                                  this->_input_unit + 1);
            for(int k = 0; k < this->_BATCH_SIZE; k ++) {
                for(int l = 0; l < this->_input_unit + 1; l ++) {
                    MAT(current_batch, k, l) = ((*(this->_training_data))[k])[l];
                }
            }
            update_layers(current_batch);
        }
    }
    return 0;
}

double Network::update_layers(matrix* current_batch) {
    
    return 0.0;
}

void Network::test() {
    std::cout <<"num layers: ";
    std::cout << this->_layers->size() <<std::endl;
    std::cout <<"layers: ";
    for(size_t i = 0; i < this->_layers->size(); i ++) {
        std::cout << *((*(this->_layers))[i]) << std::endl;
    }

}
