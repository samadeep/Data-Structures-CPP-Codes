#include <iostream>
#include <vector>

using namespace std;

// This function partitions the array around a pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // choose the last element as pivot
    int i = low - 1; // initialize index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]); // swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // swap arr[i + 1] and arr[high]
    return i + 1;
}

// This function implements Quick Sort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high); // partition the array
        quickSort(arr, low, p - 1); // recursively sort left sub-array
        quickSort(arr, p + 1, high); // recursively sort right sub-array
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9}; // initialize the array
    int n = arr.size(); // get the size of the array

    quickSort(arr, 0, n - 1); // sort the array

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // print the sorted array
    }
    cout << endl;

    return 0;
}
