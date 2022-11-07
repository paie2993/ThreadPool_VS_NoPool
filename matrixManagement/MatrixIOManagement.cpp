//
// Created by PopescuAd on 11/7/2022.
//

#include <fstream>
#include <iostream>
#include "MatrixIOManagement.h"

int readDimension(const std::string &fileName) {
    std::ifstream reader(fileName);

    int dimension;
    reader >> dimension;

    return dimension;
}

void readMatrix(int **matrix, const int dimension, const std::string &fileName) {
    std::ifstream reader(fileName);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            reader >> matrix[i][j];
        }
    }
}

void printMatrix(int **matrix, const int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
