#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int id;
    int w,v;
};

bool comp(Item i1, Item i2)
{
    return i1.v*1.0 /i1.w >  i2.v*1.0 /i2.w ;
}

double fractional_Knapsack(vector<Item> items, int w)
{
    sort(items.begin(),items.end(),comp);
    double cap_left=w;
    double profit= 0;
    printf("------Items Taken------\n");
    for(int i=0; i<items.size(); i++)
    {
        if(cap_left<=0) break;
        int vi= items [i].v, wi= items[i].w;
        double fraction = min (1.0, cap_left/wi);
        cap_left-=fraction*wi;
        profit+= fraction *vi;
        printf("item %d: %.1f kg %.1f taka\n", items[i].id, fraction*wi, fraction*vi);
    }
    return profit;
}
int main()
{
    int n, w, v;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<Item> items;
    cout<<"Enter the each item's values & weights respectively: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"value of item " << i+1 << "--> " ;
        cin >> v;
        cout<<"weight of item " << i+1 << "--> " ;
        cin >> w;
        items.push_back({i+1, w, v});
    }
    cout<<"Enter the total capacity: ";
    cin>> w;
    double profit = fractional_Knapsack(items,w);
    cout<< "Profit: " << profit << "taka"<< endl;

    return 0;
}
