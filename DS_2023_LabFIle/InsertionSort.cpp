#include <iostream>
#include <vector>

using namespace std;

// This function implements Insertion Sort algorithm
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // get the size of the array

    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1; 

        // shift the elements that are greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // insert key into the correct position
    }
}

int main() {

    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9}; // initialize the array
    int n = arr.size(); // get the size of the array

    insertionSort(arr); // sort the array

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // print the sorted array
    }
    cout << endl;

    return 0;
}
