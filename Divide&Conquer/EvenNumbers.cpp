#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countEven( int Arr[], int i, int j )
{
    if (i==j)
    {
        if ( Arr[i] % 2 == 0 ) return 1;
        else return 0;
    }
    else
    {
        int mid = (i+j)/2;
        int c1 = countEven(Arr, i, mid);
        int c2 = countEven(Arr, mid+1, j);
        return c1+c2;
    }
}

int main()
{
    int x;
    printf("Enter the array size: \n");
    cin>>x;

    int arr[x];
    cout<<"Enter the array elements:" <<endl;
    for(int i=0; i<x; i++)
    {
        cin>>arr[i];
    }
    int even = countEven(arr, 0, x-1);
    printf("There are %d even numbers in the array", even);

    return 0;
}

