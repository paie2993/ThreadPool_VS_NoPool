//
// Created by PopescuAd on 11/7/2022.
//

#include <thread>
#include "../../matrixManagement/MatrixOperations.h"

std::thread *launchSubtask(
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        int firstMatrixLine,
        int secondMatrixColumn,
        int dimension
) {
    return new std::thread(
            assignMatrixElement,
            firstMatrix,
            secondMatrix,
            resultMatrix,
            firstMatrixLine,
            secondMatrixColumn,
            dimension
    );
}
