#include <array_utils.h>
#include <printers.h>
#include <math_utils.h>

#include <cstdlib>
#include <iostream>

void task1() {
    int rows = sh::math::GetRandomInt(1, 8);
    int** matrix = sh::GetRandSquareMatrix(rows, 50);

    std::cout << "Original matrix:\n";
    sh::pr::PrintSquareMatrix(matrix, rows);

    int* a = sh::FillRightDiagonals(matrix, rows);
    std::cout << std::endl << "Elements on the right diagonals:" << std::endl;
    sh::pr::PrintArray(a, rows * rows);

    int* b = sh::FillLeftDiagonals(matrix, rows);
    std::cout << std::endl << "Elements on the left diagonals:" << std::endl;
    sh::pr::PrintArray(b, rows * rows);

    int* c = sh::FillSpiralFromCenter(matrix, rows);
    std::cout << std::endl << "Spiral elements from the center:" << std::endl;
    sh::pr::PrintArray(c, rows * rows);

    int* d = sh::FillSpiralFromTopLeft(matrix, rows);
    std::cout << std::endl << "Spiral elements from the upper left corner:" << std::endl;
    sh::pr::PrintArray(d, rows * rows);

    delete[] a, b, c, d;
    sh::FreeMatrix(matrix, rows);
}

int main() {
    task1();
}