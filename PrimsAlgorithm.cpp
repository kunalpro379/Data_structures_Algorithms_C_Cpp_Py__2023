#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
     unordered_map<int, list <int>>Adj;
        for (int i=0;i<g.size();i++){
            int u=g[i].first.first;
            int v=g[i].first.second;
            int w=g[i].second;
            Adj[u].push_back(make_pair(u,v));
            Adj[v].push_back(make_pair(v,w));
        }
        vector<int>key(n+1);
        vector<bool>mst(n+1);
        vector<int>parent(n+1);
        for (int i=0;i<=n;i++) {
            key[i]=INT_MAX;
            parent[i]=-1;
            mst[i]=false;
        }
       // algo.......

        key[1]=0;
        parent[1]=-1;
        for (int i=0; i<n; i++) {
            int min=INT_MAx;
            int u;
            for (int v=1;v<=n;v++) {
              if (mst[v]==false&&key[v]<mini) {
                  u=v;
                  mini=key[v];

              }

            }

            mst[u]=true;
            for (auto  it: Adj[u]) {
                int v=it.first;
                int w=it.second;
                if (mst[]==false&&w<key[v]) {
                    parent[v]=u;
                    
                }
            }
        }
}
