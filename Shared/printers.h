#pragma once 

#ifndef PRINTERS_H
#define PRINTERS_H

namespace sh {
	namespace pr {
		void PrintArrayWithSize(int* arr);
		void PrintArray(int* arr, int size);
		void PrintMatrixWithSize(int** matrix, int rows);
		void PrintSquareMatrix(int** matrix, int size);
	}
}

#endif // !PRINTERS_H