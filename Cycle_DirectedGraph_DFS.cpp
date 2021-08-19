#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkForCycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool isCycle(int N, vector<int> adj[])
{
    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            // cout << i << endl;
            if (checkForCycle(i, adj, vis, dfsVis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bool ans = isCycle(V, adj);
    cout << ans << "\n";
    return 0;
}