#include <iostream>
#include <vector>

using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;

    // Helper functions to get parent, left child and right child indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Helper function to maintain Max Heap property
    void maxHeapify(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest]) {
            largest = l;
        }

        if (r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxPriorityQueue() {}

    // Function to insert an element into the Max Priority Queue
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Function to get the maximum element from the Max Priority Queue
    int getMax() {
        if (heap.empty()) {
            cerr << "Max Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Function to remove the maximum element from the Max Priority Queue
    void removeMax() {
        if (heap.empty()) {
            cerr << "Max Priority Queue is empty!" << endl;
            return;
        }
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        maxHeapify(0);
    }

    // Function to check if the Max Priority Queue is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Function to get the size of the Max Priority Queue
    int size() {
        return heap.size();
    }

    // Function to print the contents of the Max Priority Queue
    void print() {
        if (heap.empty()) {
            cerr << "Max Priority Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
        
    MaxPriorityQueue pq;
    int n ;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;

    int var;

    while(n--)
    {
        cin>>var;
        pq.insert(var);
    }

    cout << "Max element: " << pq.getMax() << endl;

    cout<<"Remaining Priority Queue"<<endl;
    pq.print();

    pq.removeMax();
    cout << "Max element: " << pq.getMax() << endl;
    cout<<"Remaining Priority Queue"<<endl;
    pq.print();

    pq.removeMax();
    cout << "Max element: " << pq.getMax() << endl;
    cout<<"Remaining Priority Queue"<<endl;
    pq.print();

    return 0;
}
