#include <bits/stdc++.h>
using namespace std;

void minStops(int D, int m, vector<int> stations)
{
    int tankLife = m;
    for(int i=0; i<stations.size(); i++){
        if(stations[i] > tankLife){
            cout<<"Stops at gas station " << i <<" (" << stations[i-1] << " miles.)"<<endl;
            tankLife += stations[i-1];
        }
    }
    if(tankLife < D){
        cout<<"Can't reach the destination." <<endl;
    }
    else{
        cout<<"Reached the destination." <<endl;
    }

}

int main()
{
    int D, m, n;
    cout << "Enter the Total distance, tank range, and number of stations: " << endl;
    cin >> D >> m >> n;

    vector<int> stations;
    int x;
    cout << "Enter the distances to the stations: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        stations.push_back(x);
    }

    minStops(D, m, stations);

    return 0;
}
