#include <bits/stdc++.h>
using namespace std;

void dfs(vector<long long>& dis,vector<vector<pair<int,long long>>>& adj,int u, int fa ,long long d);
int main() 
{
    int n;
    cin >> n;
    //邻接表：每个节点对应一个vector，存储(pair<邻居节点, 边权>)
    vector<vector<pair<int,long long>>> adj(n+1);
    //k到其他每个节点的距离
    vector<long long> dis(n+1,LLONG_MAX);
    //读入n-1条边
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int q,k;
    cin >> q >> k;
    dfs(dis,adj,k,0,0);
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << dis[x]+dis[y] << endl;
    }
}
void dfs(vector<long long>& dis,vector<vector<pair<int,long long>>>& adj,int u, int fa ,long long d){
    dis[u] = d;
    for(auto &[v,w]:adj[u])
    {
        if(dis[v] == LLONG_MAX)
        {
            dfs(dis,adj,v,u,w+dis[u]);
        }
    }
}
