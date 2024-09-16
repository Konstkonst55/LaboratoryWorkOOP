#include <array_utils.h>
#include <printers.h>
#include <math_utils.h>

#include <iostream>

void task1() {
    int size = sh::math::GetRandomInt(1, 20), max = 100, * arr = sh::arr::GetRandArray(size, max);

    sh::pr::PrintArrayWithSize(arr);

    delete[] arr;
}

void task2() {
    int rows = sh::math::GetRandomInt(1, 20), max = 20, **matrix = sh::arr::GetRandMatrixRandRows(rows, max);

    std::cout << rows << " rows" << std::endl;
    sh::pr::PrintMatrixWithSize(matrix, rows);

    sh::arr::FreeMatrix(matrix, rows);
}

int main() {
    task2();
}