#include <iostream>

using namespace std;

int main()
{
    bool flag = 0;
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << endl;


    int *arr = (int *)malloc(n * sizeof(int)); // float char types
    cout << "Enter the elements of the array" << endl;
    char check[1];



    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        
        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}