#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; //number of edges and vertices
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);           //for a directed graph omit this line
        cout<<"For iteration"<<(i+1)<<endl;
    }
    /*for weighted graphs
    vector<pair<int,int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v,wt;
        cin >> u >> v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});              //for a directed graph omit this line
    }
    */

    return 0;
}