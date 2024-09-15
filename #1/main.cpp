#include <array_utils.h>
#include <printers.h>
#include <math_utils.h>

#include <iostream>

void task1() {
    int size = sh::math::GetRandomInt(1, 20), max = 100, * arr = sh::GetRandArray(size, max);

    sh::pr::PrintArray(arr);

    delete[] arr;
}

void task2() {
    int rows = sh::math::GetRandomInt(1, 20), max = 20, **matrix = sh::GetRandMatrix(rows, max);

    std::cout << rows << " rows" << std::endl;
    sh::pr::PrintMatrix(matrix, rows);

    sh::FreeMatrix(matrix, rows);
}

int main() {
    task2();
}