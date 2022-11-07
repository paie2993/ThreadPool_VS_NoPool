#pragma once

void startTask(
        const int &offset,
        const int &jump,
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix
);

long long coordinateTasksNoThreadPool(
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        const int &numberOfTasks
);