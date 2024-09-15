#include "array_utils.h"
#include "math_utils.h"

int* sh::GetRandArray(int size, int max) {
    int* arr = new int[size + 1];
    arr[0] = size;

    for (int i = 1; i <= size; i++) {
        arr[i] = sh::math::GetRandomInt(0, max);
    }

    return arr;
}

int** sh::GetRandMatrixRandRows(int rows, int max) {
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        int size = sh::math::GetRandomInt(0, max);
        matrix[i] = sh::GetRandArray(size, max);
    }

    return matrix;
}

int** sh::GetRandSquareMatrix(int size, int max) {
    int** matrix = new int* [size];

    for (int i = 0; i < size; i++) {
        matrix[i] = sh::GetRandArray(size, max);
    }

    return matrix;
}

void sh::FreeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int* sh::FillRightDiagonals(int** matrix, int n) {
    int* arr = new int[n * n], idx = 0;

    for (int sum = 0; sum <= 2 * (n - 1); ++sum) {
        for (int i = 0; i <= sum; ++i) {
            int j = sum - i;

            if (i < n && j < n) {
                arr[idx++] = matrix[i][j];
            }
        }
    }

    return arr;
}

int* sh::FillLeftDiagonals(int** matrix, int n) {
    int* arr = new int[n * n], idx = 0;

    for (int diff = -(n - 1); diff <= (n - 1); ++diff) {
        for (int i = 0; i < n; ++i) {
            int j = i - diff;

            if (j >= 0 && j < n) {
                arr[idx++] = matrix[i][j];
            }
        }
    }

    return arr;
}

int* sh::FillSpiralFromCenter(int** matrix, int n) {
    int* arr = new int[n * n], center = n / 2, idx = 0;

    arr[idx++] = matrix[center][center];

    for (int layer = 1; layer <= center; ++layer) {
        for (int i = 0; i < layer * 2; ++i) {
            arr[idx++] = matrix[center - layer + i][center + layer];
        }

        for (int i = 0; i < layer * 2; ++i) {
            arr[idx++] = matrix[center + layer][center + layer - i];
        }

        for (int i = 0; i < layer * 2; ++i) {
            arr[idx++] = matrix[center + layer - i][center - layer];
        }

        for (int i = 0; i < layer * 2; ++i) {
            arr[idx++] = matrix[center - layer][center - layer + i];
        }
    }

    return arr;
}

int* sh::FillSpiralFromTopLeft(int** matrix, int n) {
    int* arr = new int[n * n], idx = 0;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            arr[idx++] = matrix[top][i];
        }

        top++;

        for (int i = top; i <= bottom; ++i) {
            arr[idx++] = matrix[i][right];
        }

        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                arr[idx++] = matrix[bottom][i];
            }

            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                arr[idx++] = matrix[i][left];
            }

            left++;
        }
    }

    return arr;
}