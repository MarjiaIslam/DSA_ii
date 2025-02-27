#include<bits/stdc++.h>
using namespace std;

int nEdge;
int nVertex;
int p[100];

void makeSet()
{
    int i;
    for(i = 0; i < nVertex; i++)
    {
        p[i] = i;
    }
}

int findSet(int x)
{
    if(p[x] == x)
    {
        return x;
    }
    else
    {
        return findSet(p[x]);
    }
}

int UnionSet(int s1, int s2)
{
    int r1 = findSet(s1);
    int r2 = findSet(s2);

    p[r1] = r2;

}

int main()
{
    int i;
    nVertex = 10;
    nEdge = 7;

    makeSet();
    UnionSet(0, 1);
    UnionSet(0, 2);
    UnionSet(3, 4);
    UnionSet(6, 7);
    UnionSet(6, 8);
    UnionSet(7, 8);
    UnionSet(7, 9);

    cout << findSet(9) << endl;
    cout << findSet(8) << endl;
    cout << findSet(7) << endl;
    cout << findSet(6) << endl;

    cout << findSet(1) << endl;
    cout << findSet(2) << endl;
    cout << findSet(0) << endl;

    cout << findSet(5) << endl;

    cout << findSet(3) << endl;
    cout << findSet(4) << endl;
    return 0;
}
