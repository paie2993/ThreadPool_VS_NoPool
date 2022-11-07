//
// Created by PopescuAd on 11/7/2022.
//

#include <chrono>
#include <vector>
#include "./Subtask.h"
#include "../../configuration/StaticData.h"

void startTask(
        const int &offset,
        const int &jump,
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        ThreadPool *threadPool
) {
    for (int index = offset; index < dimension * dimension; index = index + jump) {
        int line = index / dimension;
        int column = index % dimension;

        threadPool->enqueue([firstMatrix, secondMatrix, resultMatrix, line, column, dimension, threadPool]() {
            launchSubtask(firstMatrix, secondMatrix, resultMatrix, line, column, dimension, threadPool);
        });
    }
}

long long coordinateTasksThreadPool(
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        const int &numberOfTasks
) {
    auto threadPool = new ThreadPool(THREAD_POOL_SIZE);
    auto start = std::chrono::system_clock::now();

    for (int offset = 0; offset < numberOfTasks; offset++) {
        threadPool->enqueue([offset, numberOfTasks, dimension, firstMatrix, secondMatrix, resultMatrix, threadPool]() {
            startTask(offset, numberOfTasks, dimension, firstMatrix, secondMatrix, resultMatrix, threadPool);
        });
    }

    auto end = std::chrono::system_clock::now();
    delete threadPool;

    auto elapsed = end - start;
    return elapsed.count();
}
