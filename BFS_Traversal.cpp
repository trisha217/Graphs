#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;
        vector<int> vis(V + 1, 0);
        queue<int> q;
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return bfs;
    }
};

// { Driver Code Starts.
int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V + 1];
    int u, v;
    for (int i = 0; i < E; i++)
    {
        cout<<"Enter 1st vertex of edge"<<(i+1);
        cin >> u;
        cout<<"Enter 2nd vertex of edge"<<(i+1);
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // uncomment this for undirected graoh
    }
    // string s1;
    // cin>>s1;
    Solution obj;
    vector<int> ans = obj.bfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
} // } Driver Code Ends