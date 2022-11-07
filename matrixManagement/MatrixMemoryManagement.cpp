//
// Created by PopescuAd on 11/7/2022.
//

#include "MatrixMemoryManagement.h"

int **allocateMatrix(const int dimension) {
    int **matrix = new int *[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new int[dimension];
    }
    return matrix;
}

void deallocateMatrix(int **matrix, const int dimension) {
    for (int i = 0; i < dimension; i++) {
        delete matrix[i];
    }
    delete matrix;
}
