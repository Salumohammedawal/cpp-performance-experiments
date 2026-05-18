# C++ Performance Experiments

A repository documenting performance engineering experiments in C++.

---

## Experiment 1: Sorting Algorithm Benchmark (C-style arrays)

Comparing the real-world performance of three sorting algorithms on random integer arrays using C-style arrays.

### Results

| Algorithm      | 10,000 elements | 100,000 elements |
|----------------|-----------------|------------------|
| Bubble Sort    | 266ms           | 33,255ms         |
| Selection Sort | 141ms           | 13,828ms         |
| std::sort      | 2ms             | 23ms             |

### Key Insight

Array size increased 10x. Bubble sort got 125x slower. std::sort got 11x slower. This is O(n²) vs O(n log n) made visible through measurement.

---

## Experiment 2: Sorting Algorithm Benchmark (std::vector)

Same experiment rebuilt using std::vector with reserve, a BenchmarkResult struct, and a SortAlgorithm enum class.

### Results

| Algorithm      | 100,000 elements |
|----------------|------------------|
| Bubble Sort    | 28,287ms         |
| Selection Sort | 14,922ms         |
| std::sort      | 5ms              |

### Key Insight

Switching from C-style arrays to std::vector with reserve produced no meaningful performance difference — the algorithm is the bottleneck, not the container.

---

## Experiment 3: Copy Cost Benchmark

Comparing the cost of passing a 100,000 element vector by value versus by const reference, called 10,000 times each.

### Results

| Method              | Total Time (10,000 calls) |
|---------------------|---------------------------|
| Pass by value       | 158ms                     |
| Pass by const ref   | 0.031ms                   |

### Key Insight

Passing by const reference is roughly 5,000x faster than passing by value for a large vector. The copy is the cost — not the computation. Every function that takes a large object by value is silently paying this price on every call.

---

## Environment
- Compiler: g++ with -std=c++20 and -O2
- OS: Windows
- CPU: AMD Ryzen 5 Pro
