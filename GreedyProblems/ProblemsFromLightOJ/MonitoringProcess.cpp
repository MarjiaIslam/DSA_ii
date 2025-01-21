#include <bits/stdc++.h>
using namespace std;

struct Event
{
    int time;
    bool isStart;
};

bool compareEvents(Event a, Event b)
{
    if (a.time == b.time)
    {
        return a.isStart > b.isStart;
    }
    return a.time < b.time;
}

int findMinWrappers(vector<Event> events)
{
    int countWrappers = 0;
    int maxWrappers = 0;

    sort(events.begin(), events.end(), compareEvents);

    for (int i = 0; i < events.size(); ++i)
    {
        if (events[i].isStart)
        {
            countWrappers++;
            maxWrappers = max(maxWrappers, countWrappers);
        }
        else
        {
            countWrappers--;
        }
    }

    return maxWrappers;
}

int main()
{
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int n;
        cout << "Enter the number of processes for case " << t << ": ";
        cin >> n;

        vector<Event> events;
        for (int i = 0; i < n; ++i)
        {
            int si, fi;
            cout << "Enter start time and end time for process " << i + 1 << " of case " << t << ": ";
            cin >> si >> fi;
            events.push_back({si, true});
            events.push_back({fi, false});
        }

        int minWrappers = findMinWrappers(events);
        cout << "Case " << t << ": " << minWrappers << endl;
    }

    return 0;
}
