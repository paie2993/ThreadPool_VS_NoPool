#include <iostream>
#include "matrixManagement/MatrixIOManagement.h"
#include "matrixManagement/MatrixMemoryManagement.h"
#include "taskExecution/threadPooled/TaskManagement.h"
#include "taskExecution/individualThreads/TaskManagement.h"
#include "configuration/StaticData.h"

int main() {
    const std::string dimensionFile = "matrices/nine_by_nine/dimension.txt";
    const std::string firstMatrixFile = "matrices/nine_by_nine/firstMatrix.txt";
    const std::string secondMatrixFile = "matrices/nine_by_nine/secondMatrix.txt";

    const int dimension = readDimension(dimensionFile);

    int **firstMatrix = allocateMatrix(dimension);
    readMatrix(firstMatrix, dimension, firstMatrixFile);

    int **secondMatrix = allocateMatrix(dimension);
    readMatrix(secondMatrix, dimension, secondMatrixFile);

    int **resultMatrix = allocateMatrix(dimension);

    long long elapsedTime = coordinateTasksThreadPool(
            dimension, firstMatrix, secondMatrix, resultMatrix, NUMBER_OF_TASKS
    );
//    long long elapsedTime = coordinateTasksNoThreadPool(
//            dimension, firstMatrix, secondMatrix, resultMatrix, NUMBER_OF_TASKS
//    );
    std::cout << "Elapsed time: " << elapsedTime << "ns" << std::endl;

    printMatrix(resultMatrix, dimension);

    deallocateMatrix(firstMatrix, dimension);
    deallocateMatrix(secondMatrix, dimension);
    deallocateMatrix(resultMatrix, dimension);
    return 0;
}
