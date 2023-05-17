#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<double> time_taken;
vector<double> input_size;

void solve()
{
    // cout << "Enter the number of elements you want to test for" << endl;
    int n;
    cin >> n;
    input_size.push_back(n);

    // populating the array
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    // QuadraticAverage(arr,n);
    float average = 0;
    float sum = 0;
    double a[n];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        average = sum / (i + 1);
        a[i] = average;
    }

    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";

    // cout << endl;

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds"
       << "\n";

    time_taken.push_back((double)duration.count());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // cout<<"Enter the number of times to repeat Experiment"<<endl;
    int n;
    cin >> n;

    while (n--)
    {
        solve();
    }

    for (int i = 0; i < time_taken.size(); i++)
    {
        cout << input_size[i] << " items -->" << time_taken[i] << " microseconds" << endl;
        ;
    }

    cout << "\n\n";

    return 0;
}