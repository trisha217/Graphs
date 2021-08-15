#include <bits/stdc++.h>
using namespace std;

int v;
list<int> *adj;

bool checkForCycle(int node, int parent, vector<int> &vis)
{
    vis[node] = 1;
    list<int>::iterator i;
    for (i = adj[node].begin(); i != adj[node].end(); ++i)
    {
        if (!vis[*i])
        {
            if (checkForCycle(*i, node, vis))
                return true;
        }
        else if (*i != parent)
        {
            return true;
        }
    }
    return false;
}
/*
void addEdge(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}*/

bool isCycle()
{
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, -1, vis))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v=3, e=2;
    //cin >> v >> e;
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        //addEdge(x, y);
    }
    bool ans = isCycle();
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