#include<bits/stdc++.h>
using namespace std;

int f[100];

int fib(int x)
{
    if(x == 0 || x == 1)
    {
        return x;
    }

    if(f[x-1] == -1)
    {
        f[x-1] = fib(x-1);
    }

    if(f[x-2] == -1)
    {
        f[x-2] = fib(x-2);
    }

    return f[x-1] + f[x-2];
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;


    for(int i = 0; i < n; i++)
    {
        f[i] = -1;
    }

    cout << "Fibonacci of " << n << " is " << fib(n) << endl;

    return 0;
}

