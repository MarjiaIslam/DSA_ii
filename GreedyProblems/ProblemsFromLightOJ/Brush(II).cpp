#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

bool comp(const Point& a, const Point& b)
{
    return a.y < b.y;
}

int minMoves(vector<Point>& dusts, int w)
{
    sort(dusts.begin(), dusts.end(), comp);

    int moves = 0;
    int current_y = dusts[0].y - w + 1;

    for (int i = 0; i < dusts.size(); i++)
    {
        if (dusts[i].y > current_y + w - 1)
        {
            moves++;
            current_y = dusts[i].y - w + 1;
        }
    }

    return moves;
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int n, w;
        cout << "Enter the number of dust points and brush width for case " << tc << " :" ;
        cin >> n >> w;

        vector<Point> dusts(n);
        cout << "Enter the coordinates of the dust points (x y):" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> dusts[i].x >> dusts[i].y;
        }

        cout << "Case " << tc << ": " << minMoves(dusts, w) << endl;
    }

    return 0;
}
