#include <iostream>
#include <string>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    int result = 0;
    for(int i = 0; i < 1000000; ++i) {
    result += i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken by sum: " << duration.count() << " milliseconds" << '\n';
    
    auto start1 = std::chrono::high_resolution_clock::now();
    std::string res = "";
    for(int i = 0; i < 1000000; ++i) {
    res = res + "a";  
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "Time taken by string concatenation: " << duration1.count() << " milliseconds" << '\n';

    
    return 0;
}