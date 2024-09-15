#include "printers.h"

#include <iostream>

void sh::pr::PrintArrayWithSize(int* arr) {
    std::cout << arr[0] << ": ";

    for (int i = 1; i <= arr[0]; i++) {
        std::cout << arr[i] << " ";
    }
}

void sh::pr::PrintArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

void sh::pr::PrintMatrixWithSize(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        int size = matrix[i][0];
        std::cout << size << ": ";

        for (int j = 1; j <= size; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void sh::pr::PrintSquareMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << "\t";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}