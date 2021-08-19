#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int v, vector<vector<int>> adj, vector<int> &visited)
{
    //create a queue for BFS
    queue<pair<int, int>> q;
    visited[s] = true;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<vector<int>> adj)
{
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, v, adj, vis))
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
    std::vector<std::vector<int>> adj(V+1);
    int u, v;
    cout<<adj.size();
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    bool ans = isCycle(V, adj);
    if (ans)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
    return 0;
}