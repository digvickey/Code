#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define pii pair<int,int>
vector<pii> adj[MAX];
priority_queue<pii> pq;
bool mark_set[MAX];
int label[MAX];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        mark_set[i]=false;
        label[i]=1e8;
    }
    mark_set[s]=true;
    label[s]=0;
    pq.push(make_pair(-0,s));
    while(!pq.empty())
    {
        int v=pq.top().second;
        int label_v=-pq.top().first;
        pq.pop();
        //cout<<"v= "<<v<<" lab_v= "<<label_v<<endl;
        if(label_v > label[v])
            continue;
        for(int i=0;i<adj[v].size();i++)
        {
            int neigh=adj[v][i].first;
            int edge= adj[v][i].second;
            if(mark_set[neigh]==false)
            {
                if(label[neigh]>edge)
                {
                    label[neigh]=edge;
                    pq.push(make_pair(-label[neigh],neigh));
                }
            }
        }
        mark_set[v]=true;
    }
    int r=0;
    for(int i=1;i<=n;i++)
        r+=label[i];
    cout<<r<<endl;
}
