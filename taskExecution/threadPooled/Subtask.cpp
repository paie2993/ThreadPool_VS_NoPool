//
// Created by PopescuAd on 11/7/2022.
//

#include "../../matrixManagement/MatrixOperations.h"
#include "../../threadPool/ThreadPool.h"

void launchSubtask(
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        int firstMatrixLine,
        int secondMatrixColumn,
        int dimension,
        ThreadPool *threadPool
) {
    threadPool->enqueue([firstMatrix, secondMatrix, resultMatrix, firstMatrixLine, secondMatrixColumn, dimension]() {
        assignMatrixElement(firstMatrix, secondMatrix, resultMatrix, firstMatrixLine, secondMatrixColumn, dimension);
    });
}