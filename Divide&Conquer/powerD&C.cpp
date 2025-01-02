#include<bits/stdc++.h>
#include<iostream>
using namespace std;

long long power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        long long p = power(x,y/2);
        if(y%2 == 0) return p*p;
        else return p*p*x;
    }

}

int main()
{
    int x,y;
    cout << "Enter the numbers:" <<endl;
    cin >> x >> y;
    cout << "Result: " << power(x,y) <<endl;

    return 0;
}
