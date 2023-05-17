#include <iostream>
using namespace std;
#define SIZE 30

template <class T>
class Queue
{
    T *arr = (T *)malloc(0 * sizeof(T));
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = SIZE)
    {
        front = -1;
        rear = -1;
        capacity = size;
        count = 0;
        arr = (T *)realloc(arr, capacity * sizeof(T));
    }

    void push(T val)
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if ((rear == capacity and front == 1) or front == rear + 1)
        {
            cout << "Overflow" << endl;
            exit(EXIT_FAILURE);
        }
        else if (rear == capacity)
        {
            rear = 0;
        }

        else
            rear++;

        arr[rear] = val;
    }

    T pop()
    {
        T ret = arr[front];

        if (front == rear)
        {
            rear = -1;
            front = -1;
            cout << "Queue is Already Empty"<<endl;
            exit(EXIT_FAILURE);
        }
        if (front == capacity)
        {
            front = 0;
        }
        else
            front++;

        return ret;
    }

    void Print()
    {
        // cout<<front<<" "<<rear<<endl;
        if (front == rear)
        {
            cout<<arr[front]<<" "<<endl;
            cout << "Queue is Empty" << endl;
        }

        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    Queue<int> Q(10); //Initialised a Queue of Size 10 using a Class Template

    for(int i=1;i<5;i++)
    {
        Q.push(i*10);
    }

   Q.Print();
   cout<<endl;

   //POP Operation
   for(int i=1;i<=5;i++)
   {
    cout<<"Popped Element: "<<Q.pop()<<endl;
    cout<<"Queue is now"<<endl;
    Q.Print();
    cout<<endl;

   }

   return 0;
}