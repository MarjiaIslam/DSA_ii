#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int combination(int n, int r)
{
    if(n < r) return 0;
    if(r == 0) return 1;
    if(r == 1) return n;
    if(n == 1) return 1;

    return combination(n-1,r) + combination(n-1,r-1);
}



int main()
{
    int n,r;
    printf("Enter the numbers: \n");
    cin >> n >> r;
    printf("%d", combination(n,r));
    return 0;
}

