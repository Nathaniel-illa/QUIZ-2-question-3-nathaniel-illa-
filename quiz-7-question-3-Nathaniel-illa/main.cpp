#include "main.hpp"

// Helper function to partition the array
int partition(int numbers[], int low, int high) {
    int pivot = numbers[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (numbers[j] <= pivot) {
            i++;
            swap(numbers[i], numbers[j]);
        }
    }
    swap(numbers[i + 1], numbers[high]);
    return i + 1;
}

// Quickselect function to find the n-th smallest element
int quickselect(int numbers[], int low, int high, int n) {
    if (low == high) {
        return numbers[low];
    }

    int pivotIndex = partition(numbers, low, high);
    if (n == pivotIndex) {
        return numbers[n];
    } else if (n < pivotIndex) {
        return quickselect(numbers, low, pivotIndex - 1, n);
    } else {
        return quickselect(numbers, pivotIndex + 1, high, n);
    }
}

int find_n_th(int numbers[], int LENGTH, int n) {
    // Check for valid input
    if (n < 1 || n > LENGTH) {
        cerr << "Invalid value of n: " << n << endl;
        return -1;
    }
    // Find the n-th smallest element (n-1 index in 0-based indexing)
    int result = quickselect(numbers, 0, LENGTH - 1, n - 1);
    // Place the n-th smallest element at index (n-1) and shuffle the rest
    int temp = numbers[n - 1];
    numbers[n - 1] = result;
    result = temp;
    return result;
}

void printArray(int numbers[], int N) {
    for (int i = 0; i < N; i++)
        cout << numbers[i] << "\t";
    cout << endl;
}
