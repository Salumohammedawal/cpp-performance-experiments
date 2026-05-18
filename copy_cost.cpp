#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

void sumElem(std::vector<int> arr) {
    
}

void sumRef(const std::vector<int>& arr) {
    
}

int main() {
    std::vector<int> numbers{};
    numbers.reserve(100000);
    for(int a = 0; a < 100000; ++a) {
    numbers.push_back(rand() % 100000);
    }
    
    int result = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; ++i) {
        sumElem(numbers);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken by sumElem: " << duration.count() << " milliseconds" << std::endl;
    

    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; ++i) {
            sumRef(numbers);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);
    std::cout << "Time taken by sumRef: " << duration1.count() << " nanoseconds" << std::endl;
    

    return 0;
}