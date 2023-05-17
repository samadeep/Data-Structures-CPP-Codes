#include <iostream>
#include <vector>

using namespace std;

// This function merges two sorted sub-arrays into one sorted array
void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // size of the left sub-array
    int n2 = r - m; // size of the right sub-array

    // create temporary arrays for left and right sub-arrays
    vector<int> L(n1), R(n2);

    // copy data to temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // merge the two arrays
    i = 0; // initial index of left sub-array
    j = 0; // initial index of right sub-array
    k = l; // initial index of merged sub-array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of L[] and R[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// This function implements Merge Sort algorithm
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // middle index
        mergeSort(arr, l, m); // recursively sort left sub-array
        mergeSort(arr, m + 1, r); // recursively sort right sub-array
        merge(arr, l, m, r); // merge the sorted sub-arrays
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9}; // initialize the array
    int n = arr.size(); // get the size of the array

    mergeSort(arr, 0, n - 1); // sort the array

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // print the sorted array
    }
    cout << endl;

    return 0;
}
