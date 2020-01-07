#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
vector<bool> visited(100, false);

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i]);
}

void DFS(int V)
{
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u);
}

int main()
{
    int V = 5;
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
    DFS(V);
    return 0;
}
