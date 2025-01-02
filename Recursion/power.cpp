#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int power(int x, int y){
    if (x==0) return 0;
    if (y==0) return 1;

    else{
        return x*(pow(x,y-1));
    }
}


int main(){

    int x,y;
    printf("Enter the numbers: \n");
    cin >> x>> y;
    printf("%d", power(x,y));


return 0;
}

