#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;

        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void BFS(int G[][8], int start, int n)
{
    int visited[8] = {0};
    cout << start << " ";
    visited[start] = 1;
    enqueue(start);
    while (!isEmpty())
    {
        int u = dequeue();
        for (int v = 1; v <= n; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

void DFS(int G[][8], int start, int n)
{
    static int visited[8] = {0};
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main()
{
    int G[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},  //0
                   {0, 0, 1, 0, 1, 0, 0, 0},  //1
                   {0, 1, 0, 1, 0, 0, 0, 0},  //2
                   {0, 0, 1, 0, 1, 1, 0, 0},  //3
                   {0, 1, 0, 1, 0, 1, 0, 0},  //4
                   {0, 0, 0, 1, 1, 0, 1, 1},  //5
                   {0, 0, 0, 0, 0, 1, 0, 0},  //6
                   {0, 0, 0, 0, 0, 1, 0, 0}}; //7
    cout << "BFS Traversal:";
    BFS(G, 1, 7);
    cout << endl;
    cout << "DFS Traversal:";
    DFS(G, 4, 8);
    cout << endl;
    return 0;
}