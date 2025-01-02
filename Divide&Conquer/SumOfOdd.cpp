#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sumOdd( int Arr[], int i, int j )
{
    int sum = 0;
    if (i==j)
    {
        if ( Arr[i] % 2 != 0 ) return Arr[i];
        else return 0;
    }
    else
    {
        int mid = (i+j)/2;
        int c1 = sumOdd(Arr, i, mid);
        int c2 = sumOdd(Arr, mid+1, j);
        return sum = sum+c1+c2;
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
    int odd = sumOdd(arr, 0, x-1);
    printf("The sum of the all odd numbers in the array: %d", odd);

    return 0;
}


