#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sum(int n)
{
    if(n==1) return 1;
    else
    {
        return n+sum(n-1);
    }
}

int main()
{

    int n;
    printf("Enter the number: \n");
    cin >> n;
    printf("The summation of all the numbers upto %d: %d",n, sum(n));


    return 0;
}
