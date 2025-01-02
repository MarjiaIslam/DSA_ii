#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
return a>b;
}

int main()
{
    int arr[] = {100, 512, 6, 724, 31, 14, 2, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<len; i++)
    {
        printf("%d\n", arr[i]);
    }

    sort(arr+2, arr+len-2, comp);
    printf("After Sorting: \n");

    for(int i=0; i<len; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}
