#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int target)
{
    bool dp[100][100] = {false};

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int sum = 1; sum <= target; sum++)
        {
            if (arr[i] > sum)
            {
                dp[i][sum] = dp[i - 1][sum];
            }
            else
            {
                dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i]];
            }
        }
    }

    if (dp[n][target])
    {
        int i = n, sum = target;
        vector<int> subset;

        while (i > 0 && sum > 0)
        {
            if (dp[i][sum] != dp[i - 1][sum])
            {
                subset.push_back(arr[i]);
                sum -= arr[i];
            }
            i--;
        }

        cout << "Subset that sums to " << target << ": ";
        for (int x : subset)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return dp[n][target];
}

int main()
{
    int n, target;

    cout << "Enter the array size : ";
    cin >> n;

    int arr[n + 1];
    arr[0] = 0;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    if (subsetSum(arr, n, target))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
