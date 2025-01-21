#include <bits/stdc++.h>
using namespace std;

bool isValidPageOrder(int p, vector<int> pages)
{
    vector<int> counts(p, 0);
    for (int i = 0; i < p; ++i)
    {
        if (pages[i] < 0 || pages[i] >= p)
        {
            return false;
        }
        counts[pages[i]]++;
    }
    for (int i = 0; i < p; ++i)
    {
        if (counts[i] != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cout << "Enter the number of cases: ";
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        int p;
        cout << "Enter how many pages are there: ";
        cin >> p;
        vector<int> pages(p);
        cout << "Enter the page numbers: ";
        for (int i = 0; i < p; ++i)
        {
            cin >> pages[i];
        }
        cout << "Case " << T << ": ";
        if (isValidPageOrder(p, pages))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}
