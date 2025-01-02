#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    printf("Enter the number you want to find the factorial of: \n");
    cin >> n;
    printf("factorial of %d is: %d", n, fact(n));

    return 0;
}
