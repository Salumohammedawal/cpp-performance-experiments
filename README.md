# C++ Performance Experiments

A repository documenting performance engineering experiments in C++.

## Experiment 1: Sorting Algorithm Benchmark

Comparing the real-world performance of three sorting algorithms 
on random integer arrays.

### Results

| Algorithm      | 10,000 elements | 100,000 elements |
|----------------|-----------------|------------------|
| Bubble Sort    | 266ms           | 33,255ms         |
| Selection Sort | 141ms           | 13,828ms         |
| std::sort      | 2ms             | 23ms             |

### Key Insight

Array size increased 10x. Bubble sort got 125x slower. 
std::sort got 11x slower. This is O(n²) vs O(n log n) 
made visible through measurement.

### Environment
- Compiler: g++ with -std=c++20
- OS: Windows
- CPU: AMD Ryzen 5 Pro
