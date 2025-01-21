#include <bits/stdc++.h>
using namespace std;

int calculatePoints(vector<int> myTeam, vector<int> opponentTeam)
{
    int p = myTeam.size();
    int point = 0, i = 0, j = 0;

    sort(myTeam.begin(), myTeam.end());
    sort(opponentTeam.begin(), opponentTeam.end());

    while (i < p && j < p)
    {
        if (myTeam[i] > opponentTeam[j])
        {
            point += 2;
            i++;
            j++;
        }
        else if (myTeam[i] == opponentTeam[j])
        {
            point += 1;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return point;
}

int main()
{
    int c;
    cout << "Enter the number of test cases: ";
    cin >> c;

    for (int t = 1; t <= c; t++)
    {
        int p;
        cout << "Enter the number of players for this round: ";
        cin >> p;
        vector<int> myTeam(p);
        vector<int> opponentTeam(p);
        cout << "Enter your team members skills: ";
        for (int i = 0; i < p; i++)
        {
            cin >> myTeam[i];
        }
        cout << "Enter the opponent team members skills: ";
        for (int j = 0; j < p; j++)
        {
            cin >> opponentTeam[j];
        }
        int points = calculatePoints(myTeam, opponentTeam);
        cout << "Case " << t << " : " << points << endl;
    }

    return 0;
}
