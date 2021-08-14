#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;                           //number of edges and vertices
    cin>>n>>m;
    int adj[n+1][n+1];       
    memset(adj, 0, sizeof adj);          //adjacency matrix declaration
    //take input for edges
    for(int i=0;i<m;i++)
    {
        int u,v; 
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
