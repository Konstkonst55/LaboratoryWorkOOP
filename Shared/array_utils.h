#pragma once

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

namespace sh {
    int* GetRandArray(int size, int max);
    int** GetRandMatrixRandRows(int rows, int max);
    int** GetRandSquareMatrix(int size, int max);
    void FreeMatrix(int** matrix, int rows);

    int* FillRightDiagonals(int** matrix, int n);
    int* FillLeftDiagonals(int** matrix, int n);
    int* FillSpiralFromCenter(int** matrix, int n);
    int* FillSpiralFromTopLeft(int** matrix, int n);
}

#endif // ARRAY_UTILS_H