#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sumAll( int Arr[], int i, int j )
{
    int sum = 0;
    if (i==j)
    {
         sum = sum + Arr[i];
         return sum;
    }
    else
    {
        int mid = (i+j)/2;
        int c1 = sumAll(Arr, i, mid);
        int c2 = sumAll(Arr, mid+1, j);
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
    int sum = sumAll(arr, 0, x-1);
    printf("The sum of all the numbers in the array: %d", sum);

    return 0;
}



