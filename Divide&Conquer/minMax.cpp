#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Result
{
    int mAx;
    int mIn;
};

Result minMax(int arr[], int i, int j)
{
    if(i==j)
    {
        return {arr[i], arr[i]};
    }

    else
    {
        int mid = (i+j)/2;
        Result res1 = minMax(arr, i, mid);
        Result res2 = minMax(arr, mid+1, j);

        int mAx = max(res1.mAx, res2.mAx);
        int mIn = min(res1.mIn, res2.mIn);
        return{mAx, mIn};

    }
}

int main()
{
    int arr[100];
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    Result res = minMax(arr, 0, N-1);
    printf("max: %d\n", res.mAx);
    printf("min: %d\n", res.mIn);

    return 0;
}
