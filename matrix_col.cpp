#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>

const int Rows = 2000;
const int Cols = 2000;

int main() {
    int array[Rows][Cols];

    // Initialize the array with random values
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            array[i][j] = rand() % 100;
        }
    }

    // Column-major traversal
    auto start = std::chrono::high_resolution_clock::now();
    int sumColMajor = 0;
    for (int j = 0; j < Cols; ++j) {
        for (int i = 0; i < Rows; ++i) {
            sumColMajor += array[i][j];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> colMajorTime = end - start;

    std::cout << "Column-major traversal time: " << colMajorTime.count() << " seconds\n";

    return 0;
}