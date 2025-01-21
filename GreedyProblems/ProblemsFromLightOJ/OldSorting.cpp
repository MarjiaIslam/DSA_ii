#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& arr)
{
    int n = arr.size();
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++)
    {
        pos[arr[i]] = i;
    }

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            swaps++;
            int temp = arr[i];
            arr[i] = arr[pos[i + 1]];
            arr[pos[i + 1]] = temp;

            pos[temp] = pos[i + 1];
            pos[arr[i]] = i;
        }
    }

    return swaps;
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Case " << tc << ": " << minSwaps(arr) << endl;
    }

    return 0;
}
