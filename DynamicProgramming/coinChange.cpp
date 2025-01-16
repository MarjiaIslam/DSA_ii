#include<bits/stdc++.h>
using namespace std;

#define INFINITY_VALUE 999999

int calculateMinimumCoins(int targetAmount, vector<int> coinDenominations, int numberOfDenominations)
{
    int minimumCoins[targetAmount + 1];
    minimumCoins[0] = 0;

    for (int currentAmount = 1; currentAmount <= targetAmount; currentAmount++)
    {
        minimumCoins[currentAmount] = INFINITY_VALUE;

        for (int coinIndex = 0; coinIndex < numberOfDenominations; coinIndex++)
        {
            int currentCoin = coinDenominations[coinIndex];

            if (currentCoin <= currentAmount &&
                    minimumCoins[currentAmount - currentCoin] + 1 < minimumCoins[currentAmount])
            {
                minimumCoins[currentAmount] = minimumCoins[currentAmount - currentCoin] + 1;
            }
        }
    }

    cout << "Total number of coins needed: " << minimumCoins[targetAmount] << endl;
    cout << "Coins used: ";

    int remainingAmount = targetAmount;
    while (remainingAmount > 0)
    {
        for (int coinIndex = 0; coinIndex < numberOfDenominations; coinIndex++)
        {
            int currentCoin = coinDenominations[coinIndex];

            if (remainingAmount >= currentCoin &&
                    minimumCoins[remainingAmount - currentCoin] + 1 == minimumCoins[remainingAmount])
            {
                cout << currentCoin << " ";
                remainingAmount -= currentCoin;
                break;
            }
        }
    }
    cout << endl;

    return minimumCoins[targetAmount];
}

int main()
{
    int targetAmount, numberOfDenominations, coinValue;

    cout<<"Enter the target amount and how many types of coin is there: "<<endl;
    cin >> targetAmount >> numberOfDenominations;

    vector<int> coinDenominations;

    cout<<"Enter the coin values: "<<endl;
    for (int i = 0; i < numberOfDenominations; i++)
    {
        cin >> coinValue;
        coinDenominations.push_back(coinValue);
    }

    int totalCoins = calculateMinimumCoins(targetAmount, coinDenominations, numberOfDenominations);

    return 0;
}
