#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int reversee(int n){
    if(n==0) return 0;
    else{
        printf("%d", n%10 );
        return reversee(n/10);
    }

}

int main()
{
    int n;
    printf("Enter the number: \n");
    cin >> n;
    reversee(n);
    return 0;
}
