#include<bits/stdc++.h>
using namespace std;
void DFS(int s, bool visited[],list<int> adj[])
{
    visited[s] = true;
    cout << s << " ";

    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited,adj);
}

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
    cout<<"Enter start: ";
    cin>>s;
    DFS(s,V,adj);
    return 0;
}
