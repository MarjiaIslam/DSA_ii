#include<bits/stdc++.h>
using namespace std;

int nEdge;
int nVertex;
int p[100], rankk[100];

void makeSet()
{
    int i;
    for(i=0; i<nVertex; i++)
    {
        p[i] = i;
        rankk[i] = 0;
    }
}

int findSet(int x)
{
    if(p[x]==x)
    {
        return (x);
    }
    else
    {
        return p[x] = findSet(p[x]);
        }
    }

    int UnionSet(int s1, int s2)
{
    int r1, r2;
    r1 = findSet(s1);
    r2 = findSet(s2);
    if(r1==r2)
    {
        return 0;
    }
    if(rankk[r1]>rankk[r2])
    {
        p[r2] = r1;
    }
    else
    {
        p[r1]=r2;
        if(rankk[r1] == rankk[r2])
            rankk[r2]++;
    }
    return 1;

}

int main(){
    vector <pair<int, pair<int,int> > > graph1;

    int i,u,v,w;
    cout<<"Enter Number of vertices :\n";
    cin>>nVertex;
    cout<<"Enter Number of edges :\n";
    cin>>nEdge;
    cout<<"Enter the graph :\n";

    for(i=0; i<nEdge; i++){
        cin>>u>>v>>w;
        graph1.push_back(make_pair(w, make_pair(u,v)));
    }


    sort(graph1.begin(), graph1.end());

    cout<<"Sorted graph according to the edges: \n";
    for(i=0; i<nEdge; i++){
        cout<<"<" <<graph1[i].second.first<<","<<graph1[i].second.second<<">--->"<<graph1[i].first<<'\n';
    }
    cout<<'\n';
    makeSet();

    cout<<"Minimum Spanning Tree: \n";
    for(i=0; i<nEdge; i++){
            u = graph1[i].second.first;
            v = graph1[i].second.second;
            if(UnionSet(u,v) != 0)
                cout<<"<"<<u<<","<<v<<">--->"<<graph1[i].first<<'\n';
    }

return 0;
}
