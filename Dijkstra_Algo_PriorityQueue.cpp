#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
    int src;
    cin >> src;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int distance = pq.top().first;
        int prevNode = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (it = adj[prevNode].begin(); it != adj[prevNode].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (dist[next] > dist[prevNode] + nextDist)
            {
                dist[next] = dist[prevNode] + nextDist;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    cout << "The distances from the source are " << src << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << src << " "
             << "------- " << (i) << " "
             << "= " << dist[i]<<endl;
    }
    cout << endl;

    return 0;
}