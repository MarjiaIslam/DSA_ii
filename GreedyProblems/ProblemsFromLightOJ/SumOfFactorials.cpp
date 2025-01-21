#include<bits/stdc++.h>
using namespace std;

vector<long long> computeFactorial()
{
    vector<long long> factorials(21, 1);
    for (int i = 1; i <= 20; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }
    return factorials;
}

void solveTestCase(int caseNumber, int n, vector<long long>& factorials)
{
    vector<int> results;
    for (int i = 20; i >= 0; i--)
    {
        if (factorials[i] <= n)
        {
            n -= factorials[i];
            results.push_back(i);
        }
    }
    cout << "Case " << caseNumber << ": ";
    if (n == 0)
    {
        for (int i = results.size() - 1; i > 0; i--)
        {
            cout << results[i] << "!+";
        }
        cout << results[0] << "!" << endl;
    }
    else
    {
        cout << "Impossible"<<endl;
    }
}

int main()
{
    int f;
    cout << "Enter how many numbers you want to check:";
    cin >> f;
    vector<long long> factorials = computeFactorial();

    cout<<"Enter the numbers: "<<endl;
    for (int i = 1; i <= f; i++)
    {
        int n;
        cin >> n;
        solveTestCase(i, n, factorials);
    }
    return 0;
}
