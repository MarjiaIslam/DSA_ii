#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int f[n];
    f[0]=0,f[1]=1;

    for(int i=2; i<=n; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The fibonacci of " << n << " is " << fib(n) <<endl;


    return 0;
}
