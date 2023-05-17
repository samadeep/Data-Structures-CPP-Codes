#include <iostream>
#include <vector>

using namespace std;

// This function implements Selection Sort algorithm
void selectionSort(vector<int>& arr) {
    
    int n = arr.size(); // get the size of the array

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // index of the minimum element

        // find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // swap the minimum element with the first element of the unsorted part
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    vector<int> arr = {51, 33, 866, 4, 22, 7, 1,3, 102, 6, 9}; // initialize the array
    int n = arr.size(); // get the size of the array

    selectionSort(arr); // sort the array

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // print the sorted array
    }
    cout << endl;

    return 0;
}
