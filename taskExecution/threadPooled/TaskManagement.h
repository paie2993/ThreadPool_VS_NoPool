#pragma once

#include "../../threadPool/ThreadPool.h"

void startTask(
        const int &offset,
        const int &jump,
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        ThreadPool *threadPool
);

long long coordinateTasksThreadPool(
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        const int &numberOfTasks
);