#include <bits/stdc++.h>
using namespace std;

int findMinCoins(int N, vector<int> coins)
{
    int numCoins = 0;
    sort(coins.begin(), coins.end(), greater<int>());

    for (int i=0; i < coins.size(); i++)
    {
        int coinCounts = 0;
        while (N >= coins[i])
        {
            N -= coins[i];
            coinCounts++;
            numCoins++;
        }
        if(coinCounts>0)
        {
            cout<< coins[i] << " cents --> " << coinCounts <<endl;
        }
    }

    return numCoins;
}

int main()
{
    int N;
    cout << "Enter the amount to make change for: ";
    cin >> N;

    int d;
    cout << "Enter how many types of coins are available: ";
    cin >> d;

    vector<int> coins;
    int x;
    cout << "Enter the coins amount: " <<endl;
    for (int i=0; i < d; ++i)
    {
        cin>>x;
        coins.push_back(x);
    }

    int TotalCoins = findMinCoins(N, coins);

    cout << "Total coins: " << TotalCoins << endl;

    return 0;
}
