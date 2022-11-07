//
// Created by PopescuAd on 11/7/2022.
//

#include <thread>
#include <vector>
#include "./Subtask.h"
#include "./ThreadsManagement.h"

void startTask(
        const int &offset,
        const int &jump,
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix
) {
    std::vector<std::thread *> threads;

    for (int index = offset; index < dimension * dimension; index = index + jump) {
        int line = index / dimension;
        int column = index % dimension;

        std::thread *thread =
                launchSubtask(firstMatrix, secondMatrix, resultMatrix, line, column, dimension);

        threads.push_back(thread);
    }

    joinThreads(threads);
    deallocateThreads(threads);
}

long long coordinateTasksNoThreadPool(
        const int &dimension,
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        const int &numberOfTasks
) {
    std::vector<std::thread *> threads;
    auto start = std::chrono::system_clock::now();

    for (int offset = 0; offset < numberOfTasks; offset++) {
        auto *thread = new std::thread([offset, numberOfTasks, dimension, firstMatrix, secondMatrix, resultMatrix]() {
            startTask(offset, numberOfTasks, dimension, firstMatrix, secondMatrix, resultMatrix);
        });
        threads.push_back(thread);
    }

    joinThreads(threads);
    auto end = std::chrono::system_clock::now();
    deallocateThreads(threads);

    auto elapsed = end - start;
    return elapsed.count();
}
