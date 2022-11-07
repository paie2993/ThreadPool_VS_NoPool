#pragma once

#include "../../threadPool/ThreadPool.h"

void launchSubtask(
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        int firstMatrixLine,
        int secondMatrixColumn,
        int dimension,
        ThreadPool *threadPool
);