#include <bits/stdc++.h>
using namespace std;

#define INF -999999

int rodCutting(int n, vector<int> price, vector<int>& cuts)
{
    vector<int> maxx(n + 1);
    maxx[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        maxx[i] = INF;
        for (int j = 1; j <= i; j++)
        {
            if (price[j] + maxx[i - j] > maxx[i])
            {
                maxx[i] = price[j] + maxx[i - j];
                cuts[i] = j;
            }
        }
    }

    return maxx[n];
}

int main()
{
    int n;
    cout << "Enter the rod size: " << endl;
    cin >> n;

    cout << "Enter the price for each cut : " << endl;
    vector<int> price(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }

    vector<int> cuts(n + 1, 0);
    int maxprofit = rodCutting(n, price, cuts);

    cout << "Maximum profit: " << maxprofit << endl;

    cout << "Cuts taken: ";
    int length = n;
    while (length > 0)
    {
        cout << cuts[length] << " ";
        length -= cuts[length];
    }
    cout << endl;

    return 0;
}
