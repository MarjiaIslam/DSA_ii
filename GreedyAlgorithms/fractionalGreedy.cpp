#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compare(Item a, Item b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double FractionalKnapsack(int W, int v[], int w[], int n)
{
    Item items[n];

    for (int i = 0; i < n; ++i)
    {
        items[i].value = v[i];
        items[i].weight = w[i];
    }

    sort(items, items + n, compare);

    int cap_left = W;
    double profit = 0.0;
    int i = 0;

    while (cap_left > 0 && i < n)
    {
        if (cap_left >= items[i].weight)
        {
            profit += items[i].value;
            cap_left -= items[i].weight;
        }
        else
        {
            profit += items[i].value * ((double)cap_left / items[i].weight);
            cap_left = 0;
        }
        i++;
    }

    return profit;
}

int main()
{
    int n, W;
    cout<<"Enter the number of items: ";
    cin >> n;
    cout<<"Enter the total capacity: ";
    cin >> W;

    int v[n], w[n];
    cout<<"Enter the each item's values & weights respectively: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"value of item " << i+1 << "--> " ;
        cin >> v[i];
        cout<<"weight of item " << i+1 << "--> " ;
        cin >> w[i];
    }

    double result = FractionalKnapsack(W, v, w, n);
    cout <<"Total profit: " << result << endl;

    return 0;
}
