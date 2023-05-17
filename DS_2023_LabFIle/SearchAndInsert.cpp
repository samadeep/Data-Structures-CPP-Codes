#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    bool flag = 0;
    int n;

    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << endl;

    int *arr = (int *)malloc((n) * sizeof(int)); // float char types

    
    cout << "Enter the elements of the array" << endl;
    //    char check[1];

    int search;

    for (int i = 0; i <= n - 1; i++)
    {

        cin >> arr[i];
    }

    cout << "Enter the term to be searched: " << endl;

    cin >> search;

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

    cout << "The sorted array is as:" << endl;

    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int low = 0;
    int high = n-1;
    int mid = (low + high) /2;
    int present = 0;

    if (low == high)
    {
        if (arr[low] == search)
            present = 1;
    }

    while (low < high)
    {
        if (arr[mid] == search)
        {
            present = 1;
            cout << "No is Present at the" << mid + 1 << "location" << endl;
            break;
        }
        else if (arr[mid] < search)
        {
            low = mid + 1;
        }
        else if (arr[mid] > search)
        {
            high = mid - 1;
        }
        mid = (low + high) / 2 ;
    }

    if (present == 0)
    {
        arr = (int *) realloc(arr, (n+1)*sizeof(int));
        cout << "The required element is not present in the array" << endl;
        if (arr[n-1] <= search)
        {
            arr[n] = search;
        }
        else
        {
        cout << endl;
        cout << endl;
        //     for (int i = 0; i < n-1; i++)
        // {
        //     if (arr[i] <=search && arr[i + 1] >= search)
        //     {
        //         index_insert = i+1;
        //         break;
        //     }
        // }

        int j = n-1;

        while (j > mid)

        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[mid+1] = search;
        }
        
        cout << endl;
        cout << endl;

        cout << "The new array is as with the input search term" << endl;
        for (int i = 0; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    if(present==1)
    {
        for(int i=mid;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        cout<<"The array with removed element is as:"<<endl;
        for (int i = 0; i <= n-2; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}