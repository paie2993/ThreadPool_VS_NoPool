#pragma once

#include <thread>

std::thread *launchSubtask(
        int **firstMatrix,
        int **secondMatrix,
        int **resultMatrix,
        int firstMatrixLine,
        int secondMatrixColumn,
        int dimension
);