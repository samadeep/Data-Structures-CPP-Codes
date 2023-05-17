#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool is_empty() {
        return front == NULL;
    }

    void enqueue(int val) {
        Node* new_node = new Node(val);

        if (is_empty()) {
            front = new_node;
            rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else {
            int val = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            return val;
        }
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(20);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
