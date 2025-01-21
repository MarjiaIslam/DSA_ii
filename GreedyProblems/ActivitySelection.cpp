#include<bits/stdc++.h>
using namespace std;

struct Task
{
    string ActivityName;
    int startTime;
    int finishTime;
};

bool comp(Task t1, Task t2)
{
    return t1.finishTime < t2.finishTime;
}

int ActivitySelection(vector<Task> t)
{
    sort(t.begin(), t.end(), comp);


    cout<< "Selected Task: " << endl;
    cout<< t[0].ActivityName << endl;
    int activities = 1;
    for(int i=0; i<t.size(); i++)
    {
        if(t[i].finishTime <= t[i+1].startTime)
        {
            cout<< t[i+1].ActivityName <<endl;
            activities++;
        }

    }
    return activities;
}

int main()
{
    int n;
    cout<<"Enter the total activities: ";
    cin>>n;

    string task;
    int s, f;
    vector<Task> t0;
    for(int i=0; i<n; i++){
        cout<<"Enter the task " << i+1 << " name: ";
        cin>>task;
        cout<<"Enter the task " << i+1 << " start time: ";
        cin>>s;
        cout<<"Enter the task " << i+1 << " finish time: ";
        cin>>f;
        t0.push_back({task, s, f});
    }
        int result = ActivitySelection(t0);
        cout<<"Total " << result << " tasks can be done." <<endl;


    return 0;
}
