#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb(x) push_back(x)
#define MAX 10005
struct cmp
{
    bool operator() (const pii &a, const pii &b)
    {
        return a.second > b.second;
    }
};
priority_queue< pii, vector<pii>, cmp> Q;
vector<pii> G[MAX];
int D[MAX];
int K[MAX];
bool F[MAX];
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[k];
        for(int i=0;i<k;i++)
            cin>>a[i];
        int u,v,w;
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
            D[i]=1e7;
            F[i]=false;
        }
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            G[u].pb(make_pair(v,w));
            G[v].pb(make_pair(u,w));
        }
        int start=0;
        D[start]=0;
        Q.push(pii(start,0));
        while(!Q.empty())
        {
            u = Q.top().first;
            Q.pop();
            if(F[u])
                continue;
            int size = G[u].size();
            for(int i=0;i<size;i++)
            {
                v=G[u][i].first;
                w=G[u][i].second;
                if(!F[v] && D[u]+w < D[v])
                {
                    D[v] = D[u]+w;
                    Q.push(pii(v,D[v]));
                }
            }
            F[u]=true;
        }
        //
    }
}
