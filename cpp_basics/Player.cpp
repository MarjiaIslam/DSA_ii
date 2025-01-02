#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

struct player
{
    int m;
    int r;
};


bool comp(player p1, player p2)
{
    return (p1.r)/(p1.m) > (p2.r)/(p2.m);
}

int main()
{
    vector <player> p;
    int x,y,z;
    printf("Enter the number of total player: ");
    cin>>x;

    for(int i=0; i<x; i++)
    {
        printf("Enter the total match and the total run for the player %d: ", i+1);
        cin>>y;
        cin>>z;
        player p1;
        p1.m = y;
        p1.r = z;
        p.push_back(p1);

    }
    for(player a : p)
        printf("match: %d  run: %d\t", a.m, a.r);

    sort(p.begin(), p.end(), comp);
    printf("\nAfter Sorting: \n");

    for(player a : p)
        printf("match: %d  run: %d\t", a.m, a.r);

    return 0;
}
