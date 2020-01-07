#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100];
vector<bool> visited(100, false);

void addEdge(int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}

void DFSUtil(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i].first] == false)
            DFSUtil(adj[u][i].first);
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
    addEdge(0, 1, 2);
    addEdge(0, 4, 2);
    addEdge(1, 2, 2);
    addEdge(1, 3, 2);
    addEdge(1, 4, 2);
    addEdge(2, 3, 2);
    addEdge(3, 4, 2);
    DFS(V);
    return 0;
}
