#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    vector <int> list2 = {1,10,200};
    vector <int> list4;
    int x;

    for(int i=0; i<5; i++)
    {
        cin >> x;
        list4.push_back(x);
    }

    printf("size: %d\n", list4.size());

    for(int i =0; i<list4.size(); i++)
    {
        printf("[%d] %d\n", i, list4[i]);
    }

    int j=2;
    list4.erase(list4.begin() + j);

    for(int x : list4)
        printf("%d\n", x);

    return 0;
}
