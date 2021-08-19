#include <bits/stdc++.h>
using namespace std;

vector<int> topoBFS(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    /*for(int i=0;i<indeg.size();i++)
    {
        cout<<indeg.at(i)<<" ";
    }*/
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        cout << node << endl;
        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> res = topoBFS(V, adj);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res.at(i) << " ";
    }
    cout << "\n";
    return 0;
}