#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else
    {
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){

    int n;
    printf("Enter the number: \n");
    cin >> n;
    printf("%dth number is: %d", n, fibo(n));


return 0;
}
