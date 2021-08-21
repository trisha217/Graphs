#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int n, int src)
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
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
        adj[v].push_back(u);
    }
    BFS(adj, V, 0);
    return 0;
}