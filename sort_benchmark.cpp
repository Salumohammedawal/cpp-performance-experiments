#include<iostream>
#include<chrono>
#include<cstdlib>
#include<algorithm>
#include <vector>
#include <string_view>
#include <iomanip>

enum class sortAlgorithm {
    BubbleSort,
    SelectionSort,
    StdSort,
};
constexpr std::string_view getAlgorithmName(sortAlgorithm algo) {
    switch(algo) {
        case sortAlgorithm::BubbleSort:    return "Bubble Sort";
        case sortAlgorithm::SelectionSort: return "Selection Sort";
        case sortAlgorithm::StdSort:       return "std::sort";
        default:                           return "Unknown";
    }
}
struct BenchmarkResult {
    sortAlgorithm algorithm;
    int arraySize;
    long long time;
};



void BubbleSort(std::vector<int>& arr) {
    for (int i = 0; i < static_cast<int>(arr.size()) - 1; i++) {
        for (int j = 0; j < static_cast<int>(arr.size()) - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
             }
        }
    }
}
void SelectionSort(std::vector<int>& arr) {
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void AlgSort(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
}

int main() {
    std::vector<int> numbers{};
    std::vector<BenchmarkResult> result{};
    result.reserve(3);
    numbers.reserve(100000);
    for(int i = 0; i < 100000; i++) {
    numbers.push_back(rand() % 100000);
    }

    auto start = std::chrono::high_resolution_clock::now();
    BubbleSort(numbers);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    result.push_back({sortAlgorithm::BubbleSort, 100000, duration.count()});

    numbers.clear();
    for(int i = 0; i < 100000; i++) {
    numbers.push_back(rand() % 100000);
    }


    auto start1 = std::chrono::high_resolution_clock::now();
    SelectionSort(numbers);
    auto end1 =  std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    
    result.push_back({sortAlgorithm::SelectionSort, 100000, duration1.count()});

    numbers.clear();
    for(int i = 0; i < 100000; i++) {
    numbers.push_back(rand() % 100000);
    }

    auto start2 = std::chrono::high_resolution_clock::now();
    AlgSort(numbers);
    auto end2 =  std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    
    result.push_back({sortAlgorithm::StdSort, 100000, duration2.count()});

    std::cout << std::left << std::setw(20) << "Algorithm" 
          << std::setw(12) << "Size" 
          << std::setw(12) << "Time (ms)" << '\n';

    
    std::cout << std::string(44, '-') << '\n';
    for (const BenchmarkResult& r : result) {
        std::cout << std::left << std::setw(20) << getAlgorithmName(r.algorithm)
          << std::setw(12) << r.arraySize
          << std::setw(12) << r.time << '\n';
    }
    
    
    return 0;

}