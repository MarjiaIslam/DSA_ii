#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int reversee(int n, int revNum)
{
    if (n == 0)
    {
        return revNum;
    }
    else
    {
       revNum = revNum*10;
       revNum += n%10;

       return reversee(n/10, revNum);
    }
}
int PalinedromeChecker(int n)
{
    if(n==reversee(n,0)) printf("\nYES");
    else printf("\nNO");

}

int main()
{
    int n;
    cout << "Enter the number: \n";
    cin >> n;
    printf("The reverse number of %d is: %d", n, reversee(n,0));
    PalinedromeChecker(n);
    return 0;
}

