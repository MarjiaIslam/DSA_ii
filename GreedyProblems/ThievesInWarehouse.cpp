#include <bits/stdc++.h>
using namespace std;

struct Box
{
    string ItemName;
    int weight, value;
};

bool comp(Box b1, Box b2)
{
    return b1.value * 1.0 / b1.weight > b2.value * 1.0 / b2.weight;
}

int ThievesInWareHouse(vector<Box> boxes, vector<int> cap)
{
    sort(boxes.begin(), boxes.end(), comp);
    int thieves = 0;
    double total_weight = 0;

    for (int i = 0; i < boxes.size(); i++)
    {
        total_weight += boxes[i].weight;
    }

    for (int i = 0; i < cap.size(); i++)
    {
        if (total_weight <= 0)
            break;

        double capacity_left = cap[i];
        double profit = 0;
        cout << "------Thief " << i + 1 << "------" << endl;

        for (int j = 0; j < boxes.size(); j++)
        {
            if (capacity_left <= 0)
                break;

            if (boxes[j].weight == 0)
                continue;

            int wi = boxes[j].weight, vi = boxes[j].value;
            double fraction = min(1.0, capacity_left / wi);
            double weight_taken = fraction * wi;
            double value_taken = fraction * vi;

            capacity_left -= weight_taken;
            total_weight -= weight_taken;
            profit += value_taken;

            cout << "Taking " << boxes[j].ItemName << ": " << weight_taken << " kg " << value_taken << " taka" << endl;

            if (fraction == 1.0)
            {
                boxes[j].weight = 0;
            }
            else
            {
                boxes[j].weight -= weight_taken;
                boxes[j].value = boxes[j].weight * (vi / wi);
                break;
            }
        }

        cout << "Thief " << i + 1 << " profit: " << profit << " taka" << endl;
        thieves++;
    }

    if (total_weight > 0)
    {
        cout << "Still following items are left" << endl;
        for (int i = 0; i < boxes.size(); i++)
        {
            if (boxes[i].weight > 0)
            {
                cout << boxes[i].ItemName << ":" << boxes[i].weight << " kg " << boxes[i].value << " taka" << endl;
            }
        }
    }

    return thieves;
}

int main()
{
    int n, w, v, k;
    string m;
    cout << "Enter the total number of boxes: ";
    cin >> n;
    vector<Box> boxes;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Item " << i + 1 << "'s name: ";
        cin >> m;
        cout << "Enter the Item " << i + 1 << "'s weight: ";
        cin >> w;
        cout << "Enter the Item " << i + 1 << "'s value: ";
        cin >> v;
        boxes.push_back({m, w, v});
    }
    cout << "Enter the number of thieves: ";
    cin >> k;
    vector<int> cap;
    int c;
    for (int i = 0; i < k; i++)
    {
        cout << "Enter the capacity of thief " << i + 1 << "'s knapsack: ";
        cin >> c;
        cap.push_back(c);
    }

    int thieves = ThievesInWareHouse(boxes, cap);
    cout << "Total " << thieves << " thieves stole from the warehouse." << endl;

    return 0;
}
