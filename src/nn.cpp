/**
 * @file nn.cpp
 * @author Minhyuk Park
 * @date 8 Jun 2018
 * @brief File with int main
 */

#include <iostream>
#include "network.h"
void testing_linalg() {
    vector* vec = vector_create(5);
    matrix* mat = matrix_create(5, 5);
    for(size_t i = 0; i < vec->size; i ++) {
        vec->data[i] = i;
    }
   
    for(size_t i = 0; i < mat->row * mat->col ; i ++) {
        mat->data[i] = i;
    }
   
    vector* vecmat_result = matvec_multiply(mat, vec);
    vec_print(vecmat_result);
   
    vector* matvec_result = matvec_multiply(mat,vec);
    vec_print(matvec_result);
   
    matrix* converted_vecmat = vec_to_mat(vecmat_result, 0);
    mat_print(converted_vecmat);
   
    matrix* converted_matvec = vec_to_mat(matvec_result, 1);
    mat_print(converted_matvec);
   
    matrix * matmat_result = matmat_multiply(mat,mat);
    mat_print(matmat_result);    
       
    matrix *matsub_result = matmat_subtraction(mat,mat);
    mat_print(matsub_result);      
   
    matrix *matadd_result = matmat_addition(mat,mat);
    mat_print(matadd_result);   
   
    matrix *matscaleMult_result = matscalar_multiply(mat,5);
    mat_print(matscaleMult_result);
   
    matrix *matscaleDiv_result = matscalar_divide(mat,5);
    mat_print(matscaleDiv_result);
     
    matrix *mattranspose_result = mat_transpose(mat);
    mat_print(mattranspose_result);
}

int main() {
    std::cout<<"NN start?"<<std::endl;
    Network* nn = new Network(4, 5, 256, 3);
    nn->test();
    testing_linalg();
    std::cout<<nn->import_data("training_data.txt")<<std::endl;
    nn->train_network();
    return 0;
}
