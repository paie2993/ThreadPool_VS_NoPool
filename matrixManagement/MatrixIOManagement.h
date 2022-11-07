#pragma once

#include <string>

int readDimension(const std::string &fileName);

void readMatrix(int **matrix, int dimension, const std::string &fileName);

void printMatrix(int **matrix, int dimension);