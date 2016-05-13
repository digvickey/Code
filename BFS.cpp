#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e,s;
    cout<<"Enter no of vertex and Edges: ";
    cin>>v>>e;
    bool V[v+1];
    for(int i=1;i<=v;i++)
        V[i]=false;
    list <int> adj[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    list <int> q;
    cout<<"Enter start: ";
    cin>>s;
    q.push_back(s);
    V[s]=true;
    while(!q.empty())
    {
        s=q.front();
        cout<<s<<" ";
        q.pop_front();
        for(list<int>::iterator it=adj[s].begin();it!=adj[s].end();it++)
        {
            if(V[*it]==false)
            {
                V[*it]=true;
                q.push_back(*it);
            }
        }
    }
    cout<<endl;
}
