#include<iostream>
#include<chrono>
#include<cstdlib>
#include<algorithm>

void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
             }
        }
    }
}
void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void AlgSort(int arr[], int size) {
    std::sort(arr, arr + size);
}

int main() {
    int x{100000};
    int arr[x];
    for (int i = 0; i < x; i++) {
        arr[i] = rand() % 100000;
    }
    auto start = std::chrono::high_resolution_clock::now();
    BubbleSort(arr, x);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Bubble Sort: " << duration.count() << " milliseconds" << '\n';

    for (int i = 0; i < x; i++) {
        arr[i] = rand() % 100000;
    }


    auto start1 = std::chrono::high_resolution_clock::now();
    SelectionSort(arr, x);
    auto end1 =  std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "Selection sort: " << duration1.count() << " milliseconds" << '\n';

    for (int i = 0; i < x; i++) {
        arr[i] = rand() % 100000;
    }

    auto start2 = std::chrono::high_resolution_clock::now();
    AlgSort(arr, x);
    auto end2 =  std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "std::sort: " << duration2.count() << " milliseconds" << '\n';
    
    return 0;

}