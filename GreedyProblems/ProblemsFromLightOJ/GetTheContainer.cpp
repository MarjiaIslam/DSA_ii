#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &vessels, int n, int m, int maxCapacity)
{
    int containers = 1;
    int currentCapacity = 0;

    for (int i = 0; i < n; ++i)
    {
        if (vessels[i] > maxCapacity)
            return false;

        if (currentCapacity + vessels[i] > maxCapacity)
        {
            containers++;
            currentCapacity = vessels[i];

            if (containers > m)
                return false;
        }
        else
        {
            currentCapacity += vessels[i];
        }
    }

    return true;
}

int findMinimalMaxCapacity(vector<int> &vessels, int n, int m)
{
    int low = *max_element(vessels.begin(), vessels.end());
    int high = accumulate(vessels.begin(), vessels.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (isPossible(vessels, n, m, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        int n, m;
        cout << "Enter the number of vessels & containers: ";
        cin >> n >> m;

        vector<int> vessels(n);
        cout << "Enter the capacities of the vessels: ";
        for (int j = 0; j < n; ++j)
        {
            cin >> vessels[j];
        }

        int result = findMinimalMaxCapacity(vessels, n, m);
        cout << "Case " << i << ": " << result << endl;
    }

    return 0;
}
