#include <bits/stdc++.h>
//#define V 4 
  
using namespace std; 
  

// Driver program to test above function 
int main() 
{ 
    int V;
    cout<<"Enter the number of edges"<<endl;
    cin>>V;
    int G[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++){
            cin>>G[i][j];
        }
    }
    // Create a color array to store colors  
    // assigned to all veritces. Vertex  
    // number is used as index in this array.  
    // The value '-1' of colorArr[i]  
    // is used to indicate that no color  
    // is assigned to vertex 'i'. The value 1  
    // is used to indicate first color  
    // is assigned and value 0 indicates  
    // second color is assigned. 
    int colorArr[V]; 
    memset(colorArr, -1, sizeof colorArr);
    int src=0;
    // Assign first color to source 
    colorArr[src] = 1; 
  
    // Create a queue (FIFO) of vertex  
    // numbers and enqueue source vertex 
    // for BFS traversal 
    queue <int> q; 
    q.push(src); 
  
    // Run while there are vertices  
    // in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (G[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < V; ++v) 
        { 
            // An edge from u to v exists and  
            // destination v is not colored 
            if (G[u][v]==1 && colorArr[v] == -1) 
            { 
                // Assign alternate color to this adjacent v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination  
            // v is colored with same color as u 
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
            {
                cout<<"NOT A BIPARTITE GRAPH"<<endl;
                return 0; 
            }
        } 
    } 
  
    // If we reach here, then all adjacent   
    // vertices can be colored with alternate color 
    cout<<"A BIPARTITE GRAPH"<<endl;
    return 0;
 
} 