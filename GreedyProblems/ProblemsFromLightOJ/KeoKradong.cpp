#include <bits/stdc++.h>
using namespace std;

bool canDivide(const vector<int>& distances, int maxDist, int days)
{
    int dayCount = 1;
    int currentDist = 0;
    for (int i = 0; i < distances.size(); i++)
    {
        if (currentDist + distances[i] > maxDist)
        {
            dayCount++;
            currentDist = distances[i];
            if (dayCount > days)
            {
                return false;
            }
        }
        else
        {
            currentDist += distances[i];
        }
    }
    return true;
}

void print(vector<int> distances, int maxDist, int days)
{
    int usedDays = 0;
    int currentDist = 0;
    vector<int> result;
    for (int i = 0; i < distances.size(); i++)
    {
        if (currentDist + distances[i] > maxDist || distances.size() - result.size() - 1 + usedDays < days)
        {
            result.push_back(currentDist);
            usedDays++;
            currentDist = distances[i];
        }
        else
        {
            currentDist += distances[i];
        }
    }
    result.push_back(currentDist);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}

int main()
{
    int c;
    cout << "Enter the number of cases: ";
    cin >> c;

    for (int i = 1; i <= c; i++)
    {
        int distance, night;
        cout << "Enter the number of campsites and number of nights for test case " << i << ": ";
        cin >> distance >> night;

        vector<int> distances(distance + 1);
        cout << "Enter the distances between consecutive campsites for test case " << i << ":\n";
        for (int j = 0; j <= distance; j++)
        {
            cin >> distances[j];
        }

        int left = *max_element(distances.begin(), distances.end());
        int right = accumulate(distances.begin(), distances.end(), 0);
        int minMaxdist = right;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (canDivide(distances, mid, night + 1))
            {
                minMaxdist = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << "Case " << i << ": Minimum maximum distance will be: " << minMaxdist << endl;
        print(distances, minMaxdist, night + 1);
    }

    return 0;
}
