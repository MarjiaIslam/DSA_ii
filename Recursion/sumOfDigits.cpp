#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sumOfDIgits(int n)
{
    if(n==0) return 0;
    else
    {
        return sumOfDIgits(n/10)+(n%10);
    }
}


int main()
{
    int n;
    printf("Enter the number: \n");
    cin >> n;
    printf("The summation of all the digits of %d: %d",n, sumOfDIgits(n));


    return 0;
}
