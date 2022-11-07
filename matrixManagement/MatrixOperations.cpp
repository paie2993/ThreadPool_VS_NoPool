//
// Created by PopescuAd on 11/7/2022.
//

#include "MatrixOperations.h"

//assume the two matrices have the same dimension
int computeMatrixElement(
        int **firstMatrix,
        int **secondMatrix,
        int firstMatrixLine,
        int secondMatrixColumn,
        int dimension
) {
    int accumulator = 0;
    for (int current = 0; current < dimension; current++) {
        int pointWiseProduct = firstMatrix[firstMatrixLine][current] * secondMatrix[current][secondMatrixColumn];
        accumulator = accumulator + pointWiseProduct;
    }
    return accumulator;
}

void assignMatrixElement(
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        int firstMatrixLine,
        int secondMatrixColumn,
        int dimension
) {
    int matrixElement = computeMatrixElement(firstMatrix, secondMatrix, firstMatrixLine, secondMatrixColumn, dimension);
    resultMatrix[firstMatrixLine][secondMatrixColumn] = matrixElement;
}
