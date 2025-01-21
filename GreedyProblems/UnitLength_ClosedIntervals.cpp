#include <bits/stdc++.h>
using namespace std;

void UnitLengthIntervals(vector<double> points)
{
    sort(points.begin(), points.end());

    double value = -1.0;

    cout << "The smallest set of unit-length closed intervals:" << endl;
    for (int i = 0; i < points.size(); ++i)
    {
        if (points[i] > value)
        {
            cout << "[" << points[i] << ", " << points[i] + 1.0 << "]" << endl;
            value = points[i] + 1.0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of total points: ";
    cin >> n;
    vector<double> points;
    double x;

    cout << "Enter the points: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        points.push_back(x);
    }

    UnitLengthIntervals(points);

    return 0;
}
