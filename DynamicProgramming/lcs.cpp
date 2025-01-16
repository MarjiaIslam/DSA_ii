#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LongestCommonSubsequenceBottomUp(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int table[100][100];

    for (int i = 0; i <= m; i++)
    {
        table[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        table[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    vector<char> lcs;

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs.push_back(x[i - 1]);
            i--;
            j--;
        }
        else if (table[i - 1][j] >= table[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    for (int k = lcs.size() - 1; k >= 0; k--)
    {
        cout << lcs[k];
    }
    cout << endl;

    return table[m][n];
}

int main()
{
    string x, y;

    cout << "Enter string x: ";
    cin >> x;
    cout << "Enter string y: ";
    cin >> y;

    int lcsLength = LongestCommonSubsequenceBottomUp(x, y);
    cout << "Longest Common Subsequence Length: " << lcsLength << endl;

    return 0;
}
