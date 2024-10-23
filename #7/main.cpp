#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include "array_utils.h"

int main() {
    try {
        const size_t arrSize = 10;
        int* arr = sh::arr::GetRandArray(arrSize, 50);
        
        ds::Stack stack;
        ds::Queue queue;

        for (size_t it = 0; it < arrSize; it++) {
            stack.Push(arr[it]);
            queue.Push(arr[it]);
        }

        std::cout << "Stack pop: " << std::endl;

        for (size_t it = 0; it < arrSize; it++) {
            std::cout << "[" << stack.Pop() << "] ";
        }

        std::cout << std::endl << std::endl << "Queue pop: " << std::endl;

        for (size_t it = 0; it < arrSize; it++) {
            std::cout << "[" << queue.Pop() << "] ";
        }
    }
    catch (const std::exception& ex) {
        std::cerr << std::endl << ex.what() << std::endl;
        return 1;
    }
    
    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}