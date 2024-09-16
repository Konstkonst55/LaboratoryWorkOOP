#include "array_utils.h"
#include "math_utils.h"
#include <vector>

int* sh::arr::GetRandArrayWithSize(int size, int max) {
    int* arr = new int[size + 1];
    arr[0] = size;

    for (int i = 1; i <= size; i++) {
        arr[i] = sh::math::GetRandomInt(0, max);
    }

    return arr;
}

int* sh::arr::GetRandArray(int size, int max) {
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = sh::math::GetRandomInt(0, max);
    }

    return arr;
}

int** sh::arr::GetRandMatrixRandRows(int rows, int max) {
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        int size = sh::math::GetRandomInt(0, max);
        matrix[i] = sh::arr::GetRandArray(size, max);
    }

    return matrix;
}

int** sh::arr::GetRandSquareMatrix(int size, int max) {
    int** matrix = new int* [size];

    for (int i = 0; i < size; i++) {
        matrix[i] = sh::arr::GetRandArray(size, max);
    }

    return matrix;
}

void sh::arr::FreeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int* sh::arr::FillRightDiagonals(int** matrix, int n) {
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

int* sh::arr::FillLeftDiagonals(int** matrix, int n) {
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

int* sh::arr::FillSpiralFromCenter(int** matrix, int n) {
    int* arr = new int[n * n];
    int y = -1, x = 0, dir = 1, counter = n * n;
    const int modifier = -1;

    for (int i = 0; i < n;) {
        for (int j = i; j < n; j++) {
            y += dir;
            arr[counter += modifier] = matrix[x][y];
        }

        i++;

        for (int j = i; j < n; j++) {
            x += dir;
            arr[counter += modifier] = matrix[x][y];
        }

        dir *= modifier;
    }

    return arr;
}

int* sh::arr::FillSpiralFromTopLeft(int** matrix, int n) {
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