#include<bits/stdc++.h>
using namespace std;

struct Club
{
    string ClubName;
    int startTime;
    int duration;
};

bool comp(Club c1, Club c2)
{
    return (c1.startTime + c1.duration) < (c2.startTime + c2.duration);
}

int ChoosingClubs(vector<Club> c, int x)
{
    sort(c.begin(), c.end(), comp);

    cout<< "Chosen Clubs: " << endl;
    cout<< c[0].ClubName << endl;
    int FinishTime = c[0].startTime + c[0].duration;
    int clubs = 1;
    for(int i=0; i<c.size(); i++)
    {
        if((FinishTime + x) <= c[i+1].startTime)
        {
            cout<< c[i+1].ClubName <<endl;
            clubs++;
            FinishTime = c[i+1].startTime + c[i+1].duration;
        }

    }
    return clubs;
}

int main()
{
    int n;
    cout<<"Enter the total clubs: ";
    cin>>n;

    string name;
    int s, d;
    vector<Club> c0;
    for(int i=0; i<n; i++){
        cout<<"Enter the Club " << i+1 << " name: ";
        cin>>name;
        cout<<"Enter the Club " << i+1 << " start time: ";
        cin>>s;
        cout<<"Enter the Club " << i+1 << " duration: ";
        cin>>d;
        c0.push_back({name, s, d});
    }
        int x;
        cout<<"Enter the cleaning & prep time after each event: ";
        cin>>x;
        int result = ChoosingClubs(c0, x);
        cout<<"Total " << result << " Clubs can be chosen." <<endl;


    return 0;
}

